#ifndef PLAYER_H
#define PLAYER_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
//#include "classtype.h"

class Player: public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    enum { Type = UserType + 1 };
    int type() const override;

    Player();

    void keyPressEvent(QKeyEvent * ev);

    //    ClassType getClassName();    //返回当前类型


public slots:
    //创建敌人
    void creatEnemy();

private:
    //    ClassType myTpye;
    QMediaPlayer * bulletMus;
};

#endif // MYRECT_H
