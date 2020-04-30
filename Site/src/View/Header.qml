import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Controls.Universal 2.14
import ViewSolutionsModule 1.0
import QtQuick.Layouts 1.14


ToolBar {

    RowLayout {
        id: privateRoot
        property int currrentItem : 0;
        ImageView {
            background: (0 == privateRoot.currrentItem)? Material.accent : Material.background
            Layout.fillHeight: true
            Layout.preferredWidth: height * 0.8
            soucre : "qrc:/img/images/LOGO.png"
            toolTip: qsTr("Back to main page");
            text: qsTr("Home")

            onClicked: {
                privateRoot.currrentItem = 0
            }
        }

        ImageView {
            background: (1 == privateRoot.currrentItem)? Material.accent : Material.background
            Layout.fillHeight: true
            Layout.preferredWidth: height * 0.8
            soucre : "qrc:/img/images/HanoiTowers.png"
            text: qsTr("Hanoi Towers")
            toolTip: qsTr("Simple Crossplatform game");
            onClicked: {
                privateRoot.currrentItem = 1
            }
        }

        Item {
            Layout.fillWidth: true

        }

        anchors.fill: parent
    }

}
