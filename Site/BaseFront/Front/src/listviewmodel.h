#ifndef LISTVIEWMODEL_H
#define LISTVIEWMODEL_H
#include "BaseFront_global.h"
#include "infoblock.h"
#include "baselistmodel.h"


namespace BaseFront {

enum class ListViewModelRoles {
    Blok = Qt::UserRole
};

class BASEFRONT_LIBRARYSHARED_EXPORT ListViewModel: public BaseListModel
{
    Q_OBJECT
public:
    ListViewModel(QObject *ptr = nullptr);
    ~ListViewModel();

    int rowCount(const QModelIndex &parent =  QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    void setExternalSource(const QList<InfoBlock*>* newData);
    void setSource(const QList<InfoBlock*>& newData);
    void addSource(InfoBlock *data);

    void clear(bool fast = false);

    bool external() const;

private:
    void setExternal(bool external);

    bool _external = false;
    QList<InfoBlock*> _data;
    const QList<InfoBlock*> *_externalData = nullptr;

};
}
#endif // LISTVIEWMODEL_H
