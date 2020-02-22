#ifndef BULLET_H
#define BULLET_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
//#include "ClassType.h"

class Bullet :public QObject, public QGraphicsPixmapItem{

    Q_OBJECT        //需要使用信号与槽，必须包含OBJECT

public:

    enum { Type = UserType + 2 };
    int type() const override;

    Bullet();       //默认构造函数
    void bulletMove();    //子弹移动函数
    //    ClassType getClassName();    //返回当前类型(无效)


private:
    //    ClassType myTpye;
    QMediaPlayer * shootDownMus;
};

#endif // BULLET_H
