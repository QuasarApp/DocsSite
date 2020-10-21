#include "cqtdeployerpage.h"

#include <infoblock.h>

CQtDeployerAbout::CQtDeployerAbout()
{

}

QString CQtDeployerAbout::data() const {
    auto sourceText = tr(
                "<h2> What is CQtDeployer</h2> <br><br>"
                "The CQtDeployer is application for extract all depends library of executable and create launch script for your application.<br><br>"
                "<br><br>"
                "Key differences of this program:<br>"
                "* Performance: this program deploys the application several times faster (up to 10 seconds)<br><br>"
                "* Flexibility: this application's got flags that help you to configure the deployment for your or your project's needs<br><br>"
                "* Crossdeploy: this application's support windows and linux distrebutives,"
                " This means that you can use it not only to deploy a project for your platform,"
                " but also to deploy a project on Linux for Windows and vice versa.<br><br>"
                "* Fast create installers : Upon completion of the deployment, you will receive a self-contained installer of your distribution.<br><br>"
                "<br><br>"
                );

    return sourceText;
}

QString CQtDeployerAbout::title() const {
    return tr("What is CQDeployer");
}

QString CQtDeployerAbout::backgroud() const {
    return resourcesPath() + "/cqtdeployer.png";
}

QList<BaseFront::Link> CQtDeployerAbout::links() const {
    return {{tr("get more information"), "https://github.com/QuasarApp/CQtDeployer/blob/master/README.md"}};
}


CQtDeployerExamples::CQtDeployerExamples()
{

}

QString CQtDeployerExamples::data() const {
    auto sourceText = tr("The utility transfers the path to the executable"
                         " files of the deployed programs using the option -bin.<br><br>"
                         " The transferred programs are analyzed and get a list of dependencies."
                         " If the programs being deployed depend on Qt,"
                         " then a list of modules is formed based on the dependencies.<br><br>"
                         " Qt plugins are deployed depending on the qt modules used.<br><br>"
                         " Then qml plugins are copied, if necessary, and standard qt translations.<br><br>"
                         " After completing all the steps described,"
                         " scripts are formed to launch the application.<br><br>"
                         " <h3> For example: </h3> <br><br>"
                         " <h4> Linux </h4> <br>"
                         " cqtdeployer -bin myApp -qmake /media/D/Qt/5.15.2/gcc_64/bin/qmake -qmlDir . <br> <br>"
                         " <h4> Windows </h4><br>"
                         " cqtdeployer -bin myApp.exe -qmake /media/D/Qt/5.12.5/gcc_64/bin/qmake.exe -qmlDir . <br> <br>"
                         " <h4> Where: </h4><br><br>"
                         " * <b>cqtdeployer</b> is a utility call (befor version 1.4 windows version used %cqtdeployer% command).<br><br>"
                         " * <b>-bin</b> - the option for transferring the paths of the application executable files.<br><br>"
                         " * <b>myApp.exe</b> and myApp - the path to the application executable file itself <br><br>"
                         " * <b>-qmake</b> - the option for transferring qmake paths for qt deployment.<br><br>"
                         " * <b>-qmlDir</b> - the option for transferring paths to qml files of the application.<br><br>"
                         );
    return sourceText;
}

QString CQtDeployerExamples::title() const {
    return tr("Deploy any С/С++ application is easy with CQTDeployer");

}

QString CQtDeployerExamples::backgroud() const {
    return resourcesPath() + "/cqtdeployer_screen.png";

}

QList<BaseFront::Link> CQtDeployerExamples::links() const {
    return {{tr("more exampless"), "https://github.com/QuasarApp/CQtDeployer/wiki/quickguide"}};
}

CQtDeployerDocs::CQtDeployerDocs()
{

}

QString CQtDeployerDocs::data() const {
    auto sourceText = tr("The source code for "
                         "CQtDeployer components is provided under Gplv3 licenses and is freely available on GitHub. <br><br>");

    return sourceText;
}

QString CQtDeployerDocs::title() const {
    return tr("More Inforamtions About CQtDeployer");

}

QString CQtDeployerDocs::backgroud() const {
    return resourcesPath() + "/Iconbronzecorp.png";
}

QList<BaseFront::Link> CQtDeployerDocs::links() const {
    return {{tr("Full description and documentation"),
                    "https://github.com/QuasarApp/CQtDeployer/wiki"},

            {tr("Download"),
                    "https://github.com/QuasarApp/CQtDeployer/releases"}};

}
