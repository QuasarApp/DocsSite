#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QObject>
#include <infoblock.h>
#include <listviewmodel.h>

enum class Languages {
    EN,
    RU
};

class MainModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QObject* listModel READ listModel WRITE setListModel NOTIFY listModelChanged)

public:
    explicit MainModel(QObject *parent = nullptr);
    Q_INVOKABLE bool openPage(const QString& url);
    Q_INVOKABLE void changeLanguage(int code);

    QObject* listModel() const;

public slots:
    void setListModel(QObject* listModel);

signals:

    void listModelChanged(QObject* listModel);

private:
    void initQuasarApp();
    QList<QObject*> * _QuasarAppPage = nullptr;
    ViewSolutions::ListViewModel *_listModel = nullptr;
};

#endif // MAINPAGE_H
