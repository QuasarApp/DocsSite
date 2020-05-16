#include "mainmodel.h"
#include "reader.h"
#include <quasarapp.h>

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

void MainModel::changeLanguage(int code) {

    QString prefix = "Translations";

    switch (static_cast<Languages>(code)) {

    case Languages::EN: {
        if (!QuasarAppUtils::Locales::setLocale(QLocale::Language::English, "Site")) {
            QuasarAppUtils::Params::log("set language failed!");
        }
        break;
    }

    case Languages::RU: {
        if (!QuasarAppUtils::Locales::setLocale(QLocale::Language::Russian, "Site", "_", ":/translations/translations/")) {
            QuasarAppUtils::Params::log("set language failed!");
        }
        break;
    }

    default:
        QuasarAppUtils::Locales::setLocale(prefix);
    }
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
                            "Our company has ben created on 2017 year and have experians of develepment android and desctop applications and games."
                            "<br><br>");

    sourceText += tr("During our existence, we have accumulated more than 40 software components and ready-made solutions for the most diverse tasks.<br>"
                     "This approach allows us now to create final products with impressive speed. If you have an idea for the application, we will hear you."
                     );

    block->setSourceText(sourceText);
    block->setBakcBroundPicture("qrc:/img/images/LOGO.png");


    block = new BaseFront::InfoBlock(this);
    _QuasarAppPage->push_back(block);

    block->setTitle(tr("Supported Platforms"));

    sourceText = tr("At the moment, we can offer support for our solutions for the following platforms:<br><br>");

    sourceText += tr("- <i> Linux </i><br>"
                     "- <i> Windows </i><br>"
                     "- <i> Android </i><br>"
                     "- <i> Web </i>");

    block->setSourceText(sourceText);
    block->setBakcBroundPicture("qrc:/img/images/os.png");

    block = new BaseFront::InfoBlock(this);
    _QuasarAppPage->push_back(block);

    block->setTitle(tr("Order a project."));

    sourceText = tr("We are always happy to help you realize your best and most fantastic ideas."
                    "<br><br>"
                    "If you have an idea for the application, then you can leave a request to create a project with us on GitHub."
                    " All that is required of you is a detailed description of what needs to be done. Further,"
                    " our specialists will decide when work will begin on the project and how much resources will be allocated to the project."
                    "<br><br>"
                    "That how many resources will be allocated for the development depends on how much this project will collect cash donations."
                    "<br><br>"
                    "You can also request a private project exclusively for you, but such a project can no longer be free.");

    block->setSourceText(sourceText);
    block->setBakcBroundPicture("qrc:/img/images/os.png");


}

