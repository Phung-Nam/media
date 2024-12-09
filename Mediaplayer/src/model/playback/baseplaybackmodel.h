#ifndef BASEPLAYBACKMODEL_H
#define BASEPLAYBACKMODEL_H

#include <QObject>

// tim nhung cai property chung giua music va video de cho vao day, vi du: play status, current time, total time
class BasePlaybackModel : public QObject
{
    Q_OBJECT
public:
    BasePlaybackModel();
};

#endif // BASEPLAYBACKMODEL_H
