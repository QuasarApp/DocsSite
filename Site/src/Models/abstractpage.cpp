#include "abstractpage.h"
#include <infoblock.h>
#include <quasarapp.h>

AbstractPage::AbstractPage()
{

}

QObject * AbstractPage::makeBlok() const {
    auto block = new BaseFront::InfoBlock();

    block->setTitle(title());
    block->setSourceText(data());
    block->setBakcBroundPicture(backgroud());

    return block;
}

QString AbstractPage::resourcesPath() const {
    return "image://curhost/plugins/images";
}
