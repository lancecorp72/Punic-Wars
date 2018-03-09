#include "Tower.h"
#include "Bullet.h"
#include "Game.h"
#include "Ships.h"
#include <QPixmap>
#include <QVector>
#include <QLineF>
#include <QPointF>
#include <QPolygonF>
#include <QDebug>
#include "BulletMove.h"

extern Game * game;

Tower::Tower(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent) {
    // set the graphics
    setPixmap(QPixmap(":/Resources/images/towB.png"));
    tcenter=mapFromScene(sceneBoundingRect().center());

    // create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // scale points
    int SCALE_FACTOR = 40;
    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    // create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);

    // move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(pos()+tcenter);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    //initialize bool variables
    has_target=false;   // check whether a target is obtained
    no_fire=true;       //to prevent tower from firing before it is placed

    //hides the attack radius
    //attack_area->hide();

}

double Tower::distanceTo(QGraphicsItem *item) {
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Tower::fire() {
    Bullet * bullet = new Bullet();
    bullet->setPos(pos()+tcenter);

    QLineF ln(pos()+tcenter,attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);

    BulletMove * bm=new BulletMove();
    bm->thrdset(bullet);
}

void Tower::setNoFire() {
    no_fire=false;
}

void Tower::get_target() {
    if(no_fire)
        return;
    // get a list of all items colliding with attack_area
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    if (colliding_items.size() <= 1){
        has_target = false;
        return;
    }

    double closest_dist = 300;
    QPointF closest_pt = QPointF(0,0);

    for (size_t i = 0, n = colliding_items.size(); i < n; i++){
        Ships * ship = dynamic_cast<Ships *>(colliding_items[i]);
        if (ship){
            double this_dist = distanceTo(ship);
            if (this_dist < closest_dist){
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->sceneBoundingRect().center();
                has_target = true;
            }
        }
    }

    attack_dest = closest_pt;
    if(has_target)
    {
        fire();
        has_target=false;
    }

}
