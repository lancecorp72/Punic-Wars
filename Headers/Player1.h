#ifndef PLAYER1_H
#define PLAYER1_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Tower.h"
#include <QMediaPlayer>
#include "ShipMove.h"
#include "TowerShoot.h"


class Player1: public QGraphicsPixmapItem {
public:
    Player1(QGraphicsEllipseItem * c,QGraphicsEllipseItem *c2, QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    QMediaPlayer *deny;

private:
    bool select1,select2;
    Tower * t;
    Tower * t1;
    QGraphicsEllipseItem * cur;
    QGraphicsEllipseItem * cur1;
    ShipMove * th;
    TowerShoot * ts;
};
#endif // PLAYER1_H
