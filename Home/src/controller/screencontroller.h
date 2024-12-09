#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <QStack>
#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "screenmodel.h"
#include <QDBusMessage>
#include <QDBusConnection>
#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/id3v2tag.h>
#include <taglib/mpegfile.h>
#include <taglib/id3v2frame.h>
#include <taglib/id3v2header.h>
#include <taglib/attachedpictureframe.h>
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

    // screen transition
    Q_INVOKABLE void pushScreen(int screenId);
    Q_INVOKABLE void replaceScreen(int screenId);
    Q_INVOKABLE void popScreen();
    Q_INVOKABLE void popToRoot();
    void reloadScreen();

    Q_INVOKABLE void broadcastDbusSignal(int n);


    QString getAlbumArt(QUrl url);
    Q_INVOKABLE void loadMediaList();

private:
    static ScreenController *m_instance;
    bool m_initialized;


    ScreenModel m_model;
    QStack<int> m_screenStack;
    QQmlApplicationEngine *m_engine;
signals:
    void signalsHome(QString songTitle, QString artistName, QString coverArt);
public slots:
    void onSlotHome(QString songTitle, QString artistName, QString coverArt);
};

#endif // SCREENCONTROLLER_H
