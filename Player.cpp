#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"
#include <QDebug>

Player::Player()
{
    //    myTpye = ClassType::PLAYER;

    //添加子弹的声音
    bulletMus = new QMediaPlayer();
    bulletMus->setMedia(QUrl("qrc:/sounds/res/sounds/Bullet_1.mp3"));
}

void Player::keyPressEvent(QKeyEvent *ev)
{
    /*
     * 说明：
     *      游戏是水平方向的，所以需要检测上下减实现方向
     *      检测空格发射子弹
     */
    //    qDebug()<<"玩家检测到按键响应";
    if(ev->key() == Qt::Key_Up)
    {
        //控制玩家不能移动到视口外部
        if(y() > 0){
            this->setPos(x(),y()-10);
        }

    }
    else if(ev->key() == Qt::Key_Down)
    {
        //控制玩家不能移动到视口外部
//        if(y() < (600-this->rect().height())){
        if(y() < (600-this->boundingRect().height())){
            this->setPos(x(),y()+10);
        }
    }
    else if(ev->key() == Qt::Key_Space)
    {
        //发出声音
        //判断当前音乐状态
        if(bulletMus->state() == QMediaPlayer::PlayingState)
        {
            bulletMus->setPosition(0);  //如果正在播放则，从0开始播放
        }
        else {
            bulletMus->play();
        }


        Bullet * bullet = new Bullet();
        //        bullet->setPos(x()+this->rect().width()-10,y()+this->rect().height()/2-bullet->rect().height()/2);    //设置位置

        bullet->setPos(x()+this->boundingRect().width()-10,y()+this->boundingRect().height()/2-bullet->boundingRect().height()/2);
        scene()->addItem(bullet);   //包含场景头文件，这里就能获取当前的场景
        qDebug()<<"子弹：发射!!!";
    }
}

void Player::creatEnemy()
{
    //创建敌人
    Enemy * enemy = new Enemy();
    //把新创建的敌人加入到场景
    scene()->addItem(enemy);
}

//返回当前类的类名
//ClassType Enemy::getClassName()
//{
//    return myTpye;
//}

//返回当前item子类的id
int Player::type() const
{
    return Type;
}
