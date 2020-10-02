#ifndef HOME_H
#define HOME_H

#include <abstractsidebaritem.h>



class Home: public AbstractSideBarItem
{
    Q_OBJECT
public:
    Home();

    // AbstractSideBarItem interface
public:
    QString description() const;
    QString title() const;
    QString backgroud() const;
    QString projectName() const;
};

#endif // HOME_H
