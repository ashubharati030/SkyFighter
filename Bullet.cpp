#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include <QDebug>

extern Game * game; //there is an external global obj ptr called game , here used for increasing score.****

Bullet::Bullet(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/bullt.png"));
    setPos(x(),y());
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //if bullet collides then delete them both
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid (* (colliding_items[i])) == typeid (Enemy))
        {
            //increase the score
            game->score->increase();
            //remove both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete from heap
            delete colliding_items[i];
            delete this;
        }
    }

    setPos(x(),y()-10);
    if(pos().y()  < 0 )
    {
                scene()->removeItem(this);
                delete this;
               // qDebug() <<"bullet deleted";
    }
}


