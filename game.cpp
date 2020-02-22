#include "game.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

Game::Game()
{
    //创建场景
    scene = new QGraphicsScene();

    //加入图形项
    player = new Player();
    //    player->setRect(0,0,150,100);
    player->setPixmap(QPixmap(":/image/res/image/player.png"));

    //把图形项加入到场景
    scene->addItem(player);

    //设置图形可以获取焦点
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();  //设置自动获取焦点,打开界面就可以直接响应键盘，不用鼠标先选取

    //创建视图
    view = new QGraphicsView(scene);
    //给是视口添加 背景（也就是游戏背景，当前场景和视口大小是一样的，设置任何一个都可以
    view->setBackgroundBrush(QPixmap(":/image/res/image/BackImage_1.jpg"));

    //禁用使用水平和垂直滚动条
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //设置场景和视口大小
    view->setFixedSize(1000,600);
    scene->setSceneRect(0,0,1000,600);

    //设置玩家位置(靠左,中间位置)
    //    player->setPos(5,view->height()/2-player->rect().height()/2);
    player->setPos(5,view->height()/2-player->boundingRect().height()/2);

    //设置分数
    score = new Score();
    scene->addItem(score);

    //创建生命值
    health = new Health();
    scene->addItem(health);
    health->setPos(score->x(),score->y()+30);

    //创建定时器，定时生成敌人
    QTimer * timer = new QTimer();
    QObject::connect(timer,&QTimer::timeout,player,&Player::creatEnemy);
    timer->start(2000);

    //加载背景音乐
    QMediaPlayer * bkGroundMus = new QMediaPlayer();
    //使用播放列表实现循环播放
    QMediaPlaylist * bkGroundMusList = new QMediaPlaylist;
    bkGroundMusList->addMedia(QUrl("qrc:/sounds/res/sounds/BkGround.mp3"));
    bkGroundMusList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    bkGroundMus->setPlaylist(bkGroundMusList);
    bkGroundMus->play();
}

void Game::show()
{
    view->show();
}
