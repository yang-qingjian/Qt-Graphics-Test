#ifndef ENEMY_H
#define ENEMY_H
//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>
#include <QMediaPlayer>

//#include "classtype.h"

class Enemy :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT                //需要使用信号与槽，必须包含OBJECT

public:
    enum { Type = UserType + 3 };
    int type() const override;

    Enemy();                //默认构造函数
    void enemyMove();       //敌人移动函数

    //    ClassType getClassName();    //返回当前类型

private:
    //    ClassType myTpye;
    QMediaPlayer * enemyMus;
    QMediaPlayer * goingMus;

};

#endif // ENEMY_H
