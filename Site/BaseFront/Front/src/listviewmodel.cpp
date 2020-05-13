#include "listviewmodel.h"
namespace BaseFront {

ListViewModel::ListViewModel(QObject *ptr):
    BaseListModel(ptr){

}

ListViewModel::~ListViewModel() {
    clear();
}

int ListViewModel::rowCount(const QModelIndex &) const {
    if (external())
        return _externalData->size();

    return _data.size();
}

QVariant ListViewModel::data(const QModelIndex &index, int role) const {

    if (index.row() < rowCount(index)) {
        if (static_cast<ListViewModelRoles>(role) == ListViewModelRoles::Blok) {
            QObject *item = (external())? _externalData->value(index.row()) : _data.value(index.row());
            return QVariant::fromValue(item);
        }
    }

    return {};
}

QHash<int, QByteArray> ListViewModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[static_cast<int>(ListViewModelRoles::Blok)] = "block";

    return roles;
}

void ListViewModel::setExternalSource(const QList<InfoBlock *> *newData) {
    if (external()) {
        beginResetModel();
        _externalData = newData;
        endResetModel();
    } else {
        _externalData = newData;
    }

    setExternal(true);

}

void ListViewModel::setSource(const QList<InfoBlock*> &newData) {

    if (!external()) {
        beginResetModel();

        clear(true);
        _data = newData;

        endResetModel();
    } else {
        clear(true);
        _data = newData;
    }

    setExternal(false);
}

void ListViewModel::addSource(InfoBlock* data) {
    if (!external()) {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        _data.push_back(data);
        endInsertRows();
    } else {
        _data.push_back(data);
    }
}

void ListViewModel::clear(bool fast) {
    for (auto i : _data) {
        if (fast) {
            i->deleteLater();
        } else {
            delete i;
        }
    }

    _data.clear();
}

bool ListViewModel::external() const {
    return _external;
}

void ListViewModel::setExternal(bool external) {
    if (external != _external) {
        beginResetModel();
        _external = external;
        endResetModel();
    }
}
}
