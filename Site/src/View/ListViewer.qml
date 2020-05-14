import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Controls.Universal 2.14
import QtQuick.Layouts 1.14

import ViewSolutionsModule 1.0

ListView {
    id: viewPort
    property real globalPos: 0
    anchors.fill: parent
    anchors.margins: 40
    delegate: Component {
        ViewPortPage {
            property var data: block
            scrollPos: viewPort.globalPos
            source:  (data)? data.bakcBroundPicture: ""
            viewground: viewPort
            title: (data)? data.title: ""
            text: (data)? data.sourceText: ""
            textMargins: 40
        }
    }

    spacing: 10

    ScrollBar.vertical: ScrollBar {
        onPositionChanged: {
            viewPort.globalPos = position
        }
        visible: false

    }

}
