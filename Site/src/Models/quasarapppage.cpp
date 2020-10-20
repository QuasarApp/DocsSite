#include "quasarapppage.h"
//=========================================================== QuasarAppPage ========================================================
QuasarAppPage::QuasarAppPage() {

}

QString QuasarAppPage::data() const {

    auto sourceText = tr("The **QuasarApp** is developing open source mobile and desktop"
                         " applications.\n\n"
                         "Our company has been created on 2017 year and have"
                         " experians of develepment android and desctop applications and games."
                         "\n\n");

    sourceText += tr("During our existence,"
                     " we have accumulated more than 40 software components and ready-made solutions"
                     " for the most diverse tasks. \n\n"
                     "This approach allows us now to create final products with impressive speed."
                     " If you have an idea for the application, we will hear you."
                     );
    return sourceText;
}

QString QuasarAppPage::title() const {
    return tr("QuasarApp Group");
}

QString QuasarAppPage::backgroud() const {
    return resourcesPath() + "/quasarapp.png";
}

//================================================== QuasarAppSupportPlatforms ========================================================

QuasarAppSupportPlatforms::QuasarAppSupportPlatforms()
{

}

QString QuasarAppSupportPlatforms::data() const {
    auto sourceText = tr("At the moment, we can offer support for our solutions for the following platforms:\n\n");

    sourceText += tr("* Linux \n"
                     "* Windows \n"
                     "* Android \n"
                     "* Web \n");

    return sourceText;
}

QString QuasarAppSupportPlatforms::title() const {
    return tr("Supported Platforms");
}

QString QuasarAppSupportPlatforms::backgroud() const {
    return resourcesPath() + "/crossplatforms.png";
}

//================================================== QasarAppOrder ========================================================

QasarAppOrder::QasarAppOrder()
{

}

QString QasarAppOrder::data() const {
    auto sourceText = tr("We are always happy to help you realize your best and most fantastic ideas."
                    "\n\n"
                    "If you have an idea for the application, then you can leave a request to create a project with us on GitHub. \n\n"
                    " All that is required of you is a detailed description of what needs to be done. Further,"
                    " our specialists will decide when work will begin on the project and how much resources will be allocated to the project."
                    "\n\n"
                    "That how many resources will be allocated for the development depends on how much this project will collect cash donations."
                    "\n\n"
                    "You can also request a private project exclusively for you, but such a project can no longer be free.");

    return sourceText;
}

QString QasarAppOrder::title() const {
    return tr("Order a project.");
}

QString QasarAppOrder::backgroud() const {
    return resourcesPath() + "/icongoldcorp.png";
}
