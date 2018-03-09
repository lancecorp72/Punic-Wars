#ifndef TOWERSHOOT_H
#define TOWERSHOOT_H

#include <QThread>
#include "Tower.h"
#include <QDebug>
#include "TowerThrd.h"

class TowerShoot : public QObject {
    Q_OBJECT
public:
    void thrdset(Tower * t) {
        twr=t;
        tth.setTower(t);
        connect(&tth,SIGNAL(flag()),twr,SLOT(get_target()));
        //connect(&tth,SIGNAL(finished()),&tth,SLOT(quit()));
        tth.start();
    }
private:
    Tower * twr;
    TowerThrd tth;
};

#endif // TOWERSHOOT_H
