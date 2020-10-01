#ifndef CQTDEPLOYER_H
#define CQTDEPLOYER_H

#include <abstractsidebaritem.h>



class CQtDeployer: public AbstractSideBarItem
{
    Q_OBJECT
public:
    CQtDeployer();

    // AbstractSideBarItem interface
public:
    QString description() const;
    QString title() const;
    QString backgroud() const;
};

#endif // CQTDEPLOYER_H
