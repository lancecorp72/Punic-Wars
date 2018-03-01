#include "Resource.h"
#include <QFont>

Resource::Resource(int player_code, QGraphicsItem *parent): QGraphicsTextItem(parent){

    // initialize the resources to 100
    resources = 100;

    // draw the text
    setPlainText(QString("Resources: ") + QString::number(resources)); // Resource: 100

    if(player_code == 1){
        setDefaultTextColor(Qt::red);
        setPos(0,45);
    }
    else if(player_code == 2){
        setDefaultTextColor(Qt::blue);
        setPos(1300,45);
    }
    setFont(QFont("times",20));
}

void Resource::increase(){
    resources++;
    setPlainText(QString("Resources: ") + QString::number(resources)); // Resource: <current_resources>
}

int Resource::getresources(){
    return resources;
}
