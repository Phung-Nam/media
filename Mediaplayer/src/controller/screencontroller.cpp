#include "screencontroller.h"
#include "appdefines.h"
#include "loghelper.h"
#include"videoplayercontroller.h"

ScreenController* ScreenController::m_instance = nullptr;

ScreenController::ScreenController(QObject *parent)
    : QObject(parent)
    , m_initialized(false)
    , m_engine(nullptr)
{
    LOG_INFO;

    // connect with test signal from other process
    QDBusConnection::sessionBus().connect("",                           // service name, could be empty
                                          "/vn/com/fsoft/appInterface", // object path, could be empty
                                          "vn.com.fsoft.appInterface",  // service interface
                                          "screen",           // method name
                                          this, SLOT(onChangeScreenFromHome(int)));
}

ScreenController::~ScreenController()
{
    LOG_INFO;
    m_engine = nullptr;
}

ScreenController *ScreenController::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new ScreenController();
    }

    return m_instance;
}

void ScreenController::initialize(QQmlContext *context)
{
    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        context->setContextProperty("SCREEN_CTRL", this);
        context->setContextProperty("SCREEN_MODEL", &m_model);
    }
}

void ScreenController::initializeScreen(QQmlApplicationEngine *engine)
{
    LOG_INFO;
    if(m_engine == nullptr)
    {
        m_engine = engine;

        // load main qml
        m_engine->load(QUrl(QStringLiteral(MAIN_QML)));

        // show deafault screen
        pushScreen(AppEnums::SCREEN_ID_MUSIC_PLAYER);
        //pushScreen(AppEnums::SCREEN_ID_VIDEO_PLAYER);
    }
}

void ScreenController::pushScreen(int screenId)
{
    LOG_INFO << screenId;
    m_screenStack.push(screenId);
    reloadScreen();
}

void ScreenController::replaceScreen(int screenId)
{
    LOG_INFO << screenId;
    if(!m_screenStack.isEmpty())
    {
        m_screenStack.pop();
    }
    m_screenStack.push(screenId);
    reloadScreen();
}

void ScreenController::popScreen()
{
    LOG_INFO << m_screenStack.count();
    if(m_screenStack.count() > 1)
    {
        m_screenStack.pop();
        reloadScreen();
    }
}

void ScreenController::popToRoot()
{
    LOG_INFO << m_screenStack.count();
    while(m_screenStack.count() > 1)
    {
        m_screenStack.pop();
    }
    reloadScreen();
}

void ScreenController::broadcastDbusSignalButonHome(QString songTitle, QString artistName, QString coverArt)
{
    qDebug() << " broadcastDbusSignalButonHome_____nam";

    // 1. create a dbus signal
    QDBusMessage msg = QDBusMessage::createSignal(
                "/",   // object path
                "a.home",    // service interface
                "home"                               // method name
                );

    // 2. append input arguments
    msg << songTitle << artistName << coverArt ;

    // 3. broadcast signal (using session or system bus)
    QDBusConnection::sessionBus().send(msg);
}

QQmlApplicationEngine *ScreenController::getEngine() const
{
    return m_engine;
}

bool ScreenController::getScreenMusic() const
{
    return screenMusic;
}



void ScreenController::reloadScreen()
{
    if(!m_screenStack.isEmpty())
    {
        QString screenName = ScreenNameMap.value(m_screenStack.top());
        m_model.setCurrentScreen(screenName);
        // reload screen on qml
        if((m_engine != nullptr) && (m_engine->rootObjects().count() > 0))
        {
            QMetaObject::invokeMethod(m_engine->rootObjects().at(0), "reloadScreen");
        }
    }
}

void ScreenController::onChangeScreenFromHome(int n)
{    
    qDebug()<< " da vao dc slot media";
    if((1 == n) && (screenMusic == false) )
    {
        replaceScreen(AppEnums::SCREEN_ID_MUSIC_PLAYER);
        screenMusic = true;
        screenVideo = false;
    }
    else if((2==n) && (screenVideo == false))
    {
        replaceScreen(AppEnums::SCREEN_ID_VIDEO_PLAYER);
        screenVideo = true;
        screenMusic = false;
    }
    emit visibleMedia();
}


