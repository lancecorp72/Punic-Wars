#ifndef BULLETMOVE_H
#define BULLETMOVE_H

#include <QThread>
#include "Bullet.h"
#include <QDebug>
#include "BulletThrd.h"

class BulletMove : public QObject {
    Q_OBJECT
public:
    void thrdset(Bullet * b) {
        bul=b;
        bth.setBullet(b);
        connect(&bth,SIGNAL(flag()),bul,SLOT(move()));
        connect(&bth,SIGNAL(finished()),&bth,SLOT(quit()));
        bth.start();
    }
private:
    Bullet * bul;
    BulletThrd bth;
};

#endif // BULLETMOVE_H
