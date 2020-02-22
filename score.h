#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem{

public:
    Score(QGraphicsItem * parent = 0);

    //加分
    void incScore();

    //获取分数
    int getScore();

private:
    int score;
};


#endif // SCORE_H
