#include "Player1.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Tower.h"
#include "Bullet.h"
#include <QDebug>

Player1::Player1(QGraphicsEllipseItem * c,QGraphicsEllipseItem *c2 ,QGraphicsItem * parent): QGraphicsPixmapItem(parent){
    select1=false;
    select2=false;
    t= NULL;
    t1= NULL;
    cur=c;
    cur1=c2;
    cur1->setPos(1450,0);
   }

void Player1::keyPressEvent(QKeyEvent *event) {
    if(select1 == true) {        //tower is selected
        if(event->key() == Qt::Key_Return) {
            t->setNoFire();
            select1=false;

        }
        else if(event->key() == Qt::Key_Right) {
            if(t->x()<700&&cur->x()<700)
            {t->setPos(t->x()+50,t->y());
                cur->setPos(cur->x()+50,cur->y());}

        }
        else if(event->key() == Qt::Key_Down) {
            if(t->y()<500&&cur->y()<500)
            {t->setPos(t->x(),t->y()+50);
                cur->setPos(cur->x(),cur->y()+50);}
        }
        else if(event->key() == Qt::Key_Left) {
            if(t->x()>0&&cur->x()>0)
            {t->setPos(t->x()-50,t->y());
               cur->setPos(cur->x()-50,cur->y());}
        }
        else if(event->key() == Qt::Key_Up) {
            if(t->y()>0&&cur->y()>0)
            {t->setPos(t->x(),t->y()-50);
                cur->setPos(cur->x(),cur->y()-50);}
        }
    }
    else {                      //no towers are selected
        if(event->key() == Qt::Key_Return && cur->x()<=100 && cur->y()<=40) {
            select1=true;
            t=new Tower();
            t->setPos(cur->x(),cur->y());
            scene()->addItem(t);
        }
        else if(event->key() == Qt::Key_Right) {
            if(cur->x()<700)
                cur->setPos(cur->x()+50,cur->y());


        }
        else if(event->key() == Qt::Key_Down) {
            if(cur->y()<500)
                cur->setPos(cur->x(),cur->y()+50);
        }
        else if(event->key() == Qt::Key_Left) {
            if(cur->x()>0)
               cur->setPos(cur->x()-50,cur->y());
        }
        else if(event->key() == Qt::Key_Up) {
            if(cur->y()>0)
                cur->setPos(cur->x(),cur->y()-50);
        }

        }
    if(select2 == true) {        //tower is selected
        if(event->key() == Qt::Key_F) {
            t1->setNoFire();
            select2=false;

        }
        else if(event->key() == Qt::Key_D) {
            if(t1->x()<1450&&cur1->x()<1450)
            {t1->setPos(t1->x()+50,t1->y());
                cur->setPos(cur1->x()+50,cur1->y());}

        }
        else if(event->key() == Qt::Key_S) {
            if(t1->y()<500&&cur1->y()<500)
            {t1->setPos(t1->x(),t1->y()+50);
                cur1->setPos(cur1->x(),cur1->y()+50);}
        }
        else if(event->key() == Qt::Key_A) {
            if(t1->x()>800&&cur1->x()>800)
            {t1->setPos(t1->x()-50,t1->y());
               cur1->setPos(cur1->x()-50,cur1->y());}
        }
        else if(event->key() == Qt::Key_W) {
            if(t1->y()>0&&cur1->y()>0)
            {t1->setPos(t1->x(),t1->y()-50);
                cur1->setPos(cur1->x(),cur1->y()-50);}
        }
    }
    else {                      //no towers are selected
        if(event->key() == Qt::Key_F && cur1->x()>=1350 && cur1->y()<=40) {
            select2=true;
            t1=new Tower();
            t1->setPos(cur1->x(),cur1->y());
            scene()->addItem(t1);
        }
        else if(event->key() == Qt::Key_D) {
            if(cur1->x()<1450)
                cur1->setPos(cur1->x()+50,cur1->y());


        }
        else if(event->key() == Qt::Key_S) {
            if(cur1->y()<500)
                cur1->setPos(cur1->x(),cur1->y()+50);
        }
        else if(event->key() == Qt::Key_A) {
            if(cur1->x()>800)
               cur1->setPos(cur1->x()-50,cur1->y());

        }
        else if(event->key() == Qt::Key_W) {
            if(cur1->y()>0)
                cur1->setPos(cur1->x(),cur1->y()-50);
        }

        }
    }

