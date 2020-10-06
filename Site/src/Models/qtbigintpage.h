#ifndef QTBIGINTPAGE_H
#define QTBIGINTPAGE_H


#include <abstractpage.h>

class QtBigIntAbout: public AbstractPage
{
public:
    QtBigIntAbout();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

class QtBigIntExamples: public AbstractPage
{
public:
    QtBigIntExamples();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

class QtBigIntDocs: public AbstractPage
{
public:
    QtBigIntDocs();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

#endif // QTBIGINTPAGE_H
