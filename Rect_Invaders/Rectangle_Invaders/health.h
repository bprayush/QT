#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>
#include "gameover.h"
#include <QObject>


class Health: public QGraphicsTextItem
{
    Q_OBJECT

public:
    Health(QGraphicsItem *parent = 0);
    int getHealth();
    void decrease();

private:
    int health;
    GameOver *gameOver;
    QTimer *endTimer;

public slots:
    void wait();
};

#endif // HEALTH_H
