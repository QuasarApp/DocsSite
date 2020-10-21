#include "heartpage.h"

#include <infoblock.h>


HeartAbout::HeartAbout()
{

}

HeartAbout::~HeartAbout() {

}

QString HeartAbout::data() const
{
    return tr(""
              "<b>QuasarApp Heart</b> - it is base backend for C++/Qt projects. This library support work with databases and work with lite network requests. <br><br>"
              "<h2> Futures </h2><br>"
              "<br> "
              " * Support ssl sockets <br>"
              " * Support initialize database <br>"
              " * Support work in database <br><br>"
              " This library consists of two levels (AbstractNode level and DataBaseNode level).<br>"
              " <br>");
}

QString HeartAbout::title() const {
    return tr("About QuasarApp Heart");
}

QString HeartAbout::backgroud() const {
    return resourcesPath() + "/heart.png";
}

QList<BaseFront::Link> HeartAbout::links() const {
    return {{"More information about suport databases", "https://doc.qt.io/qt-5/sql-driver.html"}};
}

HeartExamples::HeartExamples()
{

}

HeartExamples::~HeartExamples() {

}

QString HeartExamples::data() const {
    return tr(""
              "<b>QuasarApp Heart</b> - has very detailed examples of how the library works,"
              " as well as a complete description of all the functions in the official technical documentation. <br><br>"
              " But if you want to get only a short example of how to use it, you can visit the official page on github.");
}

QString HeartExamples::title() const {
    return tr("Examples of QuasarApp Heart");
}

QString HeartExamples::backgroud() const {
    return resourcesPath() + "/HeartExamples.png";
}

QList<BaseFront::Link> HeartExamples::links() const {
    return {{"official page on github", "https://github.com/QuasarApp/Heart"}};
}

HeartDocs::HeartDocs() {

}

HeartDocs::~HeartDocs() {

}

QString HeartDocs::data() const {
    return tr("<br><br>"
              "**QuasarApp Heart** - if you want get more information see technical documentation."
              "<br><br>"
              );
}

QString HeartDocs::title() const {
    return tr("Doxygen Technical Documentation");
}

QString HeartDocs::backgroud() const {
    return resourcesPath() + "/docs.png";
}

QList<BaseFront::Link> HeartDocs::links() const {
    return {{"technical documentation", "https://quasarapp.ddns.net/docs/heart/html/index.html"}};

}
