#ifndef CUSTOMQGRAPHICSVIEW_H
#define CUSTOMQGRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QPainter>
#include <QRectF>
#include <QEvent>

class CustomQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CustomQGraphicsView(QWidget *parent = 0);

    Qt::Alignment alignment() const;
    void setAlignment(Qt::Alignment alignment);
    
    void setViewportUpdateOn(bool isEnabled);

    void activateSelection(bool isActive);

    void clearGraphicsView();

    void clearSelectionLockAndCallbacks();

    void setGLView();

    void resetGL();

    bool shouldShowDetails();

    void allowGLSwitch();

    void drawBackgroundGL(QPainter painter, QRectF rect);

    void focusInEvent(QFocusEvent *event);

    void focusOutEvent(QFocusEvent *event);

    void setSelectionLock(selectionLock);

    void setScaleFitFactor(qreal value);

    void setKeyPan(button);

    void addToPressList(QObject *item);

    qint32 keyPanDeltaX();

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);

    void enterEvent(QEvent * event);

    void leaveEvent(QEvent *);

    void mouseMoveEvent(QMouseEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void panEnable();

    void panDisable();

    void wheelEvent(QWheelEvent *event);

    void safeScale(qreal delta);

    void zoomIn(qreal fractionofmax);

    void zoomOut(qreal fractionofmin);

    void dollyZoom(QMouseEvent *event);

    void resetScale();

    void zoomToFit();

    void paintEvent(QPaintEvent *event);

signals:
    
public slots:
    
};

#endif // CUSTOMQGRAPHICSVIEW_H
