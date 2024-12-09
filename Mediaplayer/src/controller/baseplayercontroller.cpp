#include "baseplayercontroller.h"
#include "loghelper.h"
#include "videolistcontroller.h"
BasePlayerController::~BasePlayerController()
{

}

void BasePlayerController::initialize(QQmlContext *context)
{
    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        //        context->setContextProperty("MPLAYER_CTRL", this);
        //        context->setContextProperty("MPLAYER_MODEL", &m_model);
        context->setContextProperty("PLAY_VIDEO",VideoPlayerController::getInstance());
    }
}
