#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem * parent):QGraphicsTextItem(parent)
{
    //分数默认为0；
    score = 0;

    //设置内容和字体
    setPlainText(QString("分数：")+ QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("宋体",20));

}

void Score::incScore()
{
    ++score;
    //加分后更新内容
    setPlainText(QString("分数：")+ QString::number(score));
}

int Score::getScore()
{
    return  score;
}
