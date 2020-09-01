#include "Button.h"
#include<QBrush>
#include <QGraphicsTextItem>
#include<QFont>
Button::Button(QString name,QGraphicsItem *parent):QObject(),QGraphicsRectItem(parent)
{
    //draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    //text on button
    text1 = new QGraphicsTextItem(name,this);
    int xpos = rect().width()/2-text1->boundingRect().width()/2;
    int ypos = rect().height()/2-text1->boundingRect().height()/2;
    text1->setPos(xpos-10,ypos-5);
    text1->setDefaultTextColor(Qt::white);
    text1->setFont(QFont("times",16));

    //allow responding to hover events
    setAcceptHoverEvents(true);


}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
