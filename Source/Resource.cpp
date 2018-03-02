#include "Resource.h"
#include <QFont>

Resource::Resource(int player_code, QGraphicsItem *parent): QGraphicsTextItem(parent){

    // initialize the resources to 100
    s_res = 3;
    t_res = 3;

    // draw the text and set both resources to 10
    setRes();

    if(player_code == 1){
        setDefaultTextColor(Qt::red);
        setPos(0,45);
    }
    else if(player_code == 2){
        setDefaultTextColor(Qt::blue);
        setPos(1350,45);
    }
    setFont(QFont("times",20));
}

void Resource::incT(){
    t_res++;
    setRes();
}

void Resource::incS(){
    s_res++;
    setRes();
}

void Resource::decT()
{
    if(t_res<=0)
        return;
    t_res--;
    setRes();
}

void Resource::decS()
{
    if(s_res<=0)
        return;
    s_res--;
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
