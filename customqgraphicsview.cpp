#include "customqgraphicsview.h"

CustomQGraphicsView::CustomQGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
}

CustomQGraphicsView::keyPressEvent(QKeyEvent *event) {
    /*
    Handle key presses for mouse-drag transforms and arrow-key panning.
    */
    if (!hasFocus) { // we don't have focus -> ignore keypress
        return;
    }  
    switch(event->key()) {
        case key_mod:
            transform_enable = true;
            QGraphicsView::keyPressEvent(event);
            break;
        case Qt::Key_Left:
            scene_root_item->translate(keyPanDeltaX(), 0);
            break;
        case Qt::Key_Up:
            scene_root_item->translate(0, keyPanDeltaY());
            break;
        case Qt::Key_Right:
            scene_root_item->translate(-keyPanDeltaX(), 0);
            break;
        case Qt::Key_Down:
            scene_root_item->translate(0, -keyPanDeltaY());
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