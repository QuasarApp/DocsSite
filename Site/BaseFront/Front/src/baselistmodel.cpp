#include "baselistmodel.h"
namespace BaseFront {

BaseListModel::BaseListModel(QObject *ptr):
    QAbstractListModel(ptr) {

}

bool BaseListModel::canFetchMore(const QModelIndex &) const {
    if (_itemCount != rowCount())
        return true;
    else
        return false;
}

void BaseListModel::fetchMore(const QModelIndex &) {
    int remainder = rowCount() - _itemCount;
    int itemsToFetch = qMin(100, remainder);

    if (itemsToFetch < 0) {
        beginRemoveRows(QModelIndex(), 0, 0 - itemsToFetch - 1 );

        _itemCount += itemsToFetch;

        endRemoveRows();
    } else if (itemsToFetch > 0) {
        beginInsertRows(QModelIndex(), _itemCount, _itemCount + itemsToFetch - 1);

        _itemCount += itemsToFetch;

        endInsertRows();
    }

}
}
