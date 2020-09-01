#ifndef BUTTON_H
#define BUTTON_H
#include<QGraphicsItem>
#include<QGraphicsRectItem>
#include <QGraphicsTextItem>
#include<QGraphicsScene>
#include<QGraphicsSceneMouseEvent>
#include<QGraphicsSceneHoverEvent>
#include <QObject>

class Button:public QObject, public QGraphicsRectItem //Signal slot wont work without QObject.
{
    Q_OBJECT

public:
    //constructors
    Button(QString name,QGraphicsItem *parent=NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();


private:
    QGraphicsTextItem *text1;
};
#endif // BUTTON_H
