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
class Game:public QGraphicsView{
public:
    Game(QWidget * parent = 0);
    Score * score;
    Health * health;
};

#endif // GAME_H
