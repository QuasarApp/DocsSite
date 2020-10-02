#ifndef SIDEBARITEM_H
#define SIDEBARITEM_H

#include <QObject>



class SideBarItem:  public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString banner READ banner WRITE setBanner NOTIFY bannerChanged)
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)

public:
    explicit SideBarItem(QObject *parent = nullptr);
    QString title() const;
    QString description() const;
    QString banner() const;

    QString path() const;

public slots:
    void setTitle(QString title);
    void setDescription(QString description);
    void setBanner(QString banner);
    void setPath(QString path);

signals:
    void titleChanged(QString title);
    void descriptionChanged(QString description);
    void bannerChanged(QString banner);
    void pathChanged(QString path);

private:

    QString m_title;
    QString m_description;
    QString m_banner;
    QString m_path;
};



#endif // SIDEBARITEM_H
