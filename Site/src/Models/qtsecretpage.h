#ifndef QTSECRETPAGE_H
#define QTSECRETPAGE_H

#include <abstractpage.h>



class QtSecretAbout: public AbstractPage
{
public:
    QtSecretAbout();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

class QtSecretExamples: public AbstractPage
{
public:
    QtSecretExamples();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

class QtSecretDocs: public AbstractPage
{
public:
    QtSecretDocs();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

#endif // QTSECRETPAGE_H
