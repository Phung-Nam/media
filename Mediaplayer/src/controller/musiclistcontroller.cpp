#include "musiclistcontroller.h"
#include "loghelper.h"
#include <QFileDialog>
#include "screencontroller.h"
#include <QStack>
#include "ThreadLoadMp3.h"

MusicListController* MusicListController::m_instance = nullptr;

MusicListController::MusicListController(QObject* parent ):QObject(parent), m_initialized(false)

{
    LOG_INFO;
    //getFileName();
}

MusicListController::~MusicListController()
{

    LOG_INFO;
}

MusicListController *MusicListController::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new MusicListController();
    }

    return m_instance;
}

void MusicListController::initialize(QQmlContext *context)
{
    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        context->setContextProperty("MLIST_CTRL", this);
        context->setContextProperty("MLIST", &mListModel);
        context->setContextProperty("MUSIC_PLAY_CONTROLER", MusicPlayerController::getInstance());
        context->setContextProperty("MUSIC_PLAYBACK_MODEL", MusicPlaybackModel::getInStance());
        context->setContextProperty("FOLDER_LIST", QVariant::fromValue(m_folderList));
    }
}

//void MusicListController::getFileName()
//{
//    qDebug()<< "da vao duoc getFileName()";
//    //    QDir directory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation)[0]);

//    //   //test
//    //    qDebug() << QStandardPaths::standardLocations(QStandardPaths::MusicLocation).size();
//    //    for(int i =0; i<QStandardPaths::standardLocations(QStandardPaths::MusicLocation).size(); i++)
//    //    {
//    //        qDebug() << "test standardLocations__ " << QStandardPaths::standardLocations(QStandardPaths::MusicLocation)[i];
//    //    }



//    //   //test end

//    //    mListModel.m_model  = directory.entryList(QStringList("*.mp3"));

//    //    qDebug()<<"so luong bai hat: "<< mListModel.m_model.size();
//    //    musicfilePath = directory.filePath("");
//    //    qDebug()<< "directory.filePath: " << directory.filePath("");

//    ////    for(int i = 0; i< mListModel.m_model.size(); i++)
//    ////    {
//    ////        qDebug()<< mListModel.m_model[i];
//    ////    }



//    //---------------------------------------SỬA LẠI THEO CÁCH LẤY NHẠC TRONG CẢ THU MỤC CON--------------------------------
//    QWidget* parent = nullptr;
//    QString rootDirectoryPath = QFileDialog::getExistingDirectory(parent, QString(), "/home");
//    qDebug() <<"rootDirectoryPath:__ "<< rootDirectoryPath;

//    QDirIterator it(rootDirectoryPath, QStringList()<< "*.mp3",QDir::NoFilter, QDirIterator::Subdirectories );

//    while( it.hasNext())
//    {
//        it.next();
//        //       qDebug() << it.fileName();
//        //       qDebug() << it.filePath();
//        listFile.insert(it.fileName(),it.filePath());
//        mListModel.m_model.append(it.fileName()); // lay danh sach ten bai hat

//        MusicPlaybackModel::getInStance()->urls.append(QUrl::fromLocalFile(it.filePath()));
//    }
//    qDebug() <<listFile.size();
//    //listFile.clear();
//    //    QMap<QString, QString > ::iterator i;
//    //    for(i = listFile.begin(); i!=listFile.end(); i++)
//    //    {
//    //        //qDebug() <<  i.key() <<" : " <<  i.value();
//    //        mListModel.m_model.append(i.key());

//    //    }
//    //    qDebug() <<" so luong bai hat trong model: "<< mListModel.m_model.size();

//    if(mListModel.m_model.size()>0)
//    {
//        firstSong = mListModel.m_model[0];
//        if(isFistLoad == false)
//        {
//            MusicPlayerController::getInstance()->playWhenLoadListMp3();
//            isFistLoad = true;
//        }

////        qDebug() << "invokeMethod: "<< QMetaObject::invokeMethod(ScreenController::getInstance()->getEngine()->rootObjects().at(0), "namsFunction");
////        qDebug() << "invokeMethod: "<< ScreenController::getInstance()->getEngine()->rootObjects().size();
//    }
//}

void MusicListController::getFolerAndMp3 (QString rootDirectoryPath)
{
    LOG_INFO;
    MusicPlaybackModel::getInStance()->clearPlayback();

    QDir qdir(rootDirectoryPath);
    QFileInfoList  mp3List = qdir.entryInfoList(QStringList()<< "*.mp3");
    QFileInfoList folderInFoList = qdir.entryInfoList(QDir::Dirs|QDir::NoDotAndDotDot);
    int n = mp3List.size();
    for (int  i = 0; i < n; i++)
    {
        qDebug() << mp3List [i].fileName();
        mListModel.m_model.append(mp3List [i].fileName());
        mp3Map.insert(mp3List [i].fileName(),mp3List [i].filePath());

        MusicPlaybackModel::getInStance()->urls.append(QUrl::fromLocalFile(mp3List [i].filePath()));
        MusicPlaybackModel::getInStance()-> setTitle( mListModel.m_model);
    }
    MusicPlaybackModel::getInStance()->loadMediaList();

    int m = folderInFoList.size();
    for(int i = 0; i< m; i++)
    {
        qDebug() << folderInFoList [i].fileName();
        m_folderList.append(folderInFoList [i].fileName());
        folderMap.insert(folderInFoList [i].fileName(),folderInFoList [i].filePath());
    }
    qDebug() << m_folderList.size();

}


void MusicListController::getFileName()
{
    qDebug()<< "da vao duoc getFileName()";

    mListModel.m_model.clear();
    m_folderList.clear();

    QWidget* parent = nullptr;
    QString rootDirectoryPath = QFileDialog::getExistingDirectory(parent, QString(), "/home");
    qDebug() <<"rootDirectoryPath:__ "<< rootDirectoryPath;

    folderStack.push(rootDirectoryPath);
    //getFolerAndMp3(rootDirectoryPath);
    ThreadLoadMp3 :: getInstance()->getFolderAndMp3_Thread(rootDirectoryPath);

}


int MusicListController::getSizeModel()
{
    return mListModel.m_model.size();
}

void MusicListController::clickFolder(QString folderName)
{
    m_folderList.clear();
    mListModel.m_model.clear();

   // getFolerAndMp3(folderMap.value(folderName));
    ThreadLoadMp3 :: getInstance()->getFolderAndMp3_Thread(folderMap.value(folderName));

    folderStack.push(folderMap.value(folderName)); //push duong dan cua thu muc vao stack
}

void MusicListController::clickBack()
{

    if(folderStack.size()>1)
    {
        m_folderList.clear();
        mListModel.m_model.clear();

        folderStack.pop();
        //getFolerAndMp3(folderStack.top());
        ThreadLoadMp3 :: getInstance()->getFolderAndMp3_Thread(folderStack.top());
    }

}



QMap<QString, QString> MusicListController::getListFile() const
{
    return listFile;
}

QStringList MusicListController::folderList() const
{
    return m_folderList;
}

void MusicListController::setFolderList(QStringList folderList)
{
    if (m_folderList == folderList)
        return;

    m_folderList = folderList;
    emit folderListChanged(m_folderList);
}

QMap<QString, QString> MusicListController::getMp3Map() const
{
    return mp3Map;
}









