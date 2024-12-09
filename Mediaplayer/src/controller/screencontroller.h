#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <QStack>
#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "screenmodel.h"
#include <QDBusConnection>
#include <QDBusMessage>
class ScreenController : public QObject
{
    Q_OBJECT

private:
    explicit ScreenController(QObject *parent = nullptr);

public:
    ~ScreenController();

    // singleton pattern
    static ScreenController *getInstance();

    // initialize controller
    void initialize(QQmlContext *context);
    void initializeScreen(QQmlApplicationEngine *engine);
    void reloadScreen();
    // screen transition
    Q_INVOKABLE void pushScreen(int screenId);
    Q_INVOKABLE void replaceScreen(int screenId);
    Q_INVOKABLE void popScreen();
    Q_INVOKABLE void popToRoot();
    Q_INVOKABLE void broadcastDbusSignalButonHome(QString songTitle, QString artistName, QString coverArt);



    QQmlApplicationEngine *getEngine() const;

    bool getScreenMusic() const;

private:

    static ScreenController *m_instance;
    bool m_initialized;

    ScreenModel m_model;
    QStack<int> m_screenStack;
    QQmlApplicationEngine *m_engine;

    bool screenMusic = false; // man hinh music chưa bật
    bool screenVideo = false;


public slots:
    void onChangeScreenFromHome(int n);
signals:
    void visibleMedia();
};

#endif // SCREENCONTROLLER_H










