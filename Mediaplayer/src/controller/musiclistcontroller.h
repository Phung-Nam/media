#ifndef MUSICLISTCONTROLLER_H
#define MUSICLISTCONTROLLER_H

#include <QObject>
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
#include <QDirIterator>
#include <QStandardPaths>
#include "musicplayercontroller.h"
#include "musicplaybackmodel.h"
#include <QStack>


// this class will handle read all .mp3 file in a directory then it push to model
class MusicListController:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList folderList READ folderList WRITE setFolderList NOTIFY folderListChanged)
private:
    explicit MusicListController(QObject* parent = nullptr);


public:
    ~MusicListController();

    // singleton pattern
    static MusicListController *getInstance();

    // initialize controller
    void initialize(QQmlContext *context);

    QString musicfilePath;
    QString firstSong ;
    MusicListModel mListModel;

    Q_INVOKABLE void getFileName();

    Q_INVOKABLE int getSizeModel();

    Q_INVOKABLE void clickFolder (QString folderName);

    Q_INVOKABLE void clickBack ();


    QMap<QString, QString> getListFile() const;



    QStringList folderList() const;

    QMap<QString, QString> getMp3Map() const;
    void getFolerAndMp3 (QString rootDirectoryPath);

public slots:
    void setFolderList(QStringList folderList);

signals:
    void folderListChanged(QStringList folderList);

private:
    static MusicListController *m_instance;
    bool m_initialized;
    bool isFistLoad = false;

    //    MusicPlaybackModel musicPlaybackModel;

    QMap<QString, QString > listFile; //key save fileName, value save filePath

    QMap<QString, QString > mp3Map;
    QMap<QString, QString > folderMap;

    QStack <QString> folderStack;








    //QString filePath;





    QStringList m_folderList;
};

#endif // MUSICLISTCONTROLLER_H




























