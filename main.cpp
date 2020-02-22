#include <QApplication>
#include "game.h"

//子弹类，分数统计需要使用，所以需要定义为全局
Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //创建游戏

    game = new Game();
    game->show();


    return a.exec();
}
