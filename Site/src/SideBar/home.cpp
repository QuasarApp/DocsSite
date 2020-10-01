#include "home.h"

Home::Home()
{

}

QString Home::description() const {
    return tr("Back to main page");
}

QString Home::title() const {
    return tr("Main page");
}

QString Home::backgroud() const {
    return "QuasarApp.png";
}
