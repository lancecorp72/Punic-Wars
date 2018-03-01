#ifndef RESOURCE_H
#define RESOURCE_H

#include <QGraphicsTextItem>

class Resource: public QGraphicsTextItem{
public:
    Resource(int player_code, QGraphicsItem * parent=0);  //player_code = 1 if player 1
                                                          //player_code = 2 if player 2
    void increase();
    int getresources();
private:
    int resources;
};

#endif // RESOURCE_H
