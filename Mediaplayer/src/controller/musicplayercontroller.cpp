#include "musicplayercontroller.h"
#include "musicplaybackmodel.h"
#include "screencontroller.h"
#include <QDBusConnection>
#include <loghelper.h>
#include <QCoreApplication>

MusicPlayerController::MusicPlayerController()
{
    //mPlaybackModel = new MusicPlaybackModel();
    QObject::connect(&mPlayer, &QMediaPlayer::positionChanged, this, &MusicPlayerController::myPositionChange);
    QObject::connect(&mPlayer, &QMediaPlayer::durationChanged, this, &MusicPlayerController::myDurationChange);
    QObject::connect(&mPlayer, &QMediaPlayer::positionChanged, this, &MusicPlayerController::automaticSongSwitching);

    QDBusConnection::sessionBus().connect("","/volumn","volumn.value","volumn",this,
                   SLOT(setVolumn(int)) );
    mPlayer.setVolume(50);

    QDBusConnection::sessionBus().connect("","/language","language.value","language",this,
                   SLOT(setLanguage(QString)));

//    QDBusMessage mesLanguage = QDBusMessage::createSignal("/language","language.value","language");
//    mesLanguage << m_language ;
//    QDBusConnection :: sessionBus().send(mesLanguage);

}

MusicPlayerController *MusicPlayerController::getInstance()
{
    static MusicPlayerController instance;
    return &instance;
}

void MusicPlayerController::play(QString fileName)
{
    QString fullPathMP3 =  MusicListController::getInstance()->getMp3Map().value(fileName);
    //    QString fullPathMP3;
    //    fullPathMP3 =  MusicListController::getInstance()->musicfilePath + "/" + fileName;
    mPlayer.setMedia(QUrl::fromLocalFile(fullPathMP3));
    mPlayer.play();
    qDebug() << "test duration: " << mPlayer.duration();
    //    getDuration();
    //    replaceScreen(AppEnums::SCREEN_ID_MUSIC_PLAYER);
    //   ScreenController::getInstance()->reloadScreen();
}

void MusicPlayerController::playWhenLoadListMp3()
{
//    if(flag == false)
//    {
        play(MusicListController::getInstance()->mListModel.m_model[0]);
//        flag = true;
        emit signalplayWhenLoadListMp3();
//    }
}

void MusicPlayerController::pause()
{
    mPlayer.pause();
}

void MusicPlayerController::resume()
{
    mPlayer.play();
}

void MusicPlayerController::noMusic()
{
    mPlayer.setMedia(QUrl::fromLocalFile(""));
}

void MusicPlayerController::next_prev(int i)
{
    play(MusicListController::getInstance()->mListModel.m_model[i]);
    qDebug() << "i c++: " << i;
}

int MusicPlayerController::getNumberSong()
{
    return MusicListController::getInstance()->mListModel.m_model.size()-1;
}

qint64 MusicPlayerController::getDuration()
{
    //    qDebug() << "Duraton(nam): " << mPlayer.duration();
    return mPlayer.duration();
    //return mPlayer.duration();
    //  QString n =  QString::number(14);
    //    tempCount ++;
    //    return tempCount;
}

int MusicPlayerController::getPosition()
{
    return mPlayer.position();
}

void MusicPlayerController::mySetPosition(qint64 position)
{
    mPlayer.setPosition(position);
}

QString MusicPlayerController::convertMilisecondToMinute(qint64 miliSecond)
{
    //return QString::number((miliSecond/1000)/60) + ":" +QString::number((miliSecond/1000)%60);
    QString minute;
    if(((miliSecond/1000)/60)<10)
    {
        minute = "0" + QString::number((miliSecond/1000)/60);
    }
    else
    {
        minute = QString::number((miliSecond/1000)/60);
    }
    QString second;
    if(((miliSecond/1000)%60)<10)
    {
        second = "0" + QString::number((miliSecond/1000)%60);
    }
    else
    {
        second = QString::number((miliSecond/1000)%60);
    }
    return minute + ":" + second;
}

QString MusicPlayerController::upDateTxt() const
{
    return m_upDateTxt;
}

void MusicPlayerController::automaticSongSwitching()
{
    if((mPlayer.duration() >0 )&&(mPlayer.position() == mPlayer.duration()))
    {

        emit switchSong();
        qDebug() <<"Nam_ emit switchSong()";
        qDebug() <<"pos: " <<mPlayer.position();
        qDebug() <<"Du: " <<mPlayer.duration();
    }
}

void MusicPlayerController::setVolumn(int value)
{
    mPlayer.setVolume(value);
}

void MusicPlayerController::setLanguage(QString language)
{
    LOG_INFO ;
    qDebug() << language;
    if(language == "VietNam")
    {
        mtranslator.load(":/localization/AppLanguage_vi.qm");
        QCoreApplication::installTranslator(&mtranslator);
        emit upDateTxtChanged("");
        qDebug() <<"3333";
    }
    else if(language == "English")
    {
        mtranslator.load(":/localization/AppLanguage_en.qm");
        QCoreApplication::installTranslator(&mtranslator);
        emit upDateTxtChanged("");
    }
}

void MusicPlayerController::setUpDateTxt(QString upDateTxt)
{
    if (m_upDateTxt == upDateTxt)
        return;

    m_upDateTxt = upDateTxt;
    emit upDateTxtChanged(m_upDateTxt);
}







