#ifndef PLAYER1_H
#define PLAYER1_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Tower.h"
#include "Thrd.h"


class Player1:public QObject, public QGraphicsPixmapItem {
public:
    Player1(QGraphicsEllipseItem * c,QGraphicsEllipseItem *c2, QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

private:
    bool select1,select2;
    Tower * t;
    Tower * t1;
    QGraphicsEllipseItem * cur;
    QGraphicsEllipseItem * cur1;
    Thrd * th;
};
#endif // PLAYER1_H
