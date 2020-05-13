import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import ViewSolutionsModule 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Material.theme: Material.Light
    Material.accent: Material.LightBlue
//    Material.background: Material.Teal
//    Material.foreground: Material.Pink
    Material.primary: Material.Teal

    header: Header {
        height: root.height * 0.2

        onCurrentPageChanged: {
            mainModel.openPage(currentPage);
        }
    }

    contentData: StackView {
        id: stackView
        initialItem: ListViewer {
            id: sourceList
            model: mainModel.listModel

            anchors.fill: parent

        }
        anchors.fill: parent

    }

}
