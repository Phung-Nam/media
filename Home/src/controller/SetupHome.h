#ifndef SETUPHOME_H
#define SETUPHOME_H

#include <QObject>
#include <QQmlContext>
#include <QTranslator>

class SetupHome : public QObject
{
    Q_OBJECT
    explicit SetupHome(QObject *parent = nullptr);
    static SetupHome* m_Instance;
    Q_PROPERTY(int  myValueVolume READ myValueVolume WRITE setMyValueVolume NOTIFY myValueVolumeChanged)
    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)
    Q_PROPERTY(QString sourceLanguegeScreen READ sourceLanguegeScreen WRITE setSourceLanguegeScreen NOTIFY sourceLanguegeScreenChanged)
    int m_myValueVolume = 50;

    QString m_language =  "English";

    QTranslator mTranslator;


    QString m_sourceLanguegeScreen = "HomeScreen/ScreenSetupLanguage.qml";

public:
    static SetupHome* getInstance();
    void initialize(QQmlContext *context);
    Q_INVOKABLE void test();

    //    Q_INVOKABLE void mySetVolume(int value);

    int myValueVolume() const;

    QString language() const;

    QString sourceLanguegeScreen() const;

public slots:
    void setMyValueVolume(int myValueVolume);

    void setLanguage(QString language);

    void setSourceLanguegeScreen(QString sourceLanguegeScreen);

signals:

    void myValueVolumeChanged(int myValueVolume);
    void languageChanged(QString language);
    void sourceLanguegeScreenChanged(QString sourceLanguegeScreen);
};

#endif // SETUPHOME_H
