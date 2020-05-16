#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>
#include <QFont>
#include <QFontDatabase>

#include <BaseFront.h>
#include <viewsolutions.h>

#include "mainmodel.h"
#include "quasarapp.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    int id = QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Regular.ttf");
    QFont appFont(QFontDatabase::applicationFontFamilies(id).at(0));
    app.setFont(appFont);

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;

    QObject::connect(QuasarAppUtils::Locales::instance(), &QuasarAppUtils::Locales::sigTranslationChanged,
                     &engine, &QQmlApplicationEngine::retranslate);


    if (!ViewSolutions::init(&engine)) {
        return -1;
    }

    if (!BaseFront::init(&engine)) {
        return -2;
    }

    auto root = engine.rootContext();

    auto mainModel = MainModel();

    root->setContextProperty("mainModel", &mainModel);


    const QUrl url(QStringLiteral("qrc:/View/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-3);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
