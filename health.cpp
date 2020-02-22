#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem * parent):QGraphicsTextItem(parent)
{
    //生命默认为0；
    health = 5;

    //设置内容和字体
    setPlainText(QString("生命：")+ QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("宋体",20));

}

void Health::decHealth()
{
    --health;
    //生命减少后更新内容
    setPlainText(QString("生命：")+ QString::number(health));
}

int Health::getHealth()
{
    return  health;
}
