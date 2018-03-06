#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Tower.h"
#include "ShipMove.h"
#include "TowerShoot.h"

class Tutorial:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Tutorial(QGraphicsScene *s,QGraphicsEllipseItem * c,QGraphicsEllipseItem *c2, QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void nothing(QGraphicsTextItem *t,int limit =-1);
private:
    bool select1,select2;
    Tower * t;
    Tower * t1;
    QGraphicsEllipseItem * cur;
    QGraphicsEllipseItem * cur1;
    int timecount;
    QTimer *timer;
    QGraphicsScene *s1;
    int stage;
    QGraphicsTextItem *text;
    QGraphicsTextItem *text2;
    QList<QGraphicsItem*> list;
    ShipMove * th;
    TowerShoot * ts;
};

#endif // TUTORIAL_H
