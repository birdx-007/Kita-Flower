#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QIcon>

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    //只能最小化
    this->setWindowFlags(this->windowFlags()&(~Qt::WindowMinMaxButtonsHint|Qt::WindowMinimizeButtonHint));
    this->setWindowIcon(QIcon(":/res/icon.png"));
    this->background.load(QString(":/res/background.png"));
    this->singleKitaEffect.setSource(QUrl::fromLocalFile(":/res/kita_single.wav"));
    this->doubleKitaEffect.setSource(QUrl::fromLocalFile(":/res/kita_double.wav"));
    this->mousePressedTimes=0;
    this->frame=0;
    this->timer=new QTimer(this);
    this->timer->setInterval(20);
    connect(this->timer,&QTimer::timeout,[=]()
    {
        this->frame++;
        this->updateData();//数据处理
        this->update();//显示
        this->setWindowTitle(QString("frame=%1 kitaIdx=%2")
                             .arg(this->frame)
                             .arg(this->kita.curAnimation->getCurSpriteIdx())
                             );
        this->playSound();//播放声音
    });
    this->timer->start();
}

GameWindow::~GameWindow()
{
    delete this->timer;
    delete ui;
}

void GameWindow::updateData()
{
    this->kita.update();
}

void GameWindow::playSound()
{

}

void GameWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(0,0,800*this->screenRatio,600*this->screenRatio,this->background);
    painter.drawPixmap(200*this->screenRatio,60*this->screenRatio,this->kita.curAnimation->getCurSprite().width()*2*screenRatio,this->kita.curAnimation->getCurSprite().height()*2*screenRatio,this->kita.curAnimation->getCurSprite());
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if(this->mousePressedTimes>2)
    {
        this->mousePressedTimes=0;
    }
    this->mousePressedTimes++;
    if(this->mousePressedTimes==1)
    {
        QTimer::singleShot(300,this,SLOT(detectClickTimes()));
    }
}

void GameWindow::detectClickTimes()
{
    if(this->mousePressedTimes==1)
    {
        this->singleKitaEffect.play();
    }
    else
    {
        this->doubleKitaEffect.play();
    }
    this->mousePressedTimes=0;
    if(!this->kita.isKitaing)
    {
        this->kita.changeMode();
    }
}

