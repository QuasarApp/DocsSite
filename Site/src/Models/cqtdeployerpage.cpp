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
    auto sourceText = tr("The utility transfers the path to the executable files of the deployed programs using the option -bin. The transferred programs are analyzed and get a list of dependencies. If the programs being deployed depend on Qt, then a list of modules is formed based on the dependencies. Qt plugins are deployed depending on the qt modules used. Then qml plugins are copied, if necessary, and standard qt translations. After completing all the steps described, scripts are formed to launch the application. <br><br><br>"
                         "For example: <br><br>"
                         "<h4>Linux</h4>:<br>"
                         "cqtdeployer -bin myApp -qmake /media/D/Qt/5.15.2/gcc_64/bin/qmake -qmlDir .<br>"
                         "<h4>Windows</h4>:<br>"
                         "cqtdeployer -bin myApp.exe -qmake /media/D/Qt/5.12.5/gcc_64/bin/qmake.exe -qmlDir . <br>"
                         "Where:<br>"
                         "<br>• cqtdeployer is a utility call (befor version 1.4 windows version used %cqtdeployer% command)."
                         "<br>• - bin - the option for transferring the paths of the application executable files."
                         "<br>• myApp.exe and myApp - the path to the application executable file itself"
                         "<br>• - qmake - the option for transferring qmake paths for qt deployment."
                         "<br>• - qmlDir - the option for transferring paths to qml files of the application."
                         "<br><br> For more exampless you can see the our wiki <a href='https://github.com/QuasarApp/CQtDeployer/wiki/quickguide'>page</a>"
                         );
    return sourceText;
}

QString CQtDeployerExamples::title() const {
    return tr("Get started");

}

QString CQtDeployerExamples::backgroud() const {
    return resourcesPath() + "/cqtdeployer_screen.png";

}

CQtDeployerDocs::CQtDeployerDocs()
{

}

QString CQtDeployerDocs::data() const {
    auto sourceText = tr("The source code for CQtDeployer components is provided under Gplv3 licenses and is freely available on GitHub. <br><br>"
                         "* Full description and documentation: available <a href='https://github.com/QuasarApp/CQtDeployer/wiki'>here</a>"
                         "Download <a href='https://github.com/QuasarApp/CQtDeployer/releases'>Page</a>");

    return sourceText;
}

QString CQtDeployerDocs::title() const {
    return tr("More Inforamtions About CQtDeployer");

}

QString CQtDeployerDocs::backgroud() const {
    return resourcesPath() + "/Iconbronzecorp.png";
}
