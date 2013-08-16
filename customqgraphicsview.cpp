#include "customqgraphicsview.h"
#include "styles.h"

// Constant Non-integer Declarations
// float type must not be initialized in the class declaration, but also NOT in
// the header file.  Gotta be in the cpp. Per C++ standard
const double CustomQGraphicsView::scale_limit_max = 3.0;
const double CustomQGraphicsView::scale_limit_min = 0.41;
const double CustomQGraphicsView::scale_up_rate = 0.01;
const double CustomQGraphicsView::scale_down_rate = 0.01;
// Keyboard panning
const double CustomQGraphicsView::key_pan_delta_x = PATH_BASE_WIDTH * 21;
const double CustomQGraphicsView::key_pan_delta_y = PATH_HELIX_HEIGHT + PATH_HELIX_PADDING/2;

/* CONSTRUCTOR */
CustomQGraphicsView::CustomQGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    // set initial values of variable stuff
    x0 = 0.0;
    y0 = 0.0;
    scale_size = 1.0;
    scale_fit_factor = 1;
    last_scale_factor = 0.0;
    show_details = true;
    scene_root_item = 0;
    has_focus = false;
    transform_enable = false;
    dolly_zoom_enable = false;

    //toolbar = 0;  // custom hack for the paint tool palette
    name = "";
};

void CustomQGraphicsView::focusInEvent(QFocusEvent *event){
   has_focus = true;
};

void CustomQGraphicsView::focusOutEvent(QFocusEvent *event){
    transform_enable = false;
    dolly_zoom_enable = false;
    has_focus = false;
};

void CustomQGraphicsView::keyPressEvent(QKeyEvent *event) {
    /*
    Handle key presses for mouse-drag transforms and arrow-key panning.
    */
    if (!has_focus) { // we don't have focus -> ignore keypress
        return;
    }  
    switch(event->key()) {
        case key_mod:
            transform_enable = true;
            QGraphicsView::keyPressEvent(event);
            break;
        case Qt::Key_Left:
            // scene_root_item->moveBy(keyPanDeltaX(), 0);
            scene_root_item->setTransform(QTransform::fromTranslate(keyPanDeltaX(), 0), true);
            break;
        case Qt::Key_Up:
            // scene_root_item->moveBy(0, keyPanDeltaY());
            scene_root_item->setTransform(QTransform::fromTranslate(0, keyPanDeltaY()), true);
            break;
        case Qt::Key_Right:
            // scene_root_item->moveBy(-keyPanDeltaX(), 0);
            scene_root_item->setTransform(QTransform::fromTranslate(-keyPanDeltaX(), 0), true);
            break;
        case Qt::Key_Down:
            // scene_root_item->moveBy(0, -keyPanDeltaY());
            scene_root_item->setTransform(QTransform::fromTranslate(0, -keyPanDeltaY()), true);
            break;
        case Qt::Key_Plus:
            zoomIn(0.3);
            break;
        case Qt::Key_Minus:
            zoomIn(0.03); /* Should this be zoomOut? */
            break;
        default:
            return QGraphicsView::keyPressEvent(event);
    }
};

void CustomQGraphicsView::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == key_mod) {
        transform_enable = false;
        dolly_zoom_enable = false;
        panDisable();
    } else {
        QGraphicsView::keyReleaseEvent(event);
    }
};

void CustomQGraphicsView::enterEvent(QEvent *event) {
    setFocus();
    setDragMode(no_drag);
    QGraphicsView::enterEvent(event);
};

void CustomQGraphicsView::leaveEvent(QEvent *event) {
    clearFocus();
    QGraphicsView::leaveEvent(event);
};

void CustomQGraphicsView::mouseMoveEvent(QMouseEvent *event) {
    /*  Must reimplement mouseMoveEvent of QGraphicsView to allow
        ScrollHandDrag due to the fact that events are intercepted
        breaks this feature.
    */
    if (transform_enable == true) {
        if (dragMode() == yes_drag) {
            // Add stuff to handle the pan event
            qreal xf = event->localPos().x();
            qreal yf = event->localPos().y();
            qreal factor = transform().m11();
                        scene_root_item->setTransform(QTransform::fromTranslate((xf - x0)/factor,\
                                                                                (yf - y0)/factor), true);
//            scene_root_item->translate((xf - x0)/factor,\
//                                         (yf - y0)/factor);
            x0 = xf;
            y0 = yf;
        } else if (dolly_zoom_enable == true) {
            dollyZoom(event);
        }
    }
    // adding this allows events to be passed to items underneath
    QGraphicsView::mouseMoveEvent(event);
};

void CustomQGraphicsView::dollyZoom(QMouseEvent *event){
    /* docstring for dollyZoom */
    // QMouseEvent.y() returns the position of the mouse cursor relative
    // to the widget
    qreal yf = event->y();
    int denom = (int) abs(yf - y0);
    if (denom > 0) {
        qreal scale_factor = (height() / 2) % denom;
        if (last_scale_factor != scale_factor) {
            last_scale_factor = scale_factor;
            // zoom in if mouse y position is getting bigger
            if (yf - y0 > 0) {
                safeScale(yf - y0);
            } else  { // id smaller zoom out
                safeScale(yf - y0);
            }
        }
    }
};

void CustomQGraphicsView::safeScale(qreal delta) {
    qreal current_scale_level = transform().m11();
//    scale_factor = 1 + delta * \
//       ( (delta < 0) ? scale_down_rate : scale_up_rate) * \
//       (app().prefs.zoomSpeed/100.)

    qreal scale_factor = 1 + delta * \
       ( (delta < 0) ? scale_down_rate : scale_up_rate) * \
       (PREF_ZOOM_SPEED/100.);
     qreal new_scale_level = current_scale_level * scale_factor;
//    new_scale_level = util.clamp(current_scale_level * scale_factor,\
//                          scale_limit_min,\
//                          scale_limit_max);
    qreal scale_change = new_scale_level / current_scale_level;
    scale(scale_change, scale_change);

    resetGL();
};

void CustomQGraphicsView::resetGL() {
    qreal scale_factor = transform().m11();
    // print "scaleFactor", scaleFactor
//    scene_root_item->window()->statusBar()->showMessage("%f" % scale_factor);

    if (scale_factor < 0.15) { //and isGLSwitchAllowed:
        // isGLSwitchAllowed = false
        setGLView(true);
        show_details = false;
        emit levelOfDetailChangedSignal(false); // zoomed out
        qTimer->singleShot(500, this, SLOT(allowGLSwitch()));
    } else if (scale_factor > .2) { // and self.isGLSwitchAllowed:
        // isGLSwitchAllowed = false
        setGLView(false);
        show_details = true;
        emit levelOfDetailChangedSignal(true); // zoomed in
        qTimer->singleShot(500, this, SLOT(allowGLSwitch()));
    }
};

void CustomQGraphicsView::allowGLSwitch(){
    is_GL_switch_allowed = true;
}

void CustomQGraphicsView::setGLView(bool boolval) {
    if ((boolval == true) && (is_GL == false)) {
        is_GL = true;
    } else if ((boolval == false) && (is_GL == true)) {
        is_GL = false;
    }
};

void CustomQGraphicsView::setupGL() {
    is_GL = true;
    is_GL_switch_allowed = true;
    qTimer = new QTimer();
}

void CustomQGraphicsView::panDisable() {
    /*Disable ScrollHandDrag Mode in QGraphicsView (displays a hand
    pointer)*/
    setDragMode(no_drag);
}

qint32 CustomQGraphicsView::keyPanDeltaX(){
    // TODO finish
    return 1;
};

qint32 CustomQGraphicsView::keyPanDeltaY() {
    // TODO finish
    return 2;
};

void CustomQGraphicsView::zoomIn(qreal fractionofmax){
    return;
};
