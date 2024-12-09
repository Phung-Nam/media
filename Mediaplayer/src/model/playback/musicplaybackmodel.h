#ifndef MUSICPLAYERMODEL_H
#define MUSICPLAYERMODEL_H

#include <QObject>
#include "baseplaybackmodel.h"
#include <QQmlContext>
#include "musiclistmodel.h"
#include <id3v2tag.h>
#include <mpegfile.h>
#include <id3v2frame.h>
#include <id3v2header.h>
#include <attachedpictureframe.h>
#include <cstdio>
#include <QDebug>
#include <fileref.h>
#include <tag.h>
#include<QDir>
#include<QStandardPaths>


// handle properties display on music: current song title, current album name, current artist name, coverart
class MusicPlaybackModel : public BasePlaybackModel
{
    Q_OBJECT

    Q_PROPERTY(QStringList title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QStringList album READ album WRITE setAlbum NOTIFY albumChanged)
    Q_PROPERTY(QStringList artist READ artist WRITE setArtist NOTIFY artistChanged)
    Q_PROPERTY(QStringList source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QStringList albumArt READ albumArt WRITE setAlbumArt NOTIFY albumArtChanged)
    
    MusicPlaybackModel();

private:
    static MusicPlaybackModel* m_inStance ;

    QStringList m_title;

    QStringList m_album;

    QStringList m_artist;

    QStringList m_source;

    QStringList m_albumArt;



public:
    QList<QUrl> urls;
    void clearPlayback();

    static MusicPlaybackModel* getInStance();
    
    
    QString getAlbumArt(QUrl url);
    Q_INVOKABLE QString getTitle(int index);
    Q_INVOKABLE QString getAlbum(int index);
    Q_INVOKABLE QString getArtist(int index);
//    Q_INVOKABLE QString getSource(int index);
    Q_INVOKABLE QString getAlbumArt(int index);
    Q_INVOKABLE void loadMediaList();


    QStringList albumArt() const;

    QStringList title() const;

    QStringList album() const;

    QStringList artist() const;

    QStringList source() const;


public slots:
    void setTitle(QStringList title);

    void setAlbum(QStringList album);

    void setArtist(QStringList artist);

    void setSource(QStringList source);

    void setAlbumArt(QStringList albumArt);

signals:

    void titleChanged(QStringList title);
    void albumChanged(QStringList album);
    void artistChanged(QStringList artist);
    void sourceChanged(QStringList source);
    void albumArtChanged(QStringList albumArt);
};

#endif // MUSICPLAYERMODEL_H
