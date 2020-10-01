#ifndef IRESOURCES_H
#define IRESOURCES_H

#include <QString>

class QObject;

class IResources
{
public:
    IResources();
    virtual ~IResources() = default;

    /**
     * @brief makeBlok This method build infoblock from available data.
     * @return the page data
     */
    virtual QObject *makeBlok() const = 0;

    /**
     * @brief resourcesPath This method return path to resources of site.
     * By Default this is plugins folder.
     * @return path tot resources.
     */
    virtual QString resourcesPath() const;
};

#endif // IRESOURCES_H
