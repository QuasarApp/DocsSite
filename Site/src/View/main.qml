import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import ViewSolutionsModule 1.0

ApplicationWindow {
    id: applicationRoot
    visible: true
    width: 1280
    height: 720
    title: qsTr("QuasarApp Docs")

    Material.theme: Material.Light
    Material.accent: Material.LightBlue
    Material.primary: "#404142"

    header: Header {
        height: 15 * Screen.pixelDensity
        width: applicationRoot.width

        Connections {
            target: header
            function onSideBar() {
                drawer.open()
            }
        }

        onCurrentPageChanged: {
            mainModel.openPage(currentPage);
        }
    }

    contentData:
        ListViewer {
        id: sourceList
        model: (mainModel)? mainModel.pageModel: null
        anchors.fill: parent
    }

    SideBar {
        id: drawer
        model: (mainModel)? mainModel.pageListModel: null

    }

}
