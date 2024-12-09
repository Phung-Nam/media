#ifndef MUSICPLAYERCONTROLLER_H
#define MUSICPLAYERCONTROLLER_H

#include "baseplayercontroller.h"
#include "musiclistcontroller.h"
#include <qtranslator.h>


class MusicPlayerController : public BasePlayerController
{
    //int tempCount = 1;

    Q_OBJECT

    bool flag = false;
    QTranslator mtranslator;
    Q_PROPERTY(QString upDateTxt READ upDateTxt WRITE setUpDateTxt NOTIFY upDateTxtChanged)
    QString m_upDateTxt ="";

public:

    MusicPlayerController();
    static MusicPlayerController *getInstance();
    Q_INVOKABLE void play(QString fileName);
    Q_INVOKABLE void playWhenLoadListMp3();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void resume();
    Q_INVOKABLE void noMusic();
    Q_INVOKABLE void next_prev(int i);

    Q_INVOKABLE int getNumberSong();
    Q_INVOKABLE qint64 getDuration();
    Q_INVOKABLE int getPosition();
    Q_INVOKABLE void mySetPosition(qint64 position);

    Q_INVOKABLE QString convertMilisecondToMinute (qint64 miliSecond);

    QString upDateTxt() const;

public slots:
   void automaticSongSwitching();
   void setVolumn(int value);
   void setLanguage(QString language);
   void setUpDateTxt(QString upDateTxt);

signals:
   void myPositionChange (qint64 position);
   void myDurationChange (qint64 duration);
   void switchSong();
   void signalplayWhenLoadListMp3();

   void upDateTxtChanged(QString upDateTxt);
};

#endif // MUSICPLAYERCONTROLLER_H
