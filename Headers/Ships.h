#ifndef SHIPS_H
#define SHIPS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Ships: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ships(QGraphicsItem * parent=0);
    void rotateTopoint(QPointF p);  //Set rotaion with respect to point p
public slots:
    void move_forward();            //Moves the ship forward
private:
    QList<QPointF> points;          //List of points the ships have to traverse
    QPointF dest;                   //Dynamic Destinations
    int dest_index;                //Current Destination index
};

#endif // SHIPS_H
