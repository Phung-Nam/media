#ifndef VIDEOPLAYERCONTROLLER_H
#define VIDEOPLAYERCONTROLLER_H

#include "baseplayercontroller.h"
#include "baseplaybackmodel.h"
#include <QString>
#include <QDir>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaMetaData>
#include <QStandardPaths>
#include <QDirIterator>
#include <QAbstractVideoSurface>
#include <cstdio>
#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/id3v2tag.h>
#include <taglib/mpegfile.h>
#include <taglib/id3v2frame.h>
#include <taglib/id3v2header.h>
#include <taglib/attachedpictureframe.h>

class VideoPlayerController : public BasePlayerController
{
    Q_OBJECT
public:
    VideoPlayerController();
    ~VideoPlayerController();
    static VideoPlayerController* getInstance();

    QAbstractVideoSurface *videoSurface() const;
    void setVideoSurface(QAbstractVideoSurface *surface);

    QMediaPlayer *getPlayer();

    void open();
    Q_INVOKABLE void getVideoFile(const QList<QUrl> &urls);
    Q_INVOKABLE void pauseVideo();
    Q_INVOKABLE void resumeVideo();
    Q_INVOKABLE void durationVideo();
    Q_INVOKABLE void volumeVideo(int volume);
private:
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ videoSurface WRITE setVideoSurface NOTIFY videoSurfaceChanged)
    QString m_VideoFile;


    QMediaPlayer *player = new QMediaPlayer;
    QMediaPlaylist *playlist = new QMediaPlaylist;
    QAbstractVideoSurface *m_surface;
    QMediaPlayer::State mCurrentStatus;
signals:
    void videoSurfaceChanged(QAbstractVideoSurface* videoSurface);
public slots:
    void requestPlay();
};

#endif // VIDEOPLAYERCONTROLLER_H
