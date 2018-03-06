#ifndef PLAYER1_H
#define PLAYER1_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Tower.h"
#include <QMediaPlayer>


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
};
#endif // PLAYER1_H
