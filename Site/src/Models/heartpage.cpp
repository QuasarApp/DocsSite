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
              "**QuasarApp Heart** - it is base backend for C++/Qt projects. This library support work with databases and work with lite network requests. \n"
              "## Futures \n"
              "\n "
              "\n * [YES]Support ssl sockets "
              "\n * [YES] Support initialize database "
              "\n * [YES] Support work in database "
              "\n * [STILL NO] Support decentralized network mode "
              "\n This library consists of two levels (AbstractNode level and DataBaseNode level)."
              "\n "
              "\n ### AbstractNode level (0) "
              "\n #### Description "
              "\n The AbstractNode level implement only base functions of create a new work threads and parsing packages."
              "\n For more information see QuasarApp Heart documentation, QH namespace."
              "\n "
              "\n  ### DataBaseNode level (1)"
              "\n  #### Description"
              "The DataBaseNode level implement methods and packages for work with databases."
              " This level using Qt classes for wrking with database.");
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
              "QuasarApp Heart - has very detailed examples of how the library works,"
              " as well as a complete description of all the functions in the official technical documentation. \n"
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
    return tr("\n"
              "**QuasarApp Heart** - if you want get more information see technical documentation."
              "\n"
              );
}

QString HeartDocs::title() const {
    return tr("Doxygen Technical Documentation");
}

QString HeartDocs::backgroud() const {
    return resourcesPath() + "/docs.png";
}

QList<BaseFront::Link> HeartDocs::links() const {
    return {{"technical documentation", "docs/heart/html/index.html"}};

}
