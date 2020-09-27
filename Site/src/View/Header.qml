import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Controls.Universal 2.15
import ViewSolutionsModule 1.0
import QtQuick.Layouts 1.15


ToolBar {

    property string currentPage: privateRoot.pages[privateRoot.currentItem]
    signal sideBar()

    RowLayout {
        id: privateRoot
        property int currentItem : 0;
        property var pages: [
            "QuasarApp"
        ]

        ToolButton {
            action: navigateBackAction
            text: "☰"
            font.pointSize: 20
        }

//        ImageView {
//            background: (0 == privateRoot.currentItem)? Material.accent : "#00000000"
//            Layout.fillHeight: true
//            Layout.preferredWidth: height * 1
//            soucre : "qrc:/img/images/LOGO.png"
//            toolTip: qsTr("Back to main page");
//            power: 1.9

//            onClicked: {
//                privateRoot.currentItem = 0
//            }
//        }

//        ImageView {
//            background: (1 == privateRoot.currentItem)? Material.accent : "#00000000"
//            Layout.fillHeight: true
//            Layout.preferredWidth: height * 1
//            soucre : "qrc:/img/images/CQtDeployer logo.png"
//            toolTip: qsTr("Crossplatform tool for deploying cpp applications." +
//                          " The CQtDeployer is application for extract all depends library of executable and create launch script for your application.");

//            power: 1.9
//            onClicked: {
//                privateRoot.currentItem = 1
//            }
//        }

//        ImageView {
//            background: (2 == privateRoot.currentItem)? Material.accent : "#00000000"
//            Layout.fillHeight: true
//            Layout.preferredWidth: height * 1
//            soucre : "qrc:/img/images/Qt-Secret Logo.png"
//            toolTip: qsTr("Fast encryption library supporting RSA and AES algorithms.");

//            power: 1.9
//            onClicked: {
//                privateRoot.currentItem = 2
//            }
//        }

//        ImageView {
//            background: (3 == privateRoot.currentItem)? Material.accent : "#00000000"
//            Layout.fillHeight: true
//            Layout.preferredWidth: height * 1
//            soucre : "qrc:/img/images/HanoiTowers.png"
//            toolTip: qsTr("Simple Crossplatform game");

//            power: 1.9
//            onClicked: {
//                privateRoot.currentItem = 3
//            }
//        }

//        ImageView {
//            background: (4 == privateRoot.currentItem)? Material.accent : "#00000000"
//            Layout.fillHeight: true
//            Layout.preferredWidth: height * 1
//            soucre : "qrc:/img/images/QtBigint Logo.png"
//            toolTip: qsTr("QtBigInt - Arbitrary-sized integer class for C++ and build system qmake and cmake. Power by minigmp.");

//            power: 1.9
//            onClicked: {
//                privateRoot.currentItem = 4
//            }
//        }
        Item {
            Layout.fillWidth: true

        }

        Languages {
            Layout.fillHeight: true
            itemHeigh: privateRoot.height
        }

        Switch {
            text: qsTr("Dark Mode")

            onCheckedChanged: {
                applicationRoot.Material.theme = (checked)? Material.Dark: Material.Light
            }
        }


        anchors.fill: parent
    }

    Action {
        id: navigateBackAction
        onTriggered: {
            sideBar()
        }
    }


}
