#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QObject>
#include <listviewmodel.h>

class MainModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QObject* listModel READ listModel WRITE setListModel NOTIFY listModelChanged)

public:
    explicit MainModel(QObject *parent = nullptr);
    Q_INVOKABLE bool openPage(const QString& url);

    QObject* listModel() const;

public slots:
    void setListModel(QObject* listModel);

signals:

    void listModelChanged(QObject* listModel);

private:
    void initQuasarApp();
    QList<BaseFront::InfoBlock*> * _QuasarAppPage = nullptr;
    BaseFront::ListViewModel *_listModel = nullptr;
};

#endif // MAINPAGE_H
