#ifndef PLAYER1_H
#define PLAYER1_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Tower.h"

class Player1:public QObject, public QGraphicsPixmapItem {
public:
    Player1(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
private:
    bool select;
    Tower * t;
};

#endif // PLAYER1_H
