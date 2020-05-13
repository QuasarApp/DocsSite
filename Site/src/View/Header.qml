import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Controls.Universal 2.14
import ViewSolutionsModule 1.0
import QtQuick.Layouts 1.14


ToolBar {

    property string currentPage: privateRoot.pages[privateRoot.currentItem]

    RowLayout {
        id: privateRoot
        property int currentItem : 0;
        property var pages: [
            "QuasarApp"
        ]
        ImageView {
            background: (0 == privateRoot.currentItem)? Material.accent : Material.background
            Layout.fillHeight: true
            Layout.preferredWidth: height * 0.8
            soucre : "qrc:/img/images/LOGO.png"
            toolTip: qsTr("Back to main page");
            text: qsTr("Home")

            onClicked: {
                privateRoot.currentItem = 0
            }
        }

        ImageView {
            background: (1 == privateRoot.currentItem)? Material.accent : Material.background
            Layout.fillHeight: true
            Layout.preferredWidth: height * 0.8
            soucre : "qrc:/img/images/CQtDeployer logo.png"
            text: qsTr("CQtDeployer")
            toolTip: qsTr("Crossplatform tool for deploying cpp applications." +
                          " The CQtDeployer is application for extract all depends library of executable and create launch script for your application.");
            onClicked: {
                privateRoot.currentItem = 1
            }
        }

        ImageView {
            background: (2 == privateRoot.currentItem)? Material.accent : Material.background
            Layout.fillHeight: true
            Layout.preferredWidth: height * 0.8
            soucre : "qrc:/img/images/Qt-Secret Logo.png"
            text: qsTr("Qt-Secret")
            toolTip: qsTr("Fast encryption library supporting RSA and AES algorithms.");
            onClicked: {
                privateRoot.currentItem = 2
            }
        }

        ImageView {
            background: (3 == privateRoot.currentItem)? Material.accent : Material.background
            Layout.fillHeight: true
            Layout.preferredWidth: height * 0.8
            soucre : "qrc:/img/images/HanoiTowers.png"
            text: qsTr("Hanoi Towers")
            toolTip: qsTr("Simple Crossplatform game");
            onClicked: {
                privateRoot.currentItem = 3
            }
        }

        ImageView {
            background: (4 == privateRoot.currentItem)? Material.accent : Material.background
            Layout.fillHeight: true
            Layout.preferredWidth: height * 0.8
            soucre : "qrc:/img/images/QtBigint Logo.png"
            text: qsTr("QtBigInt")
            toolTip: qsTr("QtBigInt - Arbitrary-sized integer class for C++ and build system qmake and cmake. Power by minigmp.");
            onClicked: {
                privateRoot.currentItem = 4
            }
        }
        Item {
            Layout.fillWidth: true

        }

        anchors.fill: parent
    }

}
