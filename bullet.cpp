#include <QGraphicsScene>
#include <QtDebug>
#include <QTimer>
#include <QList>
#include "bullet.h"
#include "enemy.h"
#include "game.h"

extern Game * game; //extern 说明是外部声明的变量

Bullet::Bullet()
{
    //    myTpye = ClassType::BULLET;

    //创建对象后，设置子弹大小
//    this->setRect(0,0,60,60);
    setPixmap(QPixmap(":/image/res/image/Bullet_1.png"));


    //设置子弹移动槽函数
    QTimer * timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&Bullet::bulletMove);
    timer->start(50);

    //添加击落飞机的声音
    shootDownMus = new QMediaPlayer();
    shootDownMus ->setMedia(QUrl("qrc:/sounds/res/sounds/explosion.mp3"));
}

//子弹移动函数
void Bullet::bulletMove()
{
    //判断子弹是否超过右边的边界
    if(x()>1000)
    {
        scene()->removeItem(this);
        this->deleteLater();
        qDebug()<<"子弹：消失!!!";
    }
    else{
        this->setPos(x()+10,y());
        //        qDebug()<<"子弹：移动!!!";
    }

    //判断子弹是否撞到了敌人
    QList<QGraphicsItem *> collding_items = collidingItems();

    //.count :方法用于统计某个元素在列表中出现的次数
    //.size  :以int 形式返回列表中元素的个数
    for(int i = 0, n = collding_items.size();i<n;++i)
    {
        //销毁前必须判断类型，否则子弹出来先把自己炸了

        //判断方式1:******下面使用的是typeid方法，但是有警告，当前未采用
        //qDebug()<<"子弹：击毁了："<< typeid (collding_items[0]).name(); //子弹：击毁了： P13QGraphicsItem
        //if(typeid (*(collding_items[i])) == typeid (Enemy))

        //判断方式2:******给每个类中单独定义了一个枚举作为身份，但这这里使用了多态，是子类指向父类，然后使用父类的函数调用子类的方法，而父类没有这个方法，所以无法使用。
        //if(collding_items[i]->getTpyeId() == ClassType::ENEMY)

        //判断方式3:******和上面的方式2相同，系统提供了一个type的虚函数可以使用
        //[virtual] int QGraphicsItem::type() const
        //enum QGraphicsItem::anonymous 用户类型必须大于65536，而全局UserType就是65536

        if( collding_items[i]->type() == (UserType + 3))
        {
            //发出声音
            //判断当前音乐状态
            if(shootDownMus->state() == QMediaPlayer::PlayingState)
            {
                shootDownMus->setPosition(0);  //如果正在播放则，从0开始播放
            }
            else {
                shootDownMus->play();
            }

            //把撞击的对象移除
            scene()->removeItem(collding_items[i]);  //移除敌人
            scene()->removeItem(this);   //移除自己

            qDebug()<<"子弹：击毁了对象id为["<<collding_items[i]->type()<<"] 的敌人";

            //把销毁的对象释放
            delete collding_items[i];
            delete this;

            //如果这个函数放到移动的前面，则需要加return，释放后就退出

            //通过game对象进行加分
            game->score->incScore();

        }
    }

}

//返回当前类的类名
//ClassType Bullet::getClassName()
//{
//    return myTpye;
//}

//返回当前item子类的id
int Bullet::type() const
{
    return Type;
}
