#ifndef VIEWSOLUTIONSPAGE_H
#define VIEWSOLUTIONSPAGE_H

#include <abstractpage.h>

class ViewSolutionsAbout: public AbstractPage
{
public:
    ViewSolutionsAbout();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

class ViewSolutionsExamples: public AbstractPage
{
public:
    ViewSolutionsExamples();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

class ViewSolutionsDocs: public AbstractPage
{
public:
    ViewSolutionsDocs();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};

#endif // VIEWSOLUTIONSPAGE_H
