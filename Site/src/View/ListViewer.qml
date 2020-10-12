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

        ViewPortGradientPage {
            property var data: modelData
            source:  (data)? data.bakcBroundPicture: ""
            title: (data)? data.title: ""
            text: (data)? data.sourceText: ""
            sourceTextPixelSize: Math.max(width * 0.02, 4 * Screen.pixelDensity)
            headerTextPixelSize: Math.max(width * 0.04, 8 * Screen.pixelDensity)

            textMargins: 20
            width: viewPort.width
            viewground: viewgroundItem
            listView: viewPort

        }
    }

    spacing: 24

    Item {
        id: viewgroundItem

        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: parent.width / 2
    }
}
