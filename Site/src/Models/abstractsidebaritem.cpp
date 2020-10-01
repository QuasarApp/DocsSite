#include "abstractsidebaritem.h"

#include <sidebaritem.h>

AbstractSideBarItem::AbstractSideBarItem()
{

}

QObject *AbstractSideBarItem::makeBlok() const {
    auto block = new SideBarItem();

    block->setTitle(title());
    block->setDescription(description());
    block->setBanner(backgroud());

    return block;
}
