#ifndef QUASARAPPSUPPORTPLATFORMS_H
#define QUASARAPPSUPPORTPLATFORMS_H

#include <abstractpage.h>

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

#endif // QUASARAPPSUPPORTPLATFORMS_H
