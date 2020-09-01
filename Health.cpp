#include "Health.h"
#include <QFont>
#include "Game.h"

//extern Game * game;

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent) //QGTxtItem is child class of QGItem.
{
    health = 3;

    setPlainText(QString("Health :") + QString::number(health) );
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}
void Health::decrease()
{
    health--;

    setPlainText(QString("Health :") + QString::number(health) );
}
int Health::getHealth()
{
    return health;
}
