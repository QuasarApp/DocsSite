#ifndef INFOBLOCK_H
#define INFOBLOCK_H

#include <QObject>
namespace BaseFront {

/**
 * @brief The InfoBlock class - this class contains information for viewsolutions comonents
 */
class InfoBlock : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString sourceText READ sourceText WRITE setSourceText NOTIFY sourceTextChanged)
    Q_PROPERTY(QString bakcBroundPicture READ bakcBroundPicture WRITE setBakcBroundPicture NOTIFY bakcBroundPictureChanged)

public:
    explicit InfoBlock(QObject *parent = nullptr);

    QString title() const;
    QString sourceText() const;
    QString bakcBroundPicture() const;

public slots:
    void setTitle(QString title);
    void setSourceText(QString sourceText);
    void setBakcBroundPicture(QString bakcBroundPicture);

signals:

    void titleChanged(QString title);
    void sourceTextChanged(QString sourceText);
    void bakcBroundPictureChanged(QString bakcBroundPicture);

private:
    QString m_title;
    QString m_sourceText;
    QString m_bakcBroundPicture;
};

uint qHash(const InfoBlock& obj);

}


#endif // INFOBLOCK_H
