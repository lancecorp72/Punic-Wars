#include "Bullet.h"
#include <QPixmap>
#include <qmath.h>
#include "Game.h"
#include "Ships.h"
#include <typeinfo>
#include "Resource.h"

int STEP_SIZE = 5;

Bullet::Bullet(int d,QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent) {
    // set graphics
    setPixmap(QPixmap(":Resources/images/bullet.png"));
    //Initialization
    damage=d;

    // initialize values
    maxRange = 100;
    distanceTravelled = 0;
    active=true;
}

void Bullet::delBullet() {  //delete bullet from memory
    delete this;
}

void Bullet::move() {
    //check if bullet crossed range
    if(distanceTravelled>maxRange) {
       scene()->removeItem(this);
        active=false;
        return;
    }
    distanceTravelled+=STEP_SIZE;

    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is a Ship, destroy the bullet and reduce health of ship
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Ships)) { 

                // remove them from the scene (still on the heap)
                Ships *s =(Ships *)colliding_items[i];
                s->decreasehealth(damage);
                scene()->removeItem(this);          //remove bullet from scene
                active=false;                       //bullet to be deleted in BulletThrd

                // return (all code below refers to a non existant bullet)
                return;
            }
    }

    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}
