#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QObject>
#include <infoblock.h>
#include <listviewmodel.h>

enum class Languages {
    EN,
    RU
};

class AbstractPage;
namespace BaseFront {
class Reader;
}

class MainModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QObject* pageModel READ pageModel WRITE setPageModel NOTIFY pageModelChanged)
    Q_PROPERTY(QObject* pageListModel READ pageListModel WRITE setPageListModel NOTIFY pageListModelChanged)

public:
    explicit MainModel(QObject *parent = nullptr);
    ~MainModel();
    Q_INVOKABLE bool openPage(const QString& url);
    Q_INVOKABLE void changeLanguage(int code);


    QObject* pageModel() const;
    QObject* pageListModel() const;

public slots:
    void setPageModel(QObject* pageModel);
    void setPageListModel(QObject* pageListModel);

signals:
    void pageModelChanged(QObject* pageModel);
    void pageListModelChanged(QObject* pageListModel);

private:
    void initQuasarApp();
    void clearPages();

    QHash<QString, QList<QObject*>*> _QuasarAppPages;
    ViewSolutions::ListViewModel *_pageModel = nullptr;
    ViewSolutions::ListViewModel *_pageListModel = nullptr;
    BaseFront::Reader * _reader;
};

#endif // MAINPAGE_H
