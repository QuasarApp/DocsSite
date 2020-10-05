#ifndef CQTDEPLOYEREXAMPLES_H
#define CQTDEPLOYEREXAMPLES_H

#include <abstractpage.h>



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

#endif // CQTDEPLOYEREXAMPLES_H
