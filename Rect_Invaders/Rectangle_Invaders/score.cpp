#include "score.h"
#include <QFont>
#include "game.h"

extern Game *game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //INITIALISE THE SCORE TO ZERO
    score = 0;

    //SET TEXT ON THE SCREEN
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
    if(score%10 == 0)
    {
        game->jumpScare();
    }
}

int Score::getScore()
{
    return score;
}
