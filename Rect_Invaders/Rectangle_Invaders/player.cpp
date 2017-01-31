#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
//#include <QDebug>
#include "bullet.h"
#include "enemy.h"
#include <QMediaPlayer>

void Player::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "Player debug?";

    if(event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0)
            setPos(x()-playerSpeed,y());
    }
    if(event->key() == Qt::Key_Right)
    {
        if(pos().x() < 800)
            setPos(x()+playerSpeed, y());
    }
    if(event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(this->x()+22, this->y());
       // qDebug() << "Value of X:" << x() << " Value of y(): " << y();
        scene()->addItem(bullet);

        //PLAY THE LASER SOUND WHEN THE SPACEBAR IS PRESSED
        if(media->state() == QMediaPlayer::PlayingState)
        {
            media->setPosition(0);
        }
        else if(media->state() == QMediaPlayer::StoppedState)
        {
            media->play();
        }
    }

}

Player::Player()
{
    playerSpeed = 20;
    media = new QMediaPlayer();
    media->setMedia(QUrl("qrc:/sounds/laser.wav"));
    media->setVolume(10);
}

void Player::spawnEnemy()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
