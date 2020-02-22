#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include "Player.h"
#include "score.h"
#include "health.h"
#include <QTimer>
#include <QObject>

class Game{
public:

    explicit Game();
    void show();

    //创建场景
    QGraphicsScene * scene;

    //加入图形项
    Player * player;

    //创建视图
    QGraphicsView * view;

    //创建分数
    Score * score;

    //创建health
    Health * health;
};


#endif // GAME_H
