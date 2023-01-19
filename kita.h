#ifndef KITA_H
#define KITA_H

#include "frameanimation.h"
#include <QObject>
#include <QPainter>
#include <QString>
#include <QUrl>
#include <QSound>
#include <QSoundEffect>
#include <QMediaPlayer>

class Kita : public QObject
{
    Q_OBJECT
public:
    explicit Kita(QObject *parent = nullptr);
    void update();
    void changeMode();
    FrameAnimation* curAnimation;
    bool isKitaing;
    int kitaMaxFrames;
private:
    FrameAnimation normalAnimation;
    FrameAnimation smileAnimation;
    int kitaingLeftFrames;

signals:

};

#endif // KITA_H
