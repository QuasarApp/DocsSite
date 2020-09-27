#ifndef PAGEINFO_H
#define PAGEINFO_H

#include <QObject>
namespace BaseFront {
class PageInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString banner READ banner WRITE setBanner NOTIFY bannerChanged)
    Q_PROPERTY(QString shortCut READ shortCut WRITE setShortCut NOTIFY shortCutChanged)
    Q_PROPERTY(QString page READ page WRITE setPage NOTIFY pageChanged)

public:
    PageInfo();
    QString banner() const;
    QString shortCut() const;

    QString page() const;

public slots:
    void setBanner(QString banner);
    void setShortCut(QString shortCut);

    void setPage(QString page);

signals:
    void bannerChanged(QString banner);
    void shortCutChanged(QString shortCut);
    void pageChanged(QString page);

private:
    QString m_banner;
    QString m_shortCut;
    QString m_page;
};

}
#endif // PAGEINFO_H
