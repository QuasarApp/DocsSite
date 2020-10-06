#ifndef PATRONUMPAGE_H
#define PATRONUMPAGE_H


#include <abstractpage.h>



class PatronumAbout: public AbstractPage
{
public:
    PatronumAbout();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

class PatronumExamples: public AbstractPage
{
public:
    PatronumExamples();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

class PatronumDocs: public AbstractPage
{
public:
    PatronumDocs();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};
#endif // PATRONUMPAGE_H
