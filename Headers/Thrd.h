#ifndef THRD_H
#define THRD_H

#include <QThread>
#include "Ships.h"
#include <QDebug>
#include "ShipThrd.h"

class Thrd : public QObject {
    Q_OBJECT
public:
    void thrdset(Ships * s) {
        ship=s;
        sth.setShip(s);
        connect(&sth,SIGNAL(flag()),ship,SLOT(move_forward()));
        connect(&sth,SIGNAL(finished()),&sth,SLOT(quit()));
        sth.start();
    }
private:
    Ships * ship;
    shipThrd sth;
};

#endif // THRD_H
