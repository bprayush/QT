#include "health.h"
#include <QFont>
#include <game.h>
#include <QTimer>

extern Game *game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //INITIALISE HEALTH TO 3
    health = 3;

    setPlainText(QString("Health: ")+QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ")+QString::number(health));

    if(health <= 0)
    {
        gameOver = new GameOver();
        game->scene->addItem(gameOver);
        gameOver->setPos(300,300);

        endTimer = new QTimer();

        QObject::connect(endTimer, SIGNAL(timeout()), this, SLOT(wait()));
        endTimer->start(500);

    }


}

int Health::getHealth()
{
    return health;
}

void Health::wait()
{
    game->endGame();
}
