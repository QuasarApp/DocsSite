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

    QString sourceText = tr("The <b>QuasarApp</b> is developing open source mobile and desktop applications.<br><br>"
                            "Our company has ben created on 2017 yahr and have experians of develepment android and desctop applications and games."
                            "<br><br>");

    sourceText += tr("During our existence, we have accumulated more than 40 software components and ready-made solutions for the most diverse tasks.<br>"
                     "This approach allows us now to create final products with impressive speed. If you have an idea for the application, we will hear you."
                     "<br><br>");

    block->setSourceText(sourceText);
    block->setBakcBroundPicture("qrc:/img/images/LOGO.png");


    block = new BaseFront::InfoBlock(this);
    _QuasarAppPage->push_back(block);

    block->setTitle(tr("QuasarApp Group"));

    sourceText = tr("At the moment, we can offer support for our solutions for the following platforms:<br><br>");

    sourceText += tr("- <i> Linux </i><br>"
                     "- <i> Windows </i><br>"
                     "- <i> Android </i><br>"
                     "- <i> Web </i><br>");

    block->setSourceText(sourceText);
    block->setBakcBroundPicture("qrc:/img/images/os.png");


}

