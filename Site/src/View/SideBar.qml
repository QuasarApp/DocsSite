import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Window 2.15

import ViewSolutionsModule 1.0

Drawer {
    id: root
    width: Math.max(parent.width * 0.3, 50 * Screen.pixelDensity)
    height: parent.height

    property var model: null

    ListView {
        id: viewPort
        model: root.model

        delegate: Component {
            ImageView {
                property var data: modelData

                soucre:  modelData.banner
                text: modelData.title
                toolTip: modelData.description
                anchors.margins: 20
                borderColor: "#00a4e1"
                power: 0.4

                height: width * 0.3
                width: root.width

                onClicked: {
                    mainModel.openPage(modelData.path);
                }
            }

        }

        anchors.fill: parent
    }
}
