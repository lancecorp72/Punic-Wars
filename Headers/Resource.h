#ifndef RESOURCE_H
#define RESOURCE_H

#include <QGraphicsTextItem>

class Resource: public QGraphicsTextItem{
public:
    Resource(int player_code, QGraphicsItem * parent=0);  //player_code = 1 if player 1
                                                          //player_code = 2 if player 2
    void incT(int amt);
    void incS(int amt);
    void decT(int amt);
    void decS(int amt);
    int getT();
    int getS();
    void setRes();
private:
    int s_res,t_res;
};

#endif // RESOURCE_H
