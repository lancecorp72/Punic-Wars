#include "Game.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Tower.h"
#include "Player1.h"
#include <QBrush>
#include <QImage>
#include <QDebug>
#include "Ships.h"
#include "Resource.h"
#include "Tutorial.h"
Resource *player1_resources, *player2_resources;

Game::Game(){
    // create a scene
    scene = new QGraphicsScene();
    //set scene size to finite number
    scene->setSceneRect(0,0,1500,550);
    setBackgroundBrush(QBrush(QImage(":/Resources/images/map.jpg")));

    //disable scrollbars and fix scene size
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1500,550);

    // set the scene
    setScene(scene);

    //Create Resoource display
    player1_resources = new Resource(1);
    player2_resources = new Resource(2);
    scene->addItem(player1_resources);
    scene->addItem(player2_resources);

    //Create tower button for player 1
    QBrush brush1(Qt::gray, Qt::SolidPattern);
    QPen pen(Qt::black);
    QFont serifFont("Times", 20, QFont::Bold);
    QFont costFont("Times", 10, QFont::Bold);
    scene->addRect(0,0,100,50,pen,brush1);
    QGraphicsTextItem *text=scene->addText("Tower",serifFont);
    text->setPos(0,0);
    text=scene->addText("Cost: 1 bronze",costFont);
    text->setPos(0,24);
    //Create ship button for player 1
    scene->addRect(0,50,100,50,pen,brush1);
    text=scene->addText("Ship",serifFont);
    text->setPos(0,50);
    text=scene->addText("Cost: 1 iron",costFont);
    text->setPos(0,80);
    //Cursor for player 1
    QGraphicsEllipseItem *ei = new QGraphicsEllipseItem(QRect(QPoint(0,0),QSize(15,15)));
    QBrush brush2(Qt::red,Qt::SolidPattern);
    ei->setBrush(brush2);
    scene->addItem(ei);


    //Create tower button for player 2
    QBrush brush3(Qt::gray, Qt::SolidPattern);
    QPen pen1(Qt::black);
    scene->addRect(1400,0,1500,50,pen1,brush3);
    QGraphicsTextItem * text1 =scene->addText("Tower",serifFont);
    text1->setPos(1400,0);
    text1=scene->addText("Cost: 1 bronze",costFont);
    text1->setPos(1400,24);
    //Create ship button for player 2
    scene->addRect(1400,50,100,50,pen1,brush3);
    text=scene->addText("Ship",serifFont);
    text->setPos(1400,50);
    text=scene->addText("Cost: 1 iron",costFont);
    text->setPos(1400,80);
    //Cursor for player 2
    QGraphicsEllipseItem *ei2 = new QGraphicsEllipseItem(QRect(QPoint(0,0),QSize(15, 15)));
    QBrush brush4(Qt::blue,Qt::SolidPattern);
    ei2->setBrush(brush4);
    scene->addItem(ei2);

    Tutorial *tut = new Tutorial(scene,ei,ei2);

     tut->setFlag(QGraphicsItem::ItemIsFocusable);
    tut->setFocus();

    scene->addItem(tut);

    /*Player1 * p1 = new Player1(ei,ei2);
    p1->setFlag(QGraphicsItem::ItemIsFocusable);
    p1->setFocus();
    scene->addItem(p1);*/


    show();
}
