#include "mainmodel.h"
#include "quasarapppage.h"
#include "reader.h"
#include <qasarapporder.h>
#include <quasarapp.h>
#include <quasarappsupportplatforms.h>

MainModel::MainModel(QObject *parent) : QObject(parent) {
    setPageModel(new ViewSolutions::ListViewModel(this));
    setPageListModel(new ViewSolutions::ListViewModel(this));
    _reader = new BaseFront::Reader();
    initQuasarApp();
}

void MainModel::clearPages() {
    for (auto value : _QuasarAppPages) {
        if (value) {
            for (auto object: *value) {
                delete object;
            }
            value->clear();
        }
    }
    _QuasarAppPages.clear();
}

MainModel::~MainModel() {
    delete _reader;
    clearPages();
}

bool MainModel::openPage(const QString &url) {

    auto list = _QuasarAppPages.value(url, nullptr);
    if (list) {
        _pageModel->setExternalSource(list);
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

QObject *MainModel::pageModel() const {
    return _pageModel;
}

QObject *MainModel::pageListModel() const {
    return _pageListModel;
}

void MainModel::setPageModel(QObject *pageModel) {
    auto model = dynamic_cast<ViewSolutions::ListViewModel*>(pageModel);

    if (!model || _pageModel == model)
        return;

    _pageModel = model;
    emit pageModelChanged(_pageModel);
}

void MainModel::setPageListModel(QObject *pageListModel) {
    auto model = dynamic_cast<ViewSolutions::ListViewModel*>(pageListModel);

    if (!model || _pageListModel == model)
        return;

    _pageListModel = model;
    emit pageListModelChanged(_pageListModel);
}

template<class Type>
void makePage(QList<QObject *> *page, const Type& blockData) {
    page->push_back(blockData.makeBlok());
}

template<class Type, class ... Types>
void makePage(QList<QObject *> *page, const Type& blockData, const Types& ... data) {
    if (page) {
        page->push_back(blockData.makeBlok());
        makePage(page, data...);
    }
}

void MainModel::initQuasarApp() {
    auto page = new QList<QObject*>();
    makePage(page, QuasarAppPage{}, QuasarAppSupportPlatforms{}, QasarAppOrder{});
    _QuasarAppPages.insert("QuasarApp", page);

}

