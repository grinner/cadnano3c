#ifndef CUSTOMQGRAPHICSVIEW_H
#define CUSTOMQGRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QPainter>
#include <QRectF>
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QWheelEvent>
#include <QGraphicsRectItem>
#include <QTransform>

class CustomQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CustomQGraphicsView(QWidget *parent = 0);

protected:
//    void focusInEvent(QFocusEvent *event);

//    void focusOutEvent(QFocusEvent *event);

    void keyPressEvent(QKeyEvent *event);

//    void keyReleaseEvent(QKeyEvent *event);

//    void enterEvent(QEvent * event);

//    void leaveEvent(QEvent *);

//    void mouseMoveEvent(QMouseEvent *event);

//    void mousePressEvent(QMouseEvent *event);

//    void mouseReleaseEvent(QMouseEvent *event);

//    void wheelEvent(QWheelEvent *event);

//    void paintEvent(QPaintEvent *event);

private:
    // constant floats to be initialize below by C++ standard
    static const double scale_limit_max;
    static const double scale_limit_min;
    static const double scale_up_rate;
    static const double scale_down_rate;
    // Keyboard panning
    static const double key_pan_delta_x;
    static const double key_pan_delta_y;

    qreal x0;
    qreal y0;
    double scale_size;
    double scale_fit_factor;  // sets initial zoom level
    qreal last_scale_factor;

    bool show_details;
    bool has_focus;
    bool transform_enable;

    QGraphicsRectItem *scene_root_item;  // the item to transform

    // Modifier keys and buttons
    static const int key_mod = Qt::Key_Control;
    static const int button_pan = Qt::LeftButton;
    static const int button_pan_alt = Qt::MidButton;
    static const int button_zoom = Qt::RightButton;

    //methods
    void addToPressList(QObject *item);

    qint32 keyPanDeltaX();

    qint32 keyPanDeltaY();

    void safeScale(qreal delta);

    void zoomIn(qreal fractionofmax);

    void zoomOut(qreal fractionofmin);

    void dollyZoom(QMouseEvent *event);

    void resetScale();

    void zoomToFit();

    void panEnable();

    void panDisable();

    void setViewportUpdateOn(bool isEnabled);

    void activateSelection(bool isActive);

    void clearGraphicsView();

    void clearSelectionLockAndCallbacks();

    void setGLView();

    void resetGL();

    bool shouldShowDetails();

    void allowGLSwitch();

    void drawBackgroundGL(QPainter* painter, QRectF &rect);

    //    void setSelectionLock(selectionLock);

    void setScaleFitFactor(qreal value);

    //    void setKeyPan(button);

signals:
    
public slots:
    
};

#endif // CUSTOMQGRAPHICSVIEW_H
