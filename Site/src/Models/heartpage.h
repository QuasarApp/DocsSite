#ifndef HEARTPAGE_H
#define HEARTPAGE_H

#include <abstractpage.h>

class HeartAbout: public AbstractPage
{
public:
    HeartAbout();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

class HeartExamples: public AbstractPage
{
public:
    HeartExamples();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

class HeartDocs: public AbstractPage
{
public:
    HeartDocs();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};
#endif // HEARTPAGE_H
