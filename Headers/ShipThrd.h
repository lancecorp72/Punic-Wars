#ifndef SAMPLE_H
#define SAMPLE_H

#include <QThread>
#include "Ships.h"
#include <QDebug>

class ShipThrd : public QThread {
    Q_OBJECT
public:
    void setShip(Ships *);
public slots:
    void run();
signals:
    void flag();
    void finished();
private:
    Ships * s;
};

#endif // SAMPLE_H
