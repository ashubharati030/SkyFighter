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
        bullet->setPos(x()+50,y());
        scene()->addItem(bullet);
    }
}

void Player::spawn(){
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
