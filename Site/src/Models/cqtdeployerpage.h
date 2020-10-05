#ifndef CQTDEPLOYERABOUT_H
#define CQTDEPLOYERABOUT_H

#include <abstractpage.h>

class CQtDeployerAbout :  public AbstractPage
{
public:
    CQtDeployerAbout();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};


class CQtDeployerExamples:  public AbstractPage
{
public:
    CQtDeployerExamples();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};


class CQtDeployerDocs :  public AbstractPage
{
public:
    CQtDeployerDocs();

    // AbstractPage interface
public:
    QString data() const;
    QString title() const;
    QString backgroud() const;
};


#endif // CQTDEPLOYERABOUT_H
