#include <QGuiApplication>
#include "appengine.h"
#include <QString>
#include <QApplication>

//QString MuSicfilePath;
//QString VideofilePath;

int main(int argc, char *argv[])
{

    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);
    AppEngine::getInstance()->initialize(&app);
    return app.exec();
}
