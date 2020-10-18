#ifndef CQTDEPLOYERABOUT_H
#define CQTDEPLOYERABOUT_H

#include <abstractpage.h>

class CQtDeployerAbout :  public AbstractPage
{
public:
    CQtDeployerAbout();

    // AbstractPage interface
public:
    QString data() const override;
    QString title() const override;
    QString backgroud() const override;
    QList<BaseFront::Link> links() const override;

};


class CQtDeployerExamples:  public AbstractPage
{
public:
    CQtDeployerExamples();

    // AbstractPage interface
public:
    QString data() const override;
    QString title() const override;
    QString backgroud() const override;
    QList<BaseFront::Link> links() const override;

};


class CQtDeployerDocs :  public AbstractPage
{
public:
    CQtDeployerDocs();

    // AbstractPage interface
public:
    QString data() const override;
    QString title() const override;
    QString backgroud() const override;
    QList<BaseFront::Link> links() const override;

};


#endif // CQTDEPLOYERABOUT_H
