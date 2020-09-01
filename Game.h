#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "Player.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include "Score.h"
#include "Health.h"
class Game:public QGraphicsView //QGview inherits QObject by default.
{
    Q_OBJECT //when signal slot is used.
public:
    Game(QWidget * parent = 0);
    void display();
    void display2();
    QGraphicsScene *scene;
    Score * score;
    Health * health;

public slots:
    void  start();
};

#endif // GAME_H
