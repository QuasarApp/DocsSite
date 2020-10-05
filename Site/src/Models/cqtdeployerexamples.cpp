#include "cqtdeployerexamples.h"

CQtDeployerExamples::CQtDeployerExamples()
{

}

QString CQtDeployerExamples::data() const {
    auto sourceText = tr("");
    return sourceText;
}

QString CQtDeployerExamples::title() const {
    return tr("Get CQtDeployer");

}

QString CQtDeployerExamples::backgroud() const {
    return resourcesPath() + "/cqtdeployer_screen.png";

}
