#ifndef BULLETTHRD_H
#define BULLETTHRD_H

#include <QThread>
#include "Bullet.h"
#include <QDebug>

class BulletThrd : public QThread {
    Q_OBJECT
public:
    void setBullet(Bullet *);
public slots:
    void run();
signals:
    void flag();
    void finished();
private:
    Bullet * b;
};

#endif // BULLETTHRD_H
