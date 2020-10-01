#ifndef ABSTRACTSIDEBARITEM_H
#define ABSTRACTSIDEBARITEM_H
#include "iresources.h"

#include <QObject>


/**
 * @brief The AbstractSideBarItem class This is interface for sidebar items
 */
class AbstractSideBarItem: public QObject, public IResources
{
    Q_OBJECT
public:
    AbstractSideBarItem();

    /**
     * @brief description This is base method for get text description of page.
     * All description must be use the tr method of qt.
     * @return transalted text.
     */
    virtual QString description() const = 0;

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

    QObject *makeBlok() const;
};

#endif // ABSTRACTSIDEBARITEM_H
