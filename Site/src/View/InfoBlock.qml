import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Controls.Universal 2.15
import QtQuick.Layouts 1.14
import QtQuick.Window 2.15
import QtGraphicalEffects 1.15

import ViewSolutionsModule 1.0

ViewPortGradientPage {
    id: root
    property int linksCount: 0
    property var model: null

    viewPortDelegatH: header.paintedHeight + header.anchors.bottomMargin + header.anchors.topMargin + sourceText.paintedHeight + sourceText.anchors.bottomMargin + sourceText.anchors.topMargin + (linksCount + 1)  * (sourceTextPixelSize + 25 + textLayout.spacing)

    content:
        Item {
        id: privatePage

        clip: true
        TextEdit {
            id: header
            font.bold: true
            font.pixelSize: headerTextPixelSize
            text: title;
            color: fontColor

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            clip: true
            height: paintedHeight

            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: textMargins

            selectByMouse: true
            readOnly: true

            layer.effect: DropShadow {
                verticalOffset: 0
                color: "#80000000"
                radius: 1
                samples: 3
            }
        }

        ColumnLayout {
            id : textLayout
            anchors.bottom: parent.bottom
            anchors.top: header.bottom
            anchors.left: parent.left
            anchors.horizontalCenter: parent.Center
            anchors.margins: textMargins
            width: parent.width / 2

            TextEdit {
                id: sourceText
                font.bold: false
                font.pixelSize: sourceTextPixelSize
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                text: root.text
                color: fontColor
                readOnly: true
                selectByMouse: true
                textFormat: TextEdit.MarkdownText

                wrapMode: Text.WordWrap

                Layout.fillWidth: true
                Layout.fillHeight: true

                layer.enabled: true
                layer.effect: DropShadow {
                    verticalOffset: 0
                    color: "#80000000"
                    radius: 1
                    samples: 3
                }


            }

            Repeater {
                model: linksCount

                Button {
                    text: root.model.linkName(index)

                    onClicked: {
                        Qt.openUrlExternally(root.model.linkAddress(index));
                    }
                    font.pixelSize: sourceTextPixelSize
                }
            }
        }

    }
}
