#include "infoblock.h"
namespace BaseFront {

InfoBlock::InfoBlock(QObject *parent) : QObject(parent) {

}

QString InfoBlock::title() const {
    return m_title;
}

QString BaseFront::InfoBlock::sourceText() const {
    return m_sourceText;
}

QString InfoBlock::bakcBroundPicture() const {
    return m_bakcBroundPicture;
}

QString InfoBlock::linkName(int index) const {
    return m_links.value(index).name;
}

QString InfoBlock::linkAddress(int index) const {
    return m_links.value(index).link;
}

int InfoBlock::linksCount() const {
    return m_links.size();
}

void InfoBlock::setLinks(const QList<Link> &links) {
    m_links = links;
}

void InfoBlock::setTitle(QString title) {
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
}

void InfoBlock::setSourceText(QString sourceText) {
    if (m_sourceText == sourceText)
        return;

    m_sourceText = sourceText;
    emit sourceTextChanged(m_sourceText);
}

void InfoBlock::setBakcgroundPicture(QString bakcBroundPicture) {
    if (m_bakcBroundPicture == bakcBroundPicture)
        return;

    m_bakcBroundPicture = bakcBroundPicture;
    emit bakcBroundPictureChanged(m_bakcBroundPicture);
}

uint qHash(const InfoBlock &obj) {
    return qHash(obj.title() + obj.sourceText() + obj.bakcBroundPicture());
}

Link::Link(const QString &name, const QString &link) {
    this->name = name;
    this->link = link;
}

}
