#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <cstdlib>  //rand func.
#include "Game.h"

extern Game * game; //used to decrease health.

#include <QDebug>
Enemy::Enemy(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    int r = rand() % 700;
    setPos(r,0);

    setPixmap(QPixmap(":/images/enemy_edit.png"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    setPos(x(),y()+5);

    if(pos().y() == 600 )
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        //qDebug() <<"enemy deleted";
    }
}
