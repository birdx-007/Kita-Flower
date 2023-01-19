#include "gamewindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QScreen *screen=qApp->primaryScreen();
    qreal screenRatio=screen->logicalDotsPerInch()/96.0;
    GameWindow w;
    w.screenRatio=screenRatio;
    w.resize(screenRatio*800,screenRatio*600);
    w.show();
    return a.exec();
}
