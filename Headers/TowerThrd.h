#ifndef TOWERTHRD_H
#define TOWERTHRD_H

#include <QThread>
#include "Tower.h"
#include <QDebug>

class TowerThrd : public QThread {
    Q_OBJECT
public:
    void setTower(Tower *);
public slots:
    void run();
signals:
    void flag();
private:
    Tower * t;
};

#endif // TOWERTHRD_H
