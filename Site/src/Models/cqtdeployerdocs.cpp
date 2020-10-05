#include "cqtdeployerdocs.h"

CQtDeployerDocs::CQtDeployerDocs()
{

}

QString CQtDeployerDocs::data() const {
    auto sourceText = tr("");

    return sourceText;
}

QString CQtDeployerDocs::title() const {
    return tr("More Inforamtions About CQtDeployer");

}

QString CQtDeployerDocs::backgroud() const {
    return resourcesPath() + "/Iconbronzecorp.png";
}
