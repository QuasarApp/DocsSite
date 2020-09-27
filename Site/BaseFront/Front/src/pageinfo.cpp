#include "pageinfo.h"
namespace BaseFront {

PageInfo::PageInfo() {

}

QString PageInfo::banner() const {
    return m_banner;
}

QString PageInfo::shortCut() const {
    return m_shortCut;
}

QString PageInfo::page() const {
    return m_page;
}

void PageInfo::setBanner(QString banner) {
    if (m_banner == banner)
        return;

    m_banner = banner;
    emit bannerChanged(m_banner);
}

void BaseFront::PageInfo::setShortCut(QString shortCut) {
    if (m_shortCut == shortCut)
        return;

    m_shortCut = shortCut;
    emit shortCutChanged(m_shortCut);
}

void PageInfo::setPage(QString page) {
    if (m_page == page)
        return;

    m_page = page;
    emit pageChanged(m_page);
}

}
