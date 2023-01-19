#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "kita.h"
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QString>
#include <QUrl>
#include <QSound>
#include <QSoundEffect>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void updateData();
    void playSound();
    void paintEvent(QPaintEvent*event);
    //void keyPressEvent(QKeyEvent *event);
    //void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    qreal screenRatio;

private:
    Ui::GameWindow *ui;
    QTimer* timer;
    long long frame;
    short mousePressedTimes;
    QPixmap background;
    QSoundEffect singleKitaEffect;
    QSoundEffect doubleKitaEffect;
    Kita kita;

private slots:
    void detectClickTimes();
};
#endif // GAMEWINDOW_H
