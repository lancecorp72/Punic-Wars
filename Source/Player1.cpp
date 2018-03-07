#include "Player1.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Tower.h"
#include "Bullet.h"
#include "Resource.h"
#include "Ships.h"
#include <QDebug>
#include "Path.h"
#include "Game.h"
#include "ShipMove.h"

extern Resource *player1_resources, *player2_resources;

Player1::Player1(QGraphicsEllipseItem * c,QGraphicsEllipseItem *c2 ,QGraphicsItem * parent): QGraphicsPixmapItem(parent){
    select1=false;
    select2=false;
    t= NULL;
    t1= NULL;
    cur=c;
    cur1=c2;
    th=NULL;
    ts=NULL;
   }

void Player1::keyPressEvent(QKeyEvent *event) {

    //player 1
    if(select1 == true) {

        //tower is selected
        t -> setPixmap(QPixmap(":/Resources/images/towByes.png"));

        if(event->key() == Qt::Key_F&& (cur->x() >= 100 || cur->y() >= 50)) {

            Path *waters1 = new Path();
            int c1 = waters1->iscolliding();

            //cost is deducted when tower is placed
            if(c1 == 0){

                //Place only if tower is not in ship's path
                t -> setPixmap(QPixmap(":/Resources/images/towB.png"));
                player1_resources->decT(1);
                select1=false;

                //make cursor opaque after tower is placed
                cur->setOpacity(1);

                //tower to start firing only after placed
                t->setNoFire();

                //to check for targets periodically
                ts=new TowerShoot();
                ts->thrdset(t);
            }
            else{

                deny = new QMediaPlayer();
                deny -> setMedia(QUrl("qrc:/Sounds/Resources/Sounds/Error_alert.wav"));
                if (deny ->state() == QMediaPlayer::PlayingState){
                    deny ->setPosition(0);
                }
                else if (deny->state() == QMediaPlayer::StoppedState){
                    deny->play();
                }
            }
        }

        //movement controls for player 1
        else if(event->key() == Qt::Key_D) {
            if(t->x()<700&&cur->x()<700){

                //Move Right
                t->setPos(t->x()+50,t->y());
                cur->setPos(cur->x()+50,cur->y());

                //Check if colliding with ship's path
                Path *waters1 = new Path();
                waters1->iscolliding();

            }

            if(t->x()<700&&cur->x()<700) {
                t->setPos(t->x()+50,t->y());
                cur->setPos(cur->x()+50,cur->y());
            }
        }
        else if(event->key() == Qt::Key_S) {
            if(t->y()<500&&cur->y()<500){

                //Move Down
                t->setPos(t->x(),t->y()+50);
                cur->setPos(cur->x(),cur->y()+50);

                //Check if colliding with ship's path
                Path *waters1 = new Path();
                waters1->iscolliding();
            }
        }
        else if(event->key() == Qt::Key_A) {
            if(t->x()>0&&cur->x()>0){

               //Move Left
               t->setPos(t->x()-50,t->y());
               cur->setPos(cur->x()-50,cur->y());

               //Check if colliding with ship's path
               Path *waters1 = new Path();
               waters1->iscolliding();
            }
        }
        else if(event->key() == Qt::Key_W) {
            if(t->y()>0&&cur->y()>0){

                //Move up
                t->setPos(t->x(),t->y()-50);
                cur->setPos(cur->x(),cur->y()-50);

                //Check if colliding with ship's path
                Path *waters1 = new Path();
                waters1->iscolliding();
            }
        }
        else if(event->key() == Qt::Key_Escape) {

            //make cursor opaque and delete temporary object
            cur->setOpacity(1);
            delete t;
            select1=false;
        }
    }

    else {

        //no towers are selected
        if(event->key() == Qt::Key_F && cur->x()<100 && cur->y()<50) {

            //if tower resource is less than cost, then don't select tower
            if(player1_resources->getT()==0) {
                qInfo()<<"not enough bronze";
                return;
            }

            //Create temporary Tower
            select1=true;
            t=new Tower();
            t->setPos(cur->x(),cur->y());
            scene()->addItem(t);

            //make cursor transparent when tower is selected
            cur->setOpacity(0);
        }
        else if(event->key() == Qt::Key_F && cur->x()<100 && cur->y()<100) {

            //if ship resource is less than cost, then ships are not created
            if(player1_resources->getS()==0) {
                qInfo()<<"not enough iron";
                return;
            }

            //Else Ships are added
            player1_resources->decS(1);
            Ships * s=new Ships(1,scene());
            th=new ShipMove();
            th->thrdset(s);
        }

        //Moving cursor
        else if(event->key() == Qt::Key_D) {
            if(cur->x()<700)
                cur->setPos(cur->x()+50,cur->y());
        }
        else if(event->key() == Qt::Key_S) {
            if(cur->y()<500)
                cur->setPos(cur->x(),cur->y()+50);
        }
        else if(event->key() == Qt::Key_A) {
            if(cur->x()>0)
               cur->setPos(cur->x()-50,cur->y());
        }
        else if(event->key() == Qt::Key_W) {
            if(cur->y()>0)
                cur->setPos(cur->x(),cur->y()-50);
        }
    }

    //player 2
    if(select2 == true) {

        //tower is selected
        t1 -> setPixmap(QPixmap(":/Resources/images/towByes.png"));

        if(event->key() == Qt::Key_Return && (cur1->x() < 1400 || cur1->y() >= 50)) {
            Path *waters2 = new Path();
            int c2 = waters2->iscolliding();

            //cost is deducted when tower is placed
            if(c2 == 0){

                //Place only if tower is not in ship's path
                t1 -> setPixmap(QPixmap(":/Resources/images/towB.png"));
                player2_resources->decT(1);

                //make cursor opaque after tower is placed
                cur1->setOpacity(1);
                select2=false;

                //tower to start firing only after placed
                t1->setNoFire();

                //to check for targets periodically
                ts=new TowerShoot();
                ts->thrdset(t1);
            }
            else{

                deny = new QMediaPlayer();
                deny -> setMedia(QUrl("qrc:/Sounds/Resources/Sounds/Error_alert.wav"));
                if (deny ->state() == QMediaPlayer::PlayingState){
                    deny ->setPosition(0);
                }
                else if (deny->state() == QMediaPlayer::StoppedState){
                    deny->play();
                }
            }

        }

        //movement controls for player 2
        else if(event->key() == Qt::Key_Right) {

            //Move Right
            if(t1->x()<1450&&cur1->x()<1450){

                t1->setPos(t1->x()+50,t1->y());
                cur1->setPos(cur1->x()+50,cur1->y());

                //Check if colliding with ship's path
                Path *waters2 = new Path();
                waters2->iscolliding();
            }

        }
        else if(event->key() == Qt::Key_Down) {

            //Move Down
            if(t1->y()<500&&cur1->y()<500){

                t1->setPos(t1->x(),t1->y()+50);
                cur1->setPos(cur1->x(),cur1->y()+50);

                //Check if colliding with ship's path
                Path *waters2 = new Path();
                waters2->iscolliding();
            }
        }
        else if(event->key() == Qt::Key_Left) {

            //Move Left
            if(t1->x()>800&&cur1->x()>800){

               t1->setPos(t1->x()-50,t1->y());
               cur1->setPos(cur1->x()-50,cur1->y());

               //Check if colliding with ship's path
               Path *waters2 = new Path();
               waters2->iscolliding();
            }
        }
        else if(event->key() == Qt::Key_Up) {

            //Move Up
            if(t1->y()>0&&cur1->y()>0){

                t1->setPos(t1->x(),t1->y()-50);
                cur1->setPos(cur1->x(),cur1->y()-50);

                //Check if colliding with ship's path
                Path *waters2 = new Path();
                waters2->iscolliding();
            }
        }
        else if(event->key() == Qt::Key_Backspace) {

            //make cursor opaque and delete temporary tower
            cur1->setOpacity(1);
            delete t1;
            select2=false;
        }
    }
    else {

        //no towers are selected
        if(event->key() == Qt::Key_Return && cur1->x()>=1400 && cur1->y()<50) {

            //if tower resource is less than cost, then don't select tower
            if(player2_resources->getT()==0) {
                qInfo()<<"not enough bronze";
                return;
            }

            //Creating Temporary tower and add it to scene
            select2=true;
            t1=new Tower();
            t1->setPos(cur1->x(),cur1->y());
            scene()->addItem(t1);

            //make cursor transparent when tower is selected
            cur1->setOpacity(0);
        }
        else if(event->key() == Qt::Key_Return && cur1->x()>=1400 && cur1->y()<100) {

            //if ship resource is less than cost, then ships are not created
            if(player2_resources->getS()==0) {
                qInfo()<<"not enough iron";
                return;
            }

            //Else create ship and add to scene
            player2_resources->decS(1);
            Ships * s=new Ships(2,scene());
            th=new ShipMove();
            th->thrdset(s);
        }

        //Moving cursor
        else if(event->key() == Qt::Key_Right) {
            if(cur1->x()<1450)
                cur1->setPos(cur1->x()+50,cur1->y());
        }
        else if(event->key() == Qt::Key_Down) {
            if(cur1->y()<500)
                cur1->setPos(cur1->x(),cur1->y()+50);
        }
        else if(event->key() == Qt::Key_Left) {
            if(cur1->x()>800)
               cur1->setPos(cur1->x()-50,cur1->y());
        }
        else if(event->key() == Qt::Key_Up) {
            if(cur1->y()>0)
                cur1->setPos(cur1->x(),cur1->y()-50);
        }
    }
}

