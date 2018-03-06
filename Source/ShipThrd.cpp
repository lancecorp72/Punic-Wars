#include "ShipThrd.h"

extern bool gameOn;

void ShipThrd::run() {
    while(s->x()>-30 && s->x()<1490 && gameOn) {
        msleep(100);
        emit flag();
    }

    if(s->x()==-60 && s->getPcode()<=2)
        s->delShip();
    if(gameOn)
        emit finished();
}
void ShipThrd::setShip(Ships *temp)
{
    s=temp;
}
