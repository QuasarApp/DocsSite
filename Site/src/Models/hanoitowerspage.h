#ifndef HANOITOWERSPAGE_H
#define HANOITOWERSPAGE_H

#include <abstractpage.h>

class HanoiTowersAbout: public AbstractPage
{
public:
    HanoiTowersAbout();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

class HanoiTowersExamples: public AbstractPage
{
public:
    HanoiTowersExamples();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

class HanoiTowersDocs: public AbstractPage
{
public:
    HanoiTowersDocs();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};
#endif // HANOITOWERSPAGE_H
