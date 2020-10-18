#ifndef HEART_H
#define HEART_H

#include <abstractsidebaritem.h>

class Heart: public AbstractSideBarItem
{
public:
    Heart();

    // AbstractSideBarItem interface
public:
    QString description() const override;
    QString title() const override;
    QString backgroud() const override;
    QString projectName() const override;
};

#endif // HEART_H
