#ifndef INFOBLOCK_H
#define INFOBLOCK_H

#include <QObject>
#include <functional>

namespace BaseFront {

/**
 * @brief The Link struct Conteins 2 members it is name of link and hyperlink of the target address
 */
struct Link {
    Link(const QString& name = "", const QString& link = "");
    QString name = "";
    QString link = "";
};

/**
 * @brief The InfoBlock class - this class contains information for viewsolutions comonents
 */
class InfoBlock : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString sourceText READ sourceText WRITE setSourceText NOTIFY sourceTextChanged)
    Q_PROPERTY(QString bakcBroundPicture READ bakcBroundPicture WRITE setBakcgroundPicture NOTIFY bakcBroundPictureChanged)
    Q_PROPERTY(int linksCount READ linksCount NOTIFY linksCountChanged)

public:
    explicit InfoBlock(QObject *parent = nullptr);

    QString title() const;
    QString sourceText() const;
    QString bakcBroundPicture() const;

    Q_INVOKABLE QString linkName(int index) const;
    Q_INVOKABLE QString linkAddress(int index) const;

    int linksCount() const;

    void setLinks(const QList<Link>& links);

public slots:
    void setTitle(QString title);
    void setSourceText(QString sourceText);
    void setBakcgroundPicture(QString bakcBroundPicture);

signals:

    void titleChanged(QString title);
    void sourceTextChanged(QString sourceText);
    void bakcBroundPictureChanged(QString bakcBroundPicture);

    void linksCountChanged(int linksCount);

private:
    QString m_title;
    QString m_sourceText;
    QString m_bakcBroundPicture;
    QList<Link> m_links;
};

uint qHash(const InfoBlock& obj);

}


#endif // INFOBLOCK_H
