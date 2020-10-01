#include "sidebaritem.h"

SideBarItem::SideBarItem(QObject *parent)  : QObject(parent)
{

}

QString SideBarItem::title() const {
    return m_title;
}

QString SideBarItem::description() const {
    return m_description;
}

QString SideBarItem::banner() const {
    return m_banner;
}

void SideBarItem::setTitle(QString title) {
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
}

void SideBarItem::setDescription(QString description) {
    if (m_description == description)
        return;

    m_description = description;
    emit descriptionChanged(m_description);
}

void SideBarItem::setBanner(QString banner) {
    if (m_banner == banner)
        return;

    m_banner = banner;
    emit bannerChanged(m_banner);
}
