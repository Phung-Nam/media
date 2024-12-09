#include "SetupHome.h"
#include <QDebug>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QCoreApplication>
#include "loghelper.h"
#include "screencontroller.h"
SetupHome* SetupHome::m_Instance = nullptr;

SetupHome::SetupHome(QObject *parent) : QObject(parent)
{
     mTranslator.load(":/localization/AppLanguage_en.qm");
     //mTranslator.load(":/localization/AppLanguage_vi.qm");
     QCoreApplication::installTranslator(&mTranslator);
}

SetupHome* SetupHome::getInstance()
{
    if(m_Instance == nullptr)
    {
        m_Instance = new SetupHome();
    }
    return m_Instance;
}

void SetupHome::initialize(QQmlContext *context)
{
    context->setContextProperty("SETUP_HOME",SetupHome::getInstance());
}

void SetupHome::test()
{
    qDebug() << "test Class mowi";
}

//void SetupHome::mySetVolume(int value)
//{

//}

int SetupHome::myValueVolume() const
{
    return m_myValueVolume;
}

QString SetupHome::language() const
{
    return m_language;
}

QString SetupHome::sourceLanguegeScreen() const
{
    LOG_INFO;
    return m_sourceLanguegeScreen;
}

void SetupHome::setMyValueVolume(int myValueVolume)
{
    if (m_myValueVolume == myValueVolume)
        return;

    m_myValueVolume = myValueVolume;

    //broadcast signal to media app
    QDBusMessage valueVolumn = QDBusMessage::createSignal("/volumn","volumn.value","volumn");
    valueVolumn << m_myValueVolume ;
    QDBusConnection :: sessionBus().send(valueVolumn);
    //end broadcast signal

    emit myValueVolumeChanged(m_myValueVolume);
}

void SetupHome::setLanguage(QString language)
{
    LOG_INFO;
    if (m_language == language)
        return;

    m_language = language;
    emit languageChanged(m_language);

    if(m_language == "VietNam")
    {
        mTranslator.load(":/localization/AppLanguage_vi.qm");

    }
    else if (m_language == "English")
    {
        mTranslator.load(":/localization/AppLanguage_en.qm");
    }
    QCoreApplication::installTranslator(&mTranslator);
//    m_sourceLanguegeScreen = ""; //load lai man hinh setup language
//    emit sourceLanguegeScreenChanged(m_sourceLanguegeScreen);
//    m_sourceLanguegeScreen = "HomeScreen/ScreenSetupLanguage.qml";
//    emit sourceLanguegeScreenChanged(m_sourceLanguegeScreen);
    ScreenController :: getInstance()->reloadScreen();

    QDBusMessage mesLanguage = QDBusMessage::createSignal("/language","language.value","language");
    mesLanguage << m_language ;
    QDBusConnection :: sessionBus().send(mesLanguage);


}

void SetupHome::setSourceLanguegeScreen(QString sourceLanguegeScreen)
{
    if (m_sourceLanguegeScreen == sourceLanguegeScreen)
        return;

    m_sourceLanguegeScreen = sourceLanguegeScreen;
    emit sourceLanguegeScreenChanged(m_sourceLanguegeScreen);
}












