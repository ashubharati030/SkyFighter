#include "Game.h"
#include "Enemy.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include <QBrush>
#include <QImage>

//#include <QMediaPlayer>
Game::Game(QWidget *parent)
{
    //create  scene
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/bgn2.jpg")));
    //view not needed as it is already inherited.
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //create the player
    Player *player = new Player();
    player->setPos(350,500);
    //set player to current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //add player to scene
    scene->addItem(player);

    //create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setY(health->y()+25);
    scene->addItem(health);

    //Spawn/create enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1500);

    //QMediaPlayer

    show();
}
