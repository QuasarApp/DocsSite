#ifndef ABSTRACTPAGE_H
#define ABSTRACTPAGE_H

#include <QObject>
#include <QString>

/**
 * @brief The AbstractPage class - This is interface of all text pages on cpp.
 */
class AbstractPage: public QObject
{
    Q_OBJECT
public:
    AbstractPage();

    /**
     * @brief data This is base method for get text data of page.
     * All data must be use the tr method of qt.
     * @return transalted text.
     */
    virtual QString data() const = 0;

    /**
     * @brief title This method return title of page.
     * @return title of page.
     */
    virtual QString title() const = 0;

    /**
     * @brief backgroud This is path to image or video of background.
     * @return path to backgroud.
     */
    virtual QString backgroud() const = 0;


    /**
     * @brief makeBlok This method build infoblock from available data.
     * @return the page data
     */
    QObject *makeBlok() const;

protected:
    /**
     * @brief resourcesPath This method return path to resources of site.
     * By Default this is plugins folder.
     * @return path tot resources.
     */
    QString resourcesPath() const;
};

#endif // ABSTRACTPAGE_H
