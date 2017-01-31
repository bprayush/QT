#include "enemy.h"
#include <stdlib.h>
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"
#include <time.h>

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{   srand(time(NULL));
    xPos = rand()%700;
    yPos = -5;
    enemySpeed = 5;

    setPixmap(QPixmap(":/sprites/Sprites/enemy.png"));
    setPos(xPos, yPos);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(40);
}

void Enemy::move()
{
    setPos(x(), y()+enemySpeed);
    if(pos().y() > 600)
    {
        game->healthBar->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
