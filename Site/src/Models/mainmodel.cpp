#include "mainmodel.h"
#include "reader.h"

MainModel::MainModel(QObject *parent) : QObject(parent) {
    setListModel(new BaseFront::ListViewModel(this));
    initQuasarApp();
}

bool MainModel::openPage(const QString &url) {

    if (url == "QuasarApp") {
        _listModel->setExternalSource(_QuasarAppPage);
        return true;
    }

    return false;
}

QObject *MainModel::listModel() const {
    return _listModel;
}

void MainModel::setListModel(QObject *listModel) {
    auto model = dynamic_cast<BaseFront::ListViewModel*>(listModel);
    if (!model || _listModel == model)
        return;

    _listModel = model;
    emit listModelChanged(_listModel);
}

void MainModel::initQuasarApp() {
    if (_QuasarAppPage) {
        return;
    }

    _QuasarAppPage = new QList<BaseFront::InfoBlock*>();

    auto block = new BaseFront::InfoBlock(this);
    _QuasarAppPage->push_back(block);

    block->setTitle(tr("QuasarApp Group"));
    block->setSourceText(BaseFront::Reader::instance()->read(":/sources/html/QuasarAppAbout.htm"));
    block->setBakcBroundPicture(":/img/images/LOGO.png");


}

