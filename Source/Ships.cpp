#include "Ships.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>

Ships::Ships(int player_code , QGraphicsItem *parent): QGraphicsPixmapItem(parent) {

    // set graphics
    if(player_code == 1)
        setPixmap(QPixmap(":/Resources/images/boat1.png"));
    else if(player_code == 2)
        setPixmap(QPixmap(":/Resources/images/boat2.png"));

    //Set position and origin
    setPos(730,40);
    setTransformOriginPoint(23,25);

    // set points
    if(player_code == 1)
    {
       points << QPointF(925,40)                           //Horizontal Segment 1
              << QPointF(925,140) << QPointF(1035,140)     //Segment 2
              << QPointF(1035,40) << QPointF(1165,40)      //Segment 3
              << QPointF(1165,250) << QPointF(1040,250)    //Segment 4
              << QPointF(1040,445) << QPointF(1165,445)    //Segment 5
              << QPointF(1165,355) << QPointF(1290,355)    //Segment 6
              << QPointF(1290,445) << QPointF(1500,445);   //Segment 7
    }
    else if(player_code == 2)
    {
        points << QPointF(525,40)                           //Horizontal Segment 1
               << QPointF(525,140) << QPointF(415,140)     //Segment 2
               << QPointF(415,40) << QPointF(285,40)      //Segment 3
               << QPointF(285,250) << QPointF(410,250)    //Segment 4
               << QPointF(410,445) << QPointF(285,445)    //Segment 5
               << QPointF(285,355) << QPointF(160,355)    //Segment 6
               << QPointF(160,445) << QPointF(-30,445);   //Segment 7
    }
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

    int STEP_SIZE = 3;

    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

     setPos(x()+dx, y()+dy);

}
