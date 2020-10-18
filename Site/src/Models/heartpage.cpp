#include "heartpage.h"


HeartAbout::HeartAbout()
{

}

HeartAbout::~HeartAbout() {

}

QString HeartAbout::data() const
{
    return tr(""
              "QuasarApp Heart - it is base backend for C++/Qt projects. This library support work with databases and work with lite network requests. <br><br>"
              "<h2> Futures </h2> <br> <br>"
              "<br> "
              "<br> * [YES]Support ssl sockets <"
              "<br> * [YES] Support initialize database "
              "<br> * [YES] Support work in database "
              "<br> * [STILL NO] Support decentralized network mode "
              "<br> This library consists of two levels (AbstractNode level and DataBaseNode level)."
              "<br> "
              "<br> <h3> AbstractNode level (0) </h3>"
              "<br> <h4> Description </h4>"
              "<br>The AbstractNode level implement only base functions of create a new work threads and parsing packages."
              "<br>For more information see QuasarApp Heart documentation, QH namespace."
              "<br>"
              "<br> <h3> DataBaseNode level (1)</h3>"
              "<br> <h4> Description<h4>"
              "The DataBaseNode level implement methods and packages for work with databases."
              " This level using Qt classes for wrking with database,"
              " so for more information about suport databases see "
              "<a href='https://doc.qt.io/qt-5/sql-driver.html'>Qt Documentation</a>.");
}

QString HeartAbout::title() const {
    return tr("About QuasarApp Heart");
}

QString HeartAbout::backgroud() const {
    return resourcesPath() + "/heart_banner.png";
}

HeartExamples::HeartExamples()
{

}

HeartExamples::~HeartExamples() {

}

QString HeartExamples::data() const {
    return tr("<br>"
              "QuasarApp Heart - has very detailed examples of how the library works,"
              " as well as a complete description of all the functions in the official technical documentation."
              " But if you want to get only a short example of how to use it, you can visit the official page on <a href='https://github.com/QuasarApp/Heart'>github</a>.");
}

QString HeartExamples::title() const {
    return tr("Examples of QuasarApp Heart");
}

QString HeartExamples::backgroud() const {
    return resourcesPath() + "/HeartExamples.png";
}

HeartDocs::HeartDocs() {

}

HeartDocs::~HeartDocs() {

}

QString HeartDocs::data() const {
    return tr("<br>"
              "QuasarApp Heart - if you want get more information see "
              "the <a href='docs/heart/html/index.html'>technical documentation</a>."
              );
}

QString HeartDocs::title() const {
    return tr("Doxygen Technical Documentation");
}

QString HeartDocs::backgroud() const {
    return resourcesPath() + "/docs.png";
}
