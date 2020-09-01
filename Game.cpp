#include "Game.h"
#include "Enemy.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include <QBrush>
#include <QImage>
#include "Button.h"
#include<QString>

//#include <QMediaPlayer>
Game::Game(QWidget *parent)
{
    //create  scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    //setBackgroundBrush(QBrush(QImage(":/images/bgn2.jpg")));
    //view not needed as it is already inherited.
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //    WHEN QGRAPHICSVIEW WAS NOT INHERITED.
    //    QGraphicsScene* scene = new QGraphicsScene();
    //    scene->setSceneRect(0,0,800,600);
    //    QGraphicsView *view = new QGraphicsView(scene);
    //    view->setBackgroundBrush(QBrush(Qt::white));
    //    view->show();
    //    QPainter objPainter(this);

}

void Game::display()
{
    //Title
    QGraphicsTextItem *text = new QGraphicsTextItem(QString("SKY FIGHTERS"));

    QFont titleFont("comic sans",50);
    text->setFont(titleFont);
    text->setDefaultTextColor(Qt::white);
    text->setPos(170,150);
    scene->addItem(text);



    //play
    Button *playButton=new Button(QString("PLAY"));
    int pxPos=this->width()/2 - playButton->boundingRect().width()/2;
    int pyPos=275;
    playButton->setPos(pxPos,pyPos);
    connect(playButton, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //quit
    Button *quitButton=new Button(QString("QUIT"));
    int qxPos=this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos=350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

}

void Game::display2() ///game over window.
{
      scene->clear();
      delete scene;
      //create  scene
      scene = new QGraphicsScene();
      scene->setSceneRect(0,0,800,600);
      setBackgroundBrush(QBrush(QImage("fuckk")));
      //view not needed as it is already inherited.
      setScene(scene);
      setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      setFixedSize(800,600);

    //Title
    QGraphicsTextItem *text = new QGraphicsTextItem(QString("GAME OVER"));
    //text->setPlainText(QString("SKY FIGHTERS"));
    QFont titleFont("comic sans",50);
    text->setFont(titleFont);
    text->setDefaultTextColor(Qt::white);
    text->setPos(170,150);
    scene->addItem(text);

    //Replay
    Button *playButton=new Button(QString("REPLAY"));
    int pxPos=this->width()/2 - playButton->boundingRect().width()/2;
    int pyPos=275;
    playButton->setPos(pxPos,pyPos);
    connect(playButton, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //quit
    Button *quitButton=new Button(QString("QUIT"));
    int qxPos=this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos=350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::start()
{
    scene->clear();

    //create  scene
    scene = new QGraphicsScene();
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
    timer->start(1100);


}
