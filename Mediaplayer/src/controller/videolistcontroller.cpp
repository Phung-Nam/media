#include "videolistcontroller.h"
#include "loghelper.h"

VideoListController* VideoListController::m_instance = nullptr;

VideoListController::VideoListController()
    :m_initialized(false)
{
    LOG_INFO;
}

VideoListController::~VideoListController()
{
    LOG_INFO;
}

VideoListController *VideoListController::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new VideoListController();
    }
    return m_instance;
}

void VideoListController::initialize(QQmlContext *context)
{
    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
//        context->setContextProperty("MLIST_CTRL", this);



    }

}
