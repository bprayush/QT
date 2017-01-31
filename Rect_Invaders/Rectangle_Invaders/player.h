#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QEvent>
#include <QObject>
#include <QMediaPlayer>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int playerSpeed;
    QMediaPlayer *media;
public:
    void keyPressEvent(QKeyEvent *event);
    Player();
public slots:
    void spawnEnemy();
};

#endif // PLAYER_H
