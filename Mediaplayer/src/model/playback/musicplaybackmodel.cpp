#include "musicplaybackmodel.h"

MusicPlaybackModel* MusicPlaybackModel::m_inStance = nullptr;

QStringList MusicPlaybackModel::title() const
{
    return m_title;
}

QStringList MusicPlaybackModel::album() const
{
    return m_album;
}

QStringList MusicPlaybackModel::artist() const
{
    return m_artist;
}

QStringList MusicPlaybackModel::source() const
{
    return m_source;
}

QStringList MusicPlaybackModel::albumArt() const
{
    return m_albumArt;
}

void MusicPlaybackModel::setTitle(QStringList title)
{
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
}

void MusicPlaybackModel::setAlbum(QStringList album)
{
    if (m_album == album)
        return;

    m_album = album;
    emit albumChanged(m_album);
}

void MusicPlaybackModel::setArtist(QStringList artist)
{
    if (m_artist == artist)
        return;

    m_artist = artist;
    emit artistChanged(m_artist);
}

void MusicPlaybackModel::setSource(QStringList source)
{
    if (m_source == source)
        return;

    m_source = source;
    emit sourceChanged(m_source);
}

void MusicPlaybackModel::setAlbumArt(QStringList albumArt)
{
    if (m_albumArt == albumArt)
        return;

    m_albumArt = albumArt;
    emit albumArtChanged(m_albumArt);
}

MusicPlaybackModel::MusicPlaybackModel()
{
    
}

void MusicPlaybackModel::clearPlayback()
{
    m_album.clear();
    m_title.clear();
    m_artist.clear();
    m_source.clear();
    m_albumArt.clear();
    urls.clear(); // neu khong xoa url se bi loi
}

MusicPlaybackModel *MusicPlaybackModel::getInStance()
{
    if (m_inStance == nullptr)
    {
        m_inStance = new MusicPlaybackModel();
    }
    return m_inStance;
}

QString MusicPlaybackModel::getAlbumArt(QUrl url)
{
    static const char *IdPicture = "APIC" ;
    TagLib::MPEG::File mpegFile(url.path().toStdString().c_str());
    TagLib::ID3v2::Tag *id3v2tag = mpegFile.ID3v2Tag();
    TagLib::ID3v2::FrameList Frame ;
    TagLib::ID3v2::AttachedPictureFrame *PicFrame ;
    void *SrcImage ;
    unsigned long Size ;
    FILE *jpegFile;
    jpegFile = fopen(QString(url.fileName()+".jpg").toStdString().c_str(),"wb");
    if ( id3v2tag )
    {
        // picture frame
        Frame = id3v2tag->frameListMap()[IdPicture] ;
        if (!Frame.isEmpty() )
        {
            for(TagLib::ID3v2::FrameList::ConstIterator it = Frame.begin(); it != Frame.end(); ++it)
            {
                PicFrame = static_cast<TagLib::ID3v2::AttachedPictureFrame*>(*it) ;
                if ( PicFrame->type() == TagLib::ID3v2::AttachedPictureFrame::FrontCover)
                {
                    // extract image (in it’s compressed form)
                    Size = PicFrame->picture().size() ;
                    SrcImage = malloc ( Size ) ;
                    if ( SrcImage )
                    {
                        memcpy ( SrcImage, PicFrame->picture().data(), Size ) ;
                        fwrite(SrcImage,Size,1, jpegFile);
                        fclose(jpegFile);
                        free( SrcImage ) ;
                        return QUrl::fromLocalFile(url.fileName()+".jpg").toDisplayString();
                    }
                }
            }
        }
    }
    else
    {
        return "qrc:/images/video";
    }
    return "qrc:/images/video";
}

void MusicPlaybackModel::loadMediaList()
{

    qDebug() << "da vao loadMediaList";
//    QDir directory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation)[0]);
//    QFileInfoList musics = directory.entryInfoList(QStringList()<<"*.mp3",QDir::Files);
//    QList<QUrl> urls;
//    for(int i=0;i<musics.length();i++)
//    {
//        urls.append(QUrl::fromLocalFile(musics[i].absoluteFilePath()));
//        //qDebug()<<QUrl::fromLocalFile(musics[i].absoluteFilePath());
//    }

    for(auto &url:/*urls*/MusicPlaybackModel::getInStance()->urls)
    {
        TagLib::FileRef f(url.path().toStdString().c_str());
        TagLib::Tag *tag = f.tag();
   //     QString tilte = QString::fromWCharArray(tag->title().toCWString());
        QString singer = QString::fromWCharArray(tag->artist().toCWString());
        QString album = QString::fromWCharArray(tag->album().toCWString());
        QString source=url.toDisplayString();
        QString albumArt = getAlbumArt(url);
  //      m_title.append(tilte);
        m_artist.append(singer);
        m_album.append(album);
        m_source.append(source);
        m_albumArt.append(albumArt);
    }
    qDebug() << "IN RA THU1";
    for (int i = 0; i<m_title.size();i++ )
    {
        qDebug() << m_title[i];
    }
    qDebug() << "IN RA THU2";
}
QString MusicPlaybackModel::getTitle(int index)
{
    if(m_title.at(index) == "")
    {
        return "Unknown";
    }
    else
    {
        return m_title.at(index);
    }
    //return m_title.at(index);
}

QString MusicPlaybackModel::getAlbum(int index)
{
    if(m_album.at(index) == "")
    {
        return "Unknown";
    }
    else
    {
        return m_album.at(index);
    }
    //return m_album.at(index);
}

QString MusicPlaybackModel::getArtist(int index)
{
    if(m_artist.at(index) == "")
    {
        return "Unknown";
    }
    else
    {
        return m_artist.at(index);
    }
    //return m_artist.at(index);
}

//QString MusicPlaybackModel::getSource(int index)
//{
//    return m_source.at(index);
//}

QString MusicPlaybackModel::getAlbumArt(int index)
{
    if(m_albumArt.at(index) == "qrc:/images/video")
    {
        return "qrc:/images/MusicIma.jpg";
    }
    else
    {
        return m_albumArt.at(index);
    }

//    return m_albumArt.at(index);
}
