#ifndef PATH_H
#define PATH_H

#include <QPointF>
#include <QVector>
#include <QGraphicsPolygonItem>

class Path {
public:
    Path();

    //Define path area
    QGraphicsPolygonItem *path_area;

    //bollean function that returns if the tower is colliding with ship's path
    int iscolliding();

};

#endif // PATH_H
