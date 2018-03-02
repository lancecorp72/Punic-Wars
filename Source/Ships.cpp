#include "Ships.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include <QBrush>
#include <QGraphicsScene>
#include "Resource.h"
extern Resource *player1_resources;
extern Resource *player2_resources;
Ships::Ships(int player_code ,QGraphicsScene * scene,QGraphicsItem *parent,int health): QGraphicsPixmapItem(parent) {




    //Initialization
    h=health;
    max_h= health;
    s=scene;
    pcode=player_code;
    distance=0;
    // set graphics
    if(player_code == 1)
        setPixmap(QPixmap(":/Resources/images/boat1.png"));
    else if(player_code == 2)
        setPixmap(QPixmap(":/Resources/images/boat2.png"));


         s->addItem(this);


     //add healthbar
     if(player_code==1)
     healthbar = new QGraphicsRectItem(5,5,25,5);
     else
     healthbar = new QGraphicsRectItem(15,40,25,5);
     healthbar->setPos(730,40);
     healthbar->setBrush(QBrush(Qt::red,Qt::SolidPattern));

     healthbar->show();
     healthbar->setTransformOriginPoint(23,25);
     s->addItem(healthbar);
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
void Ships::decreasehealth(int damage)
{

 h=h-damage;
 if(h>0)        //If possible , reduce health
 healthbar->setRect(5+(pcode-1)*10,5+(pcode-1)*35,h*25/max_h,5);  //hates another if
 else           // else destroy ship
 {
     s->removeItem(this);
     s->removeItem(healthbar);
     delete this;
     if(pcode==1)
     player1_resources->incT(distance/50);
     else
     player2_resources->incT(distance/50);
 }
}
void Ships::rotateTopoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
    healthbar->setRotation(-1 * ln.angle());
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
    distance++;
    int STEP_SIZE = 3;

    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

     setPos(x()+dx, y()+dy);
      healthbar->setPos(x()+dx,y()+dy);

}
