#include "Game.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Tower.h"
#include "Player1.h"
#include <QDebug>

Game::Game(){
    // create a scene
    scene = new QGraphicsScene();
    //set scene size to finite number
    scene->setSceneRect(0,0,800,600);

    //disable scrollbars and fix scene size
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // set the scene
    setScene(scene);

    // create a player
    Player1 * p1 = new Player1();
    p1->setFlag(QGraphicsItem::ItemIsFocusable);
    p1->setFocus();
    scene->addItem(p1);

    setFixedSize(800,600);
}
