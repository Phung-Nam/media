#include "videoplayercontroller.h"
#include "videoplaybackmodel.h"

VideoPlayerController::VideoPlayerController()
{
    mPlaybackModel = new VideoPlaybackModel();
    m_surface = nullptr;
    player->setPlaylist(playlist);
    open();
}

VideoPlayerController::~VideoPlayerController()
{
    m_surface = nullptr;
    player->setVideoOutput(m_surface);
}
VideoPlayerController *VideoPlayerController::getInstance()
{
    static VideoPlayerController instance;
    return &instance;
}


QAbstractVideoSurface *VideoPlayerController::videoSurface() const
{
    return m_surface;
}

void VideoPlayerController::open()
{
    QDir directory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation)[0]);
    QFileInfoList videos = directory.entryInfoList(QStringList() << "*.mp4",QDir::Files);
    QList<QUrl> urls;
    for(int i = 0; i < videos.length(); i++)
    {
        urls.append(QUrl::fromLocalFile(videos[i].absoluteFilePath()));
    }
    getVideoFile(urls);

}


void VideoPlayerController::setVideoSurface(QAbstractVideoSurface *surface)
{
    if(m_surface != surface)
    {
        m_surface = surface;
        player->setVideoOutput(m_surface);
    }
}

void VideoPlayerController::requestPlay()
{
    qDebug()<< "c++: nam test video";
    player->play();
}

void VideoPlayerController::getVideoFile(const QList<QUrl> &urls)
{
    for (auto &url:urls)
    {
        playlist->addMedia(url);
    }
}

void VideoPlayerController::pauseVideo()
{
    player->pause();
}

void VideoPlayerController::resumeVideo()
{
    player->play();
}

void VideoPlayerController::durationVideo()
{
    player->duration();
}

void VideoPlayerController::volumeVideo(int volume)
{
    player->setVolume(volume);
}




















