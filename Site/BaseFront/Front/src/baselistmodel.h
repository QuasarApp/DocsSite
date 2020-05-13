#ifndef BASELISTMODEL_H
#define BASELISTMODEL_H
#include "BaseFront_global.h"
#include <QAbstractListModel>

namespace BaseFront {

class BASEFRONT_LIBRARYSHARED_EXPORT BaseListModel: public QAbstractListModel
{
    Q_OBJECT

public:
    BaseListModel(QObject* ptr = nullptr);

    bool canFetchMore(const QModelIndex & /* index */) const;
    void fetchMore(const QModelIndex & /* index */);

private:
    int _itemCount = 0;
};

}
#endif // BASELISTMODEL_H
