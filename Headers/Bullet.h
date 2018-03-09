#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Tower.h"

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(int d=4,QGraphicsItem * parent=0);
    void delBullet();
    bool active;
public slots:
    void move();
private:
    double maxRange;
    double distanceTravelled;
    int damage;
};
#endif
