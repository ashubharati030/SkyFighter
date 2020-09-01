#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

#include <QDebug>
Player::Player(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/player_edit.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left)
    {
        if(pos().x() > 0)
        setPos(x()-10,y());
    }
    else if(event->key()==Qt::Key_Right)
    {
        if(pos().x()+100 < 800)
        setPos(x()+10,y());
    }

    else if(event->key()==Qt::Key_Up)
    {
        //create a bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x()+75,y()-10);
        Bullet *bullet1 = new Bullet();
        bullet1->setPos(x()+40,y()-10);
        scene()->addItem(bullet);
        scene()->addItem(bullet1);
    }
}

void Player::spawn(){
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
