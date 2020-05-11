import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Controls.Universal 2.14
import QtQuick.Layouts 1.14

import ViewSolutionsModule 1.0

Item {

    ListView {
        id: viewPort
        property real globalPos: 0
        anchors.fill: parent
        delegate: Component {
            ViewPortPage {
                viewPortDelegatH: 500
                scrollPos: viewPort.globalPos
                source:  modelData
                viewground: root
                title: "QuasarApp Group"
                text: ""
            }
        }

        ScrollBar.vertical: ScrollBar {
            onPositionChanged: {
                viewPort.globalPos = position
            }
        }

        model: [
            "qrc:/img/res/LOGO.png",
        ]
    }

}
