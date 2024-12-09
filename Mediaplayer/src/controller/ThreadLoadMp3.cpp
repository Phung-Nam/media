#include "ThreadLoadMp3.h"
#include "musiclistcontroller.h"
#include "loghelper.h"
#include "screencontroller.h"
#include "appdefines.h"
 ThreadLoadMp3* ThreadLoadMp3::m_Instance = nullptr;
ThreadLoadMp3 *ThreadLoadMp3::getInstance()
{
    if(m_Instance == nullptr)
    {
        m_Instance = new ThreadLoadMp3();
    }
    return  m_Instance;
}

ThreadLoadMp3::ThreadLoadMp3()
{

}

void ThreadLoadMp3::run()
{
    MusicListController::getInstance() -> getFolerAndMp3(mRootDirectoryPath);
    ScreenController::getInstance()->replaceScreen(AppEnums::SCREEN_ID_MUSIC_PLAYER);
}

void ThreadLoadMp3::getFolderAndMp3_Thread(QString rootDirectoryPath)
{
    LOG_INFO << "nam123455 getFolderAndMp3_Thread" ;
    mRootDirectoryPath = rootDirectoryPath;
    start();

}
