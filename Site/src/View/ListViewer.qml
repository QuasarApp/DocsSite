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
    delegate: Component {
        ViewPortPage {
            viewPortDelegatH: viewPort.height * 0.8
            scrollPos: viewPort.globalPos
            source:  modelData
            viewground: viewPort
            title: titleTxt
            text: sourceTxt
        }
    }

    ScrollBar.vertical: ScrollBar {
        onPositionChanged: {
            viewPort.globalPos = position
        }
    }

}
