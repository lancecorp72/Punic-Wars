#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMediaPlayer>

class Game: public QGraphicsView{
public:
    // member functions
    Game();

    QMediaPlayer *bgmusic;

    // member attributes
    QGraphicsScene * scene;
};

#endif // GAME_H
