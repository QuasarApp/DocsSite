#ifndef HEARTPAGE_H
#define HEARTPAGE_H

#include <abstractpage.h>

class HeartAbout: public AbstractPage
{
public:
    HeartAbout();
    ~HeartAbout() override;

    // AbstractPage interface
public:
    QString data() const override;
    QString title() const override;
    QString backgroud() const override;
    QList<BaseFront::Link> links() const override;
};

class HeartExamples: public AbstractPage
{
public:
    HeartExamples();
    ~HeartExamples() override;

    // AbstractPage interface
public:
    QString data() const override;
    QString title() const override;
    QString backgroud() const override;
    QList<BaseFront::Link> links() const override;

};

class HeartDocs: public AbstractPage
{
public:
    HeartDocs();
    ~HeartDocs() override;

    // AbstractPage interface
public:
    QString data() const override;
    QString title() const override;
    QString backgroud() const override;
    QList<BaseFront::Link> links() const override;

};
#endif // HEARTPAGE_H
