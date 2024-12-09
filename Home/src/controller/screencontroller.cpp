#include "screencontroller.h"
#include "appdefines.h"
#include "loghelper.h"
#include <QDir>
#include <QStandardPaths>
#include <QDirIterator>

ScreenController* ScreenController::m_instance = nullptr;

ScreenController::ScreenController(QObject *parent)
    : QObject(parent)
    , m_initialized(false)
    , m_engine(nullptr)
{
    LOG_INFO;
    loadMediaList();
    QDBusConnection::sessionBus().connect("",                           // service name, could be empty
                                          "/", // object path, could be empty
                                          "a.home",  // service interface
                                          "home",           // method name
                                          this, SLOT(onSlotHome(QString , QString , QString )));


}

ScreenController::~ScreenController()
{
    LOG_INFO;
    m_engine = nullptr;
}

void ScreenController::broadcastDbusSignal(int n)
{
    LOG_INFO << " nam test signal";

    // 1. create a dbus signal
    QDBusMessage msg = QDBusMessage::createSignal(
                "/vn/com/fsoft/appInterface",   // object path
                "vn.com.fsoft.appInterface",    // service interface
                "screen"              // signal
                );

    // 2. append input arguments
    msg << n ;

    // 3. broadcast signal (using session or system bus)
    QDBusConnection::sessionBus().send(msg);
}

QString ScreenController::getAlbumArt(QUrl url)
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

//void ScreenController::loadMediaList()
//{
//    QDir directory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation)[0]);

//    QFileInfoList musics = directory.entryInfoList(QStringList()<<"*.mp3",QDir::Files);
//    QList<QUrl> urls;
//    for(int i=0;i<musics.length();i++)
//    {
//        urls.append(QUrl::fromLocalFile(musics[i].absoluteFilePath()));
//        qDebug()<<QUrl::fromLocalFile(musics[i].absoluteFilePath());
//    }

//    for(auto &url:urls)
//    {
//        TagLib::FileRef f(url.path().toStdString().c_str());
//        TagLib::Tag *tag = f.tag();
//        QString tilte = QString::fromWCharArray(tag->title().toCWString());
//        QString singer = QString::fromWCharArray(tag->artist().toCWString());
//        QString album = QString::fromWCharArray(tag->album().toCWString());
//        QString source=url.toDisplayString();
//        QString albumArt = getAlbumArt(url);
////        m_title.append(tilte);
////        m_artist.append(singer);
////        m_album.append(album);
////        m_source.append(source);
////        m_albumArt.append(albumArt);
//    }
//}

void ScreenController::loadMediaList()
{
    QDirIterator it("/home",QStringList()<< "*.mp3",QDir::NoFilter, QDirIterator::Subdirectories);
    while( it.hasNext())
        {
            it.next();
            getAlbumArt(QUrl::fromLocalFile(it.filePath()));
        }
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
        // show home menu screen
        pushScreen(AppEnums::SCREEN_ID_HOME_MENU);
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

void ScreenController::reloadScreen()
{
    if(!m_screenStack.isEmpty())
    {
        QString screenName = ScreenNameMap.value(m_screenStack.top());
        // reload screen on qml
        m_model.setCurrentScreen(screenName);
        if((m_engine != nullptr) && (m_engine->rootObjects().count() > 0))
        {
            QMetaObject::invokeMethod(m_engine->rootObjects().at(0), "reloadScreen");
        }
    }
}

void ScreenController::onSlotHome(QString songTitle, QString artistName, QString coverArt)
{
    qDebug()<<"da nhan _ onSlotHome____nam";
    emit signalsHome(songTitle, artistName,  coverArt);
}
