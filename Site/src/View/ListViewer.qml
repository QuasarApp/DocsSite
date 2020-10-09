import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Controls.Universal 2.15
import QtQuick.Layouts 1.14

import ViewSolutionsModule 1.0

ListView {
    id: viewPort

    anchors.margins: 24
    anchors.leftMargin: 40
    anchors.rightMargin: 40

    delegate: Component {

        ViewPortGradientPage {
            property var data: modelData
            source:  (data)? data.bakcBroundPicture: ""
            title: (data)? data.title: ""
            text: (data)? data.sourceText: ""
            textMargins: 40
            width: viewPort.width
            viewground: viewPort
            height: 400

        }
    }

    spacing: 24

}
