#include "cqtdeployerpage.h"

CQtDeployerAbout::CQtDeployerAbout()
{

}

QString CQtDeployerAbout::data() const {
    auto sourceText = tr("The CQtDeployer is application for extract all depends library of executable and create"
                         " launch script for your application."
                         "<br><br><br>"
                         " Key differences of this program:"
                         "<br><br>"
                         "* Performance: this program deploys the application several times faster (up to 10 seconds)"
                         "<br><br>"
                         "* Flexibility: this application's got flags that help you to configure the deployment"
                         " for your or your project's needs"
                         "<br><br>"
                         "* Crossdeploy: this application's support windows and linux distrebutives,"
                         " This means that you can use it not only to deploy a project for your platform,"
                         " but also to deploy a project on Linux for Windows and vice versa."
                         "<br><br>"
                         "* Fast create installers : Upon completion of the deployment,"
                         " you will receive a self-contained installer of your distribution."
                         );

    return sourceText;
}

QString CQtDeployerAbout::title() const {
    return tr("Deploy any С/С++ application is easy with CQTDeployer");
}

QString CQtDeployerAbout::backgroud() const {
    return resourcesPath() + "/cqtdeployer.png";
}


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

CQtDeployerDocs::CQtDeployerDocs()
{

}

QString CQtDeployerDocs::data() const {
    auto sourceText = tr("CQtDeployer project have a ");

    return sourceText;
}

QString CQtDeployerDocs::title() const {
    return tr("More Inforamtions About CQtDeployer");

}

QString CQtDeployerDocs::backgroud() const {
    return resourcesPath() + "/Iconbronzecorp.png";
}
