#include "appengine.h"
#include "screencontroller.h"
#include "baseplayercontroller.h"
#include "musicplayercontroller.h"
#include "videoplayercontroller.h"
#include "musiclistcontroller.h"
#include "appdefines.h"
#include "loghelper.h"

AppEngine* AppEngine::m_instance = nullptr;

AppEngine::AppEngine(QObject *parent)
    : QObject(parent)
    , m_initialized(false)
    , m_app(nullptr)
{
    LOG_INFO;
}

AppEngine::~AppEngine()
{
    LOG_INFO;
    m_app = nullptr;
}

AppEngine *AppEngine::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new AppEngine();
    }

    return m_instance;
}

void AppEngine::initialize(QGuiApplication *app)
{
    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        m_app = app;

        // init app
        registerQmlObjects();
        createControllers();
        initControllers();
        initScreens();
    }
}

void AppEngine::registerQmlObjects()
{
    LOG_INFO << " => Start";

    qmlRegisterType<AppEnums>("AppEnums1", 1, 0, "AppEnums1");
    qmlRegisterType<MusicPlayerController>("MusicPlayerController", 1, 0, "MusicPlayerController");

    LOG_INFO << " => End";
}

void AppEngine::createControllers()
{
    LOG_INFO << " => Start";

    ScreenController::getInstance();
    MusicListController::getInstance();
    MusicPlayerController::getInstance();
    VideoPlayerController::getInstance();
    LOG_INFO << " => End";
}

void AppEngine::initControllers()
{
    LOG_INFO << " => Start";

    ScreenController::getInstance()->initialize(m_engine.rootContext());
    MusicPlayerController::getInstance()->initialize(m_engine.rootContext());
    VideoPlayerController::getInstance()->initialize(m_engine.rootContext());
    MusicListController::getInstance()->initialize(m_engine.rootContext());

    LOG_INFO << " => End";
}

void AppEngine::initScreens()
{
    LOG_INFO << " => Start";

    ScreenController::getInstance()->initializeScreen(&m_engine);

    LOG_INFO << " => End";
}
