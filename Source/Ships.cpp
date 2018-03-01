#include "Ships.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>

Ships::Ships(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {

    // set graphics
    setPixmap(QPixmap(":/Resources/images/boat.png"));

    //Set position and origin
    setPos(550,40);
    setTransformOriginPoint(23,25);

    // set points
    points << QPointF(925,40)                           //Horizontal Segment 1
           << QPointF(925,140) << QPointF(1035,140)     //Segment 2
           << QPointF(1035,40) << QPointF(1165,40)      //Segment 3
           << QPointF(1165,250) << QPointF(1040,250)    //Segment 4
           << QPointF(1040,445) << QPointF(1165,445)    //Segment 5
           << QPointF(1165,355) << QPointF(1290,355)    //Segment 6
           << QPointF(1290,445) << QPointF(1500,445);   //Segment 7

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
