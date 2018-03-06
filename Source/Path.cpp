#include "Path.h"
#include <QGraphicsItem>
#include "Tower.h"
#include "Game.h"
#include <QPolygonF>

extern Game * game;

Path::Path::Path()
{
    //Define the points which are the vertices of the path polygon
    QVector<QPointF> path_points;

    path_points << QPointF(0,455) << QPointF(162,455) << QPointF(162,362) << QPointF(325,362) << QPointF(325,448) << QPointF(412,448) << QPointF(412,296) << QPointF(290,296) << QPointF(290,57) << QPointF(450,57) << QPointF(450,153)
                << QPointF(540,153) << QPointF(540,60) << QPointF(953,60) << QPointF(953,145) << QPointF(1035,145) << QPointF(1035,57) << QPointF(1208,57) << QPointF(1208,288) << QPointF(1081,288) << QPointF(1081,455) << QPointF(1170,455)
                << QPointF(1170,360) << QPointF(1334,360) << QPointF(1334,455) << QPointF(1500,455) << QPointF(1500,490) << QPointF(1290,490) << QPointF(1290,402) << QPointF(1212,402) << QPointF(1212,490) << QPointF(1042,490)
                << QPointF(1042,252) << QPointF(1164,252) << QPointF(1164,95) << QPointF(1078,95) << QPointF(1078,188) << QPointF(910,188) << QPointF(910,100) << QPointF(582,100) << QPointF(582,188) << QPointF(417,188)
                << QPointF(417,95) << QPointF(330,95) << QPointF(330,252) << QPointF(454,252) << QPointF(454,492) << QPointF(287,492) << QPointF(287,400) << QPointF(203,400) << QPointF(203,490) << QPointF(0,490);

    //Create a polygon which define the path area
    path_area = new QGraphicsPolygonItem(QPolygonF(path_points));

    //add path to scene
    game->scene->addItem(path_area);

    //Set Opacity of the polygon so that it doesn't show up in the game view
    path_area->setOpacity(0);
}

int Path::iscolliding()
{
    //Returns 1 if the tower is colliding with the ship's path
    //Else returns 0

    QList<QGraphicsItem *> colliding_items = path_area->collidingItems();       //List of objects that are colliding with the path

    for (size_t i = 0, n = colliding_items.size(); i < n; i++){
        Tower * tow = dynamic_cast<Tower *>(colliding_items[i]);
        if (tow){
            return 1;           //Collides
        }
    }
    return 0;                   // Does not collide

}
