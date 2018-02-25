#include "Player1.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Tower.h"
#include <QDebug>

Player1::Player1(QGraphicsItem * parent): QGraphicsPixmapItem(parent){
    select=false;
    t=nullptr;
    qInfo()<<"start";
}

void Player1::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Enter){
        if(select == true){
            select=false;
        }
        else{
            qInfo()<<"enter";
            select=true;
            t=new Tower();
            t->setPos(0,0);
            scene()->addItem(t);
        }
    }
    else if(event->key() == Qt::Key_Right && select == true) {
        if(t->x()<750)
            t->setPos(t->x()+50,t->y());
    }
    else if(event->key() == Qt::Key_Down && select == true) {
        if(t->y()<550)
            t->setPos(t->x(),t->y()+50);
    }
    else if(event->key() == Qt::Key_Left && select == true) {
        if(t->x()>0)
            t->setPos(t->x()-50,t->y());
    }
    else if(event->key() == Qt::Key_Up && select == true) {
        if(t->y()>0)
            t->setPos(t->x(),t->y()-50);
    }
}

