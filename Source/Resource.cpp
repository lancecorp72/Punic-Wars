#include "Resource.h"
#include <QFont>

Resource::Resource(int player_code, QGraphicsItem *parent): QGraphicsTextItem(parent){

    // initialize the resources to 100
    s_res = 3;
    t_res = 2;

    // draw the text and set both resources to 10
    setRes();

    if(player_code == 1){
        setDefaultTextColor(Qt::red);
        setPos(0,100);
    }
    else if(player_code == 2){
        setDefaultTextColor(Qt::blue);
        setPos(1350,100);
    }
    setFont(QFont("times",20));
}

void Resource::incT(int amt){
    t_res+=amt;
    setRes();
}

void Resource::incS(int amt){
    s_res+=amt;
    setRes();
}

void Resource::decT(int amt)
{
    if(t_res<amt)
        return;
    t_res-=amt;
    setRes();
}

void Resource::decS(int amt)
{
    if(s_res<amt)
        return;
    s_res-=amt;
    setRes();
}

void Resource::setRes()
{
    //set/modify displayed text
    setPlainText(QString("Bronze : ") + QString::number(t_res) + QString("\nIron :") + QString::number(s_res));
}

int Resource::getT(){
    return t_res;
}

int Resource::getS(){
    return s_res;
}
