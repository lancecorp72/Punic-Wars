#include "Ships.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>

Ships::Ships(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    // set graphics
    setPixmap(QPixmap(":/Resources/images/boat.png"));
    setPos(700,5);
    // set points
    //points << QPointF(700,50) << QPointF(800,50);
    points << QPointF(870,5) << QPointF(870,100)<< QPointF(1000,100) << QPointF(1000,5) << QPointF(1130,5) << QPointF(1130,250);
    dest_index = 0;
    dest = points[0];
    rotateTopoint(dest);

    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(100);

}

void Ships::rotateTopoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}

void Ships::move_forward(){
    // if close to dest, rotate to next dest

    QLineF ln(pos(),dest);
    if (ln.length() < 10){
        dest_index++;
        if(dest_index >= points.size())
            return;
        dest = points[dest_index];
        rotateTopoint(dest);
    }
    // move enemy forward at current angle
    int STEP_SIZE = 5;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

     setPos(x()+dx, y()+dy);

}
