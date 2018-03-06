#include "Tutorial.h"
#include "Player1.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Tower.h"
#include "Bullet.h"
#include "Resource.h"
#include "Ships.h"
#include <QDebug>
#include "Game.h"
#include <QPropertyAnimation>
#include <QGraphicsItemAnimation>
#include <QTimer>

extern Resource *player1_resources, *player2_resources;
extern bool gameOn;

Tutorial::Tutorial(QGraphicsScene *s,QGraphicsEllipseItem * c,QGraphicsEllipseItem *c2 ,QGraphicsItem * parent): QGraphicsPixmapItem(parent){
    select1=false;
    select2=false;                      // Initialization
    t= NULL;
    t1= NULL;
    cur=c;
    cur1=c2;
    cur->hide();
    cur1->hide();
    cur1->setPos(1450,0);
    QFont serifFont("Times", 200, QFont::Bold);
    text=s->addText("Punic Wars",serifFont);
    text->setPos(60,100);
    timer= new QTimer(this);
    timecount=0;
    s1=s;
    connect(timer, &QTimer::timeout, [=]() {
         nothing(text);
    });
    timer->start(100);


    serifFont.setPixelSize(50);
    text2 =s->addText("Press E to continue");
    text2->setDefaultTextColor(Qt::white);
    text2->setPos(630,400);
    stage=1;




}
void Tutorial::nothing(QGraphicsTextItem *text,int limit)  // Animation
{
    if(timecount==limit) {
        timecount=0;
    }

    if(timecount%2==0)
        text->setDefaultTextColor(Qt::white);
    else
        text->setDefaultTextColor(Qt::gray);
    timecount++;


}
void Tutorial::keyPressEvent(QKeyEvent *event) {
    //player 1
    if(stage==1 && event->key()==Qt::Key_E)
    {
        timecount=-1;
        disconnect(timer,SIGNAL(timeout()),this,SLOT(nothing(QGraphicsTextItem*,int)));
        stage=2;
        s1->removeItem(text);
        text=text2;
    }
    if(stage==2)
    {                                                              //Player 1 Movement controls
        text2= s1->addText("This is your cursor Player 1, Use arrow keys to move. Try now");
        cur->show();

        text2->setPos(120,150);
        text2->setDefaultTextColor(Qt::white);
        cur->setPos(300,200);
        stage=3;



    }

    else if(stage==3&&event->key()==Qt::Key_E)
    {
        s1->removeItem(text2);                                   //Player 2 Movement controls
        text2= s1->addText("This is your cursor Player 2, Use W/A/S/D to move. Try now");
        cur1->show();

        text2->setPos(700,150);
        text2->setDefaultTextColor(Qt::white);
        cur1->setPos(1000,200);
        stage=4;


    }

    else if(stage==4&&event->key()==Qt::Key_E)
    {                               //Create tower
        s1->removeItem(text2);
        text2= s1->addText("To select a tower move your cursor over the Tower icon and press Enter(Player1) or F(Player2)");


        text2->setPos(300,150);
        text2->setDefaultTextColor(Qt::white);

        stage=5;


    }
    else if(stage==5&&event->key()==Qt::Key_E)  //Creating a ship
    {
        s1->removeItem(text2);
        text2= s1->addText("To create a ship move your cursor over the Ship icon and press Enter(Player1) or F(Pelayer2)");


        text2->setPos(300,150);
        text2->setDefaultTextColor(Qt::white);

        stage=6;
    }
    else if(stage==6&&event->key()==Qt::Key_E)
    {
        s1->removeItem(text2);
        text2= s1->addText("End of Tutorial , Have Fun");

        text2->setPos(625,150);
        text2->setDefaultTextColor(Qt::white);
        stage=7;

    }
    else if(stage==7)
    {
        //Remove hints
        s1->removeItem(text);
        s1->removeItem(text2);
        s1->removeItem(this);
        s1->removeItem(player1_resources);
        s1->removeItem(player2_resources);

        //Re initialize resources
        player1_resources = new Resource(1);
        player2_resources = new Resource(2);
        s1->addItem(player1_resources);
        s1->addItem(player2_resources);
        cur->setOpacity(1);
        cur1->setOpacity(1);
        gameOn=true;

        //Add player
        Player1 * p1 = new Player1(cur,cur1);
        p1->setFlag(QGraphicsItem::ItemIsFocusable);
        p1->setFocus();
        s1->addItem(p1);

        //delete items created in tutorial
        QList<QGraphicsItem*>::iterator i;
        for (int i=0;i<list.size();i++)
            s1->removeItem(list[i]);
    }

    if(select1 == true) {        //tower is selected
        if(event->key() == Qt::Key_Return) {
            //tower to start firing only after placed
            t->setNoFire();
            //cost is deducted when tower is placed
            player1_resources->decT(1);
            //make cursor opaque after tower is placed
            cur->setOpacity(1);
            select1=false;


        }
        //movement controls for player 1
        else if(event->key() == Qt::Key_Right) {
            if(t->x()<700&&cur->x()<700)
            {t->setPos(t->x()+50,t->y());
                cur->setPos(cur->x()+50,cur->y());}

        }
        else if(event->key() == Qt::Key_Down) {
            if(t->y()<500&&cur->y()<500)
            {t->setPos(t->x(),t->y()+50);
                cur->setPos(cur->x(),cur->y()+50);}
        }
        else if(event->key() == Qt::Key_Left) {
            if(t->x()>0&&cur->x()>0)
            {t->setPos(t->x()-50,t->y());
               cur->setPos(cur->x()-50,cur->y());}
        }
        else if(event->key() == Qt::Key_Up) {
            if(t->y()>0&&cur->y()>0)
            {t->setPos(t->x(),t->y()-50);
                cur->setPos(cur->x(),cur->y()-50);}
        }
        else if(event->key() == Qt::Key_Escape) {
            //make cursor opaque
            cur->setOpacity(1);
            delete t;
            select1=false;
        }
    }
    else {                      //no towers are selected
        if(event->key() == Qt::Key_Return && cur->x()<100 && cur->y()<50&&stage>=4) {
            //if tower resource is less than cost, then don't select tower
            if(player1_resources->getT()==0) {
                qInfo()<<"not enough bronze";
                return;
            }
            select1=true;
            t=new Tower();
            t->setPos(cur->x(),cur->y());
            scene()->addItem(t);
            //make cursor transparent when tower is selected
            cur->setOpacity(0);
            list.append(t);
        }
        else if(event->key() == Qt::Key_Return && cur->x()<100 && cur->y()<100&&stage>=5) {
            //if ship resource is less than cost, then ships are not created
            if(player1_resources->getS()==0) {
                qInfo()<<"not enough iron";
                return;
            }
            player1_resources->decS(1);
            Ships * s=new Ships(3,scene());
            th=new Thrd();
            th->thrdset(s);
            list.append(s);
            list.append(s->healthbar);
        }
        else if(event->key() == Qt::Key_Right) {
            if(cur->x()<700)
                cur->setPos(cur->x()+50,cur->y());
        }
        else if(event->key() == Qt::Key_Down) {
            if(cur->y()<500)
                cur->setPos(cur->x(),cur->y()+50);
        }
        else if(event->key() == Qt::Key_Left) {
            if(cur->x()>0)
               cur->setPos(cur->x()-50,cur->y());
        }
        else if(event->key() == Qt::Key_Up) {
            if(cur->y()>0)
                cur->setPos(cur->x(),cur->y()-50);
        }
    }
    //player 2
    if(select2 == true) {        //tower is selected
        if(event->key() == Qt::Key_F) {
            //tower to start firing only after placed
            t1->setNoFire();
            //cost is deducted when tower is placed
            player2_resources->decT(1);
            //make cursor opaque after tower is placed
            cur1->setOpacity(1);
            select2=false;

        }
        //movement controls for player 2
        else if(event->key() == Qt::Key_D) {
            if(t1->x()<1450&&cur1->x()<1450)
            {t1->setPos(t1->x()+50,t1->y());
                cur1->setPos(cur1->x()+50,cur1->y());}

        }
        else if(event->key() == Qt::Key_S) {
            if(t1->y()<500&&cur1->y()<500)
            {t1->setPos(t1->x(),t1->y()+50);
                cur1->setPos(cur1->x(),cur1->y()+50);}
        }
        else if(event->key() == Qt::Key_A) {
            if(t1->x()>800&&cur1->x()>800)
            {t1->setPos(t1->x()-50,t1->y());
               cur1->setPos(cur1->x()-50,cur1->y());}
        }
        else if(event->key() == Qt::Key_W) {
            if(t1->y()>0&&cur1->y()>0)
            {t1->setPos(t1->x(),t1->y()-50);
                cur1->setPos(cur1->x(),cur1->y()-50);}
        }
        else if(event->key() == Qt::Key_Backspace) {
            //make cursor opaque
            cur1->setOpacity(1);
            delete t1;
            select2=false;
        }
    }
    else {                      //no towers are selected
        if(event->key() == Qt::Key_F && cur1->x()>=1400 && cur1->y()<50&&stage>=4) {
            //if tower resource is less than cost, then don't select tower
            if(player2_resources->getT()==0) {
                qInfo()<<"not enough bronze";
                return;
            }
            select2=true;
            t1=new Tower();
            t1->setPos(cur1->x(),cur1->y());
            scene()->addItem(t1);
            //make cursor transparent when tower is selected
            cur1->setOpacity(0);
            list.append(t1);
        }
        else if(event->key() == Qt::Key_F && cur1->x()>=1400 && cur1->y()<100&&stage>=5) {
            //if ship resource is less than cost, then ships are not created
            if(player2_resources->getS()==0) {
                qInfo()<<"not enough iron";
                return;
            }
            player2_resources->decS(1);
            Ships * s=new Ships(4,scene());
            th=new Thrd();
            th->thrdset(s);
            list.append(s);
            list.append(s->healthbar);

        }
        else if(event->key() == Qt::Key_D) {
            if(cur1->x()<1450)
                cur1->setPos(cur1->x()+50,cur1->y());
        }
        else if(event->key() == Qt::Key_S) {
            if(cur1->y()<500)
                cur1->setPos(cur1->x(),cur1->y()+50);
        }
        else if(event->key() == Qt::Key_A) {
            if(cur1->x()>800)
               cur1->setPos(cur1->x()-50,cur1->y());

        }
        else if(event->key() == Qt::Key_W) {
            if(cur1->y()>0)
                cur1->setPos(cur1->x(),cur1->y()-50);
        }

    }
}
