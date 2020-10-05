#ifndef CQTDEPLOYERDOCS_H
#define CQTDEPLOYERDOCS_H

#include <abstractpage.h>

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

#endif // CQTDEPLOYERDOCS_H
