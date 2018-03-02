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

Bullet::Bullet(QGraphicsItem *parent,int d): QObject(),QGraphicsPixmapItem(parent) {
    // set graphics
    setPixmap(QPixmap(":Resources/images/bullet.png"));
    //Initialization
    damage=d;
    // connect a timer to move()
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);

    // initialize values
    maxRange = 100;
    distanceTravelled = 0;
}

void Bullet::move() {

    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Ships)) {
                //when ship is destroyed, resource is increased for attacking player
                if(colliding_items[i]->x()<750) {
                    player1_resources->incS();
                }
                else {
                    player2_resources->incS();
                }

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

    int STEP_SIZE = 30;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}

double Bullet::getMaxRange() {
    return maxRange;
}

double Bullet::getDistanceTravelled() {
    return distanceTravelled;
}

void Bullet::setMaxRange(double rng) {
maxRange = rng;
}

void Bullet::setDistanceTravelled(double dist) {
    distanceTravelled = dist;
}
