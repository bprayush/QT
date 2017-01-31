#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "player.h"
#include "score.h"
#include "health.h"
#include <QObject>

class Game:  public QGraphicsView
{
   Q_OBJECT

public:
    Game(QWidget * parent=0);
    QGraphicsScene *scene;
    Player *rect;
    Score *score;
    Health *healthBar;
    void endGame();
    void jumpScare();

private:
    QMediaPlayer *mediaPlayer;
    QMediaPlaylist *playlist;
    void startScare();

public slots:
    void reset();

};

#endif // GAME_H
