#include "gameover.h"
#include <QFont>

GameOver::GameOver(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setPlainText(QString("Game Over!"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 30));
}


