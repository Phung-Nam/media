#include <QGuiApplication>
#include "appengine.h"
#include <QDebug>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    AppEngine::getInstance()->initialize(&app);
    return app.exec();
}
