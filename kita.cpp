#include "kita.h"
#include <vector>
#include <QPixmap>

Kita::Kita(QObject *parent) : QObject(parent)
{
    std::vector<std::pair<QPixmap,int>> s1;
    std::vector<std::pair<QPixmap,int>> s2;
    s1.reserve(4);
    s2.reserve(4);
    QPixmap left_smile(QString(":/res/kita_left_smile.png"));
    QPixmap left_normal(QString(":/res/kita_left_normal.png"));
    QPixmap middle_smile(QString(":/res/kita_middle_smile.png"));
    QPixmap middle_normal(QString(":/res/kita_middle_normal.png"));
    QPixmap right_smile(QString(":/res/kita_right_smile.png"));
    QPixmap right_normal(QString(":/res/kita_right_normal.png"));
    s1.push_back(std::make_pair(left_smile,15));
    s1.push_back(std::make_pair(middle_smile,10));
    s1.push_back(std::make_pair(right_smile,15));
    s1.push_back(std::make_pair(middle_smile,10));
    this->smileAnimation.initAnimation(std::move(s1));
    s2.push_back(std::make_pair(left_normal,15));
    s2.push_back(std::make_pair(middle_normal,10));
    s2.push_back(std::make_pair(right_normal,15));
    s2.push_back(std::make_pair(middle_normal,10));
    this->normalAnimation.initAnimation(std::move(s2));

    this->curAnimation=&this->normalAnimation;
    this->isKitaing=false;
    this->kitaingLeftFrames=this->kitaMaxFrames=45;
}

void Kita::update()
{
    this->smileAnimation.update();
    this->normalAnimation.update();
    if(this->isKitaing)
    {
        this->kitaingLeftFrames--;
        if(this->kitaingLeftFrames==0)
        {
            this->changeMode();
        }
    }
}

void Kita::changeMode()
{
    this->isKitaing=!this->isKitaing;
    if(this->isKitaing)
    {
        this->kitaingLeftFrames=this->kitaMaxFrames;
        this->curAnimation=&this->smileAnimation;
    }
    else
    {
        this->curAnimation=&this->normalAnimation;
    }
}
