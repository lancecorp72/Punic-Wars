#include "TowerThrd.h"

extern bool gameOn;

void TowerThrd::run() {
    while(gameOn) {
        msleep(800);
        emit flag();
    }
}
void TowerThrd::setTower(Tower *temp) {
    t=temp;
}
