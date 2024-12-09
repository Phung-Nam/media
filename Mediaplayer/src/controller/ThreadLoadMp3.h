#ifndef THREADLOADMP3_H
#define THREADLOADMP3_H
#include <QThread>

class ThreadLoadMp3 : public QThread
{
    static ThreadLoadMp3* m_Instance;
    QString mRootDirectoryPath;

public:
    static ThreadLoadMp3* getInstance();
    ThreadLoadMp3();
    void run() override;
    void getFolderAndMp3_Thread(QString rootDirectoryPath);
};

#endif // THREADLOADMP3_H
