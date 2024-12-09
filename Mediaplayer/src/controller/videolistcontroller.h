#ifndef MUSICLISTCONTROLLER_H
#define MUSICLISTCONTROLLER_H

#include <QObject>
#include <QQmlContext>
#include "videoplayercontroller.h"
// this class will handle read all .mp4 file in a directory then it push to model
class VideoListController
{

private:
    explicit VideoListController();

public:
    ~VideoListController();

    // singleton pattern
    static VideoListController *getInstance();

    // initialize controller
    void initialize(QQmlContext *context);

private:
    static VideoListController *m_instance;
    bool m_initialized;
};

#endif // MUSICLISTCONTROLLER_H
