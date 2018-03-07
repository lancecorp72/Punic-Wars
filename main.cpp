#include <QApplication>
#include "Game.h"

//Global game object to access from other headers
Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Creating game class
    game = new Game();

    //Display the game widget
    game->show();

    return a.exec();
}
