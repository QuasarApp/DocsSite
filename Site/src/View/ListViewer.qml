import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Controls.Universal 2.14
import QtQuick.Layouts 1.14

import ViewSolutionsModule 1.0

ListView {
    id: viewPort
    property real globalPos: 0



    anchors.margins: 24
    anchors.leftMargin: 40
    anchors.rightMargin: 40
    delegate: Component {
        ViewPortGradientPage {
            property var data: block
            scrollPos: viewPort.globalPos
            source:  (data)? data.bakcBroundPicture: ""
            viewPortDelegatW: viewPort.width
            viewground: viewgroundItem
            title: (data)? data.title: ""
            text: (data)? data.sourceText: ""
            textMargins: 40
        }
    }

    spacing: 24

    ScrollBar.vertical: ScrollBar {
        onPositionChanged: {
            viewPort.globalPos = position
        }
        visible: false

    }

    Item{
        id: viewgroundItem
        anchors.left: parent.horizontalCenter
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom

    }

}
