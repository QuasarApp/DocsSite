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
