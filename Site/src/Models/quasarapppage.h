#ifndef QUASARAPPPAGE_H
#define QUASARAPPPAGE_H

#include "abstractpage.h"

/**
 * @brief The QuasarAppPage class - This is page about QuasarApp
 */
class QuasarAppPage: public AbstractPage
{
    Q_OBJECT
public:
    QuasarAppPage();

    // AbstractPage interface
    QString data() const override;
    QString title() const override;
    QString backgroud() const override;

};


class QasarAppOrder: public AbstractPage
{
public:
    QasarAppOrder();

    // AbstractPage interface
public:
    QString data() const override;
    QString title() const override;
    QString backgroud() const override;
};

class QuasarAppSupportPlatforms: public AbstractPage
{
public:
    QuasarAppSupportPlatforms();

    // AbstractPage interface
public:
    QString data() const override;
    QString title() const override;
    QString backgroud() const override;
};


#endif // QUASARAPPPAGE_H
