#include "enemy.h"
#include <QtDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "game.h"

extern Game * game; //extern 说明是外部声明的变量

Enemy::Enemy()
{
    //    myTpye == ClassType::ENEMY;

    //创建对象后，设置敌人大小
    //    this->setRect(0,0,75,150);
    setPixmap(QPixmap(":/image/res/image/EnemyPlane.png"));

    //使用c语言的伪随机数来产生y位置(高度600-本身高度）
    int random = rand() %450;
    setPos(980,random);

    //设置敌人移动槽函数
    QTimer * timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&Enemy::enemyMove);
    timer->start(50);

    //添加和玩家撞击的声音
    enemyMus = new QMediaPlayer();
    enemyMus->setMedia(QUrl("qrc:/sounds/res/sounds/Warning.mp3"));

    //添加飞机飞过的声音
    goingMus = new QMediaPlayer();
    goingMus ->setMedia(QUrl("qrc:/sounds/res/sounds/going.wav"));
}

//敌人移动函数
void Enemy::enemyMove()
{
    //判断敌人是否超过左边的边界
    //    if(x()< (0-this->rect().width()+20));
    if(x()< (0 - this->boundingRect().width() +20))
    {
        scene()->removeItem(this);
        this->deleteLater();
        qDebug()<<"敌人：消失!!!";

        //敌人通过：通过game对象进行减1
        game->health->decHealth();

        //发出声音
        //判断当前音乐状态
        if(goingMus->state() == QMediaPlayer::PlayingState)
        {
            goingMus->setPosition(0);  //如果正在播放则，从0开始播放
        }
        else {
            goingMus->play();
        }

    }
    else{
        this->setPos(x()-10,y());
        //        qDebug()<<"敌人：移动!!!";
    }

    //判断子弹是否撞到了敌人
    QList<QGraphicsItem *> collding_items = collidingItems();

    //.count :方法用于统计某个元素在列表中出现的次数
    //.size  :以int 形式返回列表中元素的个数
    for(int i = 0, n = collding_items.size();i<n;++i)
    {
        //判断方式3:******和上面的方式2相同，系统提供了一个type的虚函数可以使用
        //[virtual] int QGraphicsItem::type() const
        //enum QGraphicsItem::anonymous 用户类型必须大于65536，而全局UserType就是65536

        if( collding_items[i]->type() == (UserType + 1))
        {
            //发出声音
            //判断当前音乐状态
            if(enemyMus->state() == QMediaPlayer::PlayingState)
            {
                enemyMus->setPosition(0);  //如果正在播放则，从0开始播放
            }
            else {
                enemyMus->play();
            }


            qDebug()<<"敌机：撞击了对象id为["<<collding_items[i]->type()<<"] 的玩家";

            //如果这个函数放到移动的前面，则需要加return，释放后就退出

            //把自己销毁（敌机）
            scene()->removeItem(this);  //移除敌人

            //敌机移除后，如果不释放自己，界面就卡主了，原因未知
            this->deleteLater();

            //通过game对象进行减1
            game->health->decHealth();
        }
    }

    //只要敌人在移动，就给玩家设置焦点，避免切换窗口焦点丢失
    game->player->setFocus();
}

//返回当前类的类名
//ClassType Enemy::getClassName()
//{
//    return myTpye;
//}

//返回当前item子类的id
int Enemy::type() const
{
    return Type;
}
