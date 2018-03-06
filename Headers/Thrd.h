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
        //QThread * q = new QThread();
        ship=s;
        smp.setShip(s);
        //connect(&smp,SIGNAL(started()),&smp,SLOT(run()));
        connect(&smp,SIGNAL(flag()),ship,SLOT(move_forward()));
        connect(&smp,SIGNAL(finished()),&smp,SLOT(quit()));
        connect(&smp,SIGNAL(finished()),ship,SLOT(deleteLater()));
        smp.start();
    }
private:
    Ships * ship;
    shipThrd smp;
};

#endif // THRD_H
