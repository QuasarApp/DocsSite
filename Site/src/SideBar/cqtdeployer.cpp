#include "cqtdeployer.h"

CQtDeployer::CQtDeployer()
{

}

QString CQtDeployer::description() const {
    return tr("Crossplatform tool for deploying cpp applications."
              " The CQtDeployer is application for extract all depends library of executable and create launch script for your application.");
}

QString CQtDeployer::title() const {
    return "CQtDeployer";
}

QString CQtDeployer::backgroud() const {
    return "CQtDeployer.png";
}
