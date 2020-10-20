import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Controls.Universal 2.15
import QtQuick.Layouts 1.14
import QtQuick.Window 2.15

import ViewSolutionsModule 1.0

ListView {
    id: viewPort

    anchors.margins: 24
    anchors.leftMargin: 10
    anchors.rightMargin: 10

    delegate: Component {

        InfoBlock {
            property var data: modelData
            source:  (data)? data.bakcBroundPicture: ""
            title: (data)? data.title: ""
            text: (data)? data.sourceText: ""
            sourceTextPixelSize: Math.max(width * 0.015, 3 * Screen.pixelDensity)
            headerTextPixelSize: Math.max(width * 0.03, 6 * Screen.pixelDensity)

            textMargins: 20
            width: viewPort.width - scroll.width
            viewground: viewgroundItem
            listView: viewPort
            linksCount: (data)? data.linksCount: 0
            model: data

        }
    }

    header: Component {
        Item {
        height: viewPort.height / 3
    }}

    footer: Component {
        Item {
        height: viewPort.height / 3
    }}

    populate: Transition {
        NumberAnimation {
            easing.type: Easing.OutExpo
            properties: "opacity";
            duration: 5000
            from: 0
            to: 1.0
        }
    }

    spacing: Math.max(24, width * 0.15)
    ScrollBar.vertical: ScrollBar {
        id: scroll
    }

    Item {
        id: viewgroundItem

        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: parent.width / 2
    }
}
