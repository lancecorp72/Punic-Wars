#include "Bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "Game.h"
#include "Ships.h"
#include <typeinfo>
#include "Resource.h"

extern Game * game;
extern Resource *player1_resources;
extern Resource *player2_resources;
int STEP_SIZE = 5;

Bullet::Bullet(int d,QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent) {
    // set graphics
    setPixmap(QPixmap(":Resources/images/bullet.png"));
    //Initialization
    damage=d;
    // connect a timer to move()
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(10);

    // initialize values
    maxRange = 100;
    distanceTravelled = 0;
}

void Bullet::move() {
    //check if bullet crossed range
    if(distanceTravelled>maxRange) {
       scene()->removeItem(this);
       delete this;
    }
    distanceTravelled+=STEP_SIZE;

    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Ships)) { 

                // remove them from the scene (still on the heap)
                               Ships *s =(Ships *)colliding_items[i];

                               s->decreasehealth(damage);

                               scene()->removeItem(this);

                               // delete them from the heap to save memory

                               delete this;

                // return (all code below refers to a non existant bullet)
                return;
            }
    }

    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}
