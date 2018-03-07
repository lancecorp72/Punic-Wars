#include "BulletThrd.h"

extern bool gameOn;

void BulletThrd::run() {
    while(b->active && gameOn) {
        msleep(10);
        emit flag();
    }

    b->delBullet();
    emit finished();
}
void BulletThrd::setBullet(Bullet *temp) {
    b=temp;
}
