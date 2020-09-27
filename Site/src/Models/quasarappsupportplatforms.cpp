#include "quasarappsupportplatforms.h"

QuasarAppSupportPlatforms::QuasarAppSupportPlatforms()
{

}

QString QuasarAppSupportPlatforms::data() const {
    auto sourceText = tr("At the moment, we can offer support for our solutions for the following platforms:<br><br>");

    sourceText += tr("- <i> Linux </i><br>"
                     "- <i> Windows </i><br>"
                     "- <i> Android </i><br>"
                     "- <i> Web </i>");

    return sourceText;
}

QString QuasarAppSupportPlatforms::title() const {
    return tr("Supported Platforms");
}

QString QuasarAppSupportPlatforms::backgroud() const {
    return resourcesPath() + "/crossplatforms.png";
}
