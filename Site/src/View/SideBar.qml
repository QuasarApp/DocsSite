import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Window 2.15

import ViewSolutionsModule 1.0

Drawer {
    id: root
    width: Math.max(parent.width * 0.3, 50 * Screen.pixelDensity)
    height: parent.height

    ListView {
        id: viewPort
        property real globalPos: 0

        delegate: Component {
            ImageView {
                property var data: modelData

                anchors.fill: parent
                soucre:  "qrc:/img/res/LOGO.png"
                text: "QuasarApp"
                toolTip: "QuasarApp Group"
                anchors.margins: 20
                borderColor: "#00a4e1"
            }
        }

    }
}
