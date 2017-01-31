#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
//#include <QDebug>
#include <QList>
#include "enemy.h"
#include "game.h"

extern Game *game;

Bullet::Bullet(): QObject(), QGraphicsPixmapItem()
{
    //DRAW THE GRAPHICS
    setPixmap(QPixmap(":/sprites/Sprites/bullet.png"));

    //INSTANTIATE THE TIMER
    QTimer *timer = new QTimer();
    //CONNECT THE TIMER'S TIMEOUT SIGNAL TO MOVE() OF BULLET
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //SET TIMER IN MILISECOND
    timer->start(20);
}

void Bullet::move()
{
    //QLIST OF ITEMS THAT COLLIDEWITH THE BULLET
    QList <QGraphicsItem *> colliding_items = collidingItems();

    //SEARCH FOR THE COLLIDING ITEMS
    for(int i=0, n = colliding_items.size(); i<n; ++i)
    {
        //IF THE COLLIDING ITEM FOUND
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //INCREASE SCORE IF BULLET COLLIDES ENEMY
            game->score->increase();

            //DELETE ENEMY AND OBJECT
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //MOVE BULLET UP
    setPos(x(), y()-10);
    //qDebug() << y();
    if(pos().y() < -10)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }

}
