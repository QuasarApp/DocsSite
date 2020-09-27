#ifndef QASARAPPORDER_H
#define QASARAPPORDER_H

#include <abstractpage.h>



class QasarAppOrder: public AbstractPage
{
public:
    QasarAppOrder();

    // AbstractPage interface
public:
    QString data() const override;
    QString title() const override;
    QString backgroud() const override;
};

#endif // QASARAPPORDER_H
