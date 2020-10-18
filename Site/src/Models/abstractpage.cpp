#include "abstractpage.h"
#include <infoblock.h>
#include <quasarapp.h>

AbstractPage::AbstractPage()
{

}

QList<BaseFront::Link> AbstractPage::links() const {
    return {};
}

QObject * AbstractPage::makeBlok() const {
    auto block = new BaseFront::InfoBlock();

    block->setTitle(title());
    block->setSourceText(data());
    block->setBakcgroundPicture(backgroud());
    block->setLinks(links());

    return block;
}

