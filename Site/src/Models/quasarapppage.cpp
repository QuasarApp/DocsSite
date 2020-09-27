#include "quasarapppage.h"

QuasarAppPage::QuasarAppPage() {

}

QString QuasarAppPage::data() const {

    auto sourceText = tr("The <b>QuasarApp</b> is developing open source mobile and desktop"
                         " applications.<br><br>"
                         "Our company has been created on 2017 year and have"
                         " experians of develepment android and desctop applications and games."
                         "<br><br>");

    sourceText += tr("During our existence,"
                     " we have accumulated more than 40 software components and ready-made solutions"
                     " for the most diverse tasks.<br>"
                     "This approach allows us now to create final products with impressive speed."
                     " If you have an idea for the application, we will hear you."
                     );
    return sourceText;
}

QString QuasarAppPage::title() const {
    return tr("QuasarApp Group");
}

QString QuasarAppPage::backgroud() const {
    return resourcesPath() + "/LOGO.png";
}
