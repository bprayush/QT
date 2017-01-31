#include "game.h"
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
//#include <QDebug>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QImage>

Game::Game(QWidget *parent): QGraphicsView(parent){


    //CREATE A SCENE
    scene = new QGraphicsScene();
    //SET SCENE SIZE
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/sprites/Sprites/bg5.jpg")));

    //SET SCENE
    setScene(scene);

    //LOCK THE SCROLLS
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    //create a rect item
    rect = new Player();
    rect->setPixmap(QPixmap(":/sprites/Sprites/player.png"));
    rect->setTransformOriginPoint(27, 32);

    //set rect player postions
    rect->setPos(width()/2, height()-80);

    //SET RECTANGLE TO FOCUSABLE
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    //FOCUS ON RECTANGLE
    rect->setFocus();

    //ADD RECT TO THE SCENE
    scene->addItem(rect);

    //CREATE SCORE
    score = new Score();
    scene->addItem(score);

    //CREATE HEALTH
    healthBar = new Health();
    scene->addItem(healthBar);
    healthBar->setPos(healthBar->x(), score->pos().y() + 20);

    //TIMER TO SPAWN ENEMY
    QTimer *enemyTimer = new QTimer();
    QObject::connect(enemyTimer, SIGNAL(timeout()), rect, SLOT(spawnEnemy()));
    enemyTimer->start(1400);

    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/gcmusic.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    //PLAY BG MUSIC
    mediaPlayer = new QMediaPlayer();
    mediaPlayer->setMedia(playlist);
    mediaPlayer->play();
    mediaPlayer->setVolume(60);

    show();

}


void Game::endGame()
{
    delete this;
}

void Game::jumpScare()
{
    mediaPlayer->setMedia(QUrl("qrc:/sounds/screams.wav"));
    mediaPlayer->play();
    mediaPlayer->setVolume(100);
    scene->setBackgroundBrush(QBrush(QImage(":/sprites/Sprites/jumpscare.jpg")));

    QTimer::singleShot(2500, this, SLOT(reset()));
}

void Game::reset()
{
    scene->setBackgroundBrush(QBrush(QImage(":/sprites/Sprites/bg5.jpg")));
    mediaPlayer->setMedia(playlist);
    mediaPlayer->play();
    mediaPlayer->setVolume(60);
}


