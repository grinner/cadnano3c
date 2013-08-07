#include "customqgraphicsview.h"

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
    scale_size = 1.0;
    scale_fit_factor = 1;
    show_details = true;
    scene_root_item = 0;
    has_focus = false;
    transform_enable = false;
};

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
