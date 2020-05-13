#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>

#include <BaseFront.h>
#include <viewsolutions.h>

#include "mainmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
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
