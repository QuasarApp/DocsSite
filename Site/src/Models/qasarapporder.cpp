#include "qasarapporder.h"

QasarAppOrder::QasarAppOrder()
{

}

QString QasarAppOrder::data() const {
    auto sourceText = tr("We are always happy to help you realize your best and most fantastic ideas."
                    "<br><br>"
                    "If you have an idea for the application, then you can leave a request to create a project with us on GitHub."
                    " All that is required of you is a detailed description of what needs to be done. Further,"
                    " our specialists will decide when work will begin on the project and how much resources will be allocated to the project."
                    "<br><br>"
                    "That how many resources will be allocated for the development depends on how much this project will collect cash donations."
                    "<br><br>"
                    "You can also request a private project exclusively for you, but such a project can no longer be free.");

    return sourceText;
}

QString QasarAppOrder::title() const {
    return tr("Order a project.");
}

QString QasarAppOrder::backgroud() const {
    return resourcesPath() + "/icongoldcorp.png";
}
