#ifndef MUSICLISTMODEL_H
#define MUSICLISTMODEL_H

#include <QObject>

// handle list data model for display music list screen
class MusicListModel : public QObject
{
private:
    Q_OBJECT
    Q_PROPERTY(QStringList model READ model WRITE setModel NOTIFY modelChanged)



public:
    MusicListModel(QObject* parent = nullptr);
    ~ MusicListModel();
    QStringList m_model;

    QStringList model() const
    {
        return m_model;
    }
public slots:
    void setModel(QStringList model)
    {
        if (m_model == model)
            return;

        m_model = model;
        emit modelChanged(m_model);
    }
signals:
    void modelChanged(QStringList model);
};

#endif // MUSICLISTMODEL_H
