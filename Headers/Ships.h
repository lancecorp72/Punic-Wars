#ifndef SHIPS_H
#define SHIPS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QMediaPlayer>

class Ships: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ships(int player_code,QGraphicsScene *scene,int health=20,QGraphicsItem * parent=0);
//                                    Player code = 1 for player 1
//                                                = 2 for player 2

    //Set rotaion with respect to point p
    void rotateTopoint(QPointF p);

    //Decrease the health of the ship when it collides with a bullet
    void decreasehealth(int damage);

    //Representing the health of the ship graphically
    QGraphicsRectItem * healthbar;

    //Get the player code
    int getPcode();

    //Mediaplayer objects to play sounds within the game.
    QMediaPlayer *win;
    QMediaPlayer *splash;

public slots:

    //Moves the ship forward
    void move_forward();

    //Deletes an instance of the ship
    void delShip();

private:

    QList<QPointF> points;            //List of points the ships have to traverse
    QPointF dest;                     //Dynamic Destinations
    int dest_index;                   //Current Destination index

    //Auxillary variables and objects
    QGraphicsScene *s;
    int h;
    int max_h;
    int pcode;
    int distance;
};

#endif // SHIPS_H
