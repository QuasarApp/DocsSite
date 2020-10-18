#include "heart.h"

Heart::Heart()
{

}

QString Heart::description() const {
    return tr("QuasarApp Heart - it is base backend for C++/Qt projects."
              " This library support work with databases and work with lite network requests. ");
}

QString Heart::title() const {
    return "QuasarApp Heart";
}

QString Heart::backgroud() const {
    return resourcesPath() + "/heart_banner.png";
}

QString Heart::projectName() const {
    return "Heart";
}
