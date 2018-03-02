#ifndef SHIPS_H
#define SHIPS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Ships: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ships(int player_code,QGraphicsScene *scene,QGraphicsItem * parent=0,int health=20);
//                                    Player code = 1 for player 1
//                                                = 2 for player 2
    void rotateTopoint(QPointF p);//Set rotaion with respect to point p
    void decreasehealth(int damage);
    QGraphicsRectItem * healthbar;
public slots:
    void move_forward();              //Moves the ship forward
private:
    QList<QPointF> points;            //List of points the ships have to traverse
    QPointF dest;                     //Dynamic Destinations
    int dest_index;  //Current Destination index
    QGraphicsScene *s;
    int h;
    int max_h;
    int pcode;
    int distance;

};

#endif // SHIPS_H
