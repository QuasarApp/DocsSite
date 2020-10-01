import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Controls.Universal 2.15
import ViewSolutionsModule 1.0
import QtQuick.Layouts 1.14

RowLayout {
    id: root
    property int currentItem : 0;
    property int itemHeigh : root.parent.height ;

    onCurrentItemChanged: {
        mainModel.changeLanguage(currentItem);
    }

    ToolButton {
        Layout.preferredHeight: itemHeigh
        Layout.preferredWidth: itemHeigh
        text : "EN"

        onClicked: {
            root.currentItem = 0
        }

        ToolTip {
            parent: parent
            visible: parent.hovered
            text: qsTr("Select English language")
            delay: 500

        }

    }

    ToolButton {
        Layout.preferredHeight: itemHeigh
        Layout.preferredWidth: itemHeigh
        text : "RU"

        ToolTip {
            parent: parent
            visible: parent.hovered
            text: qsTr("Select Russian language");
            delay: 500

        }

        onClicked: {
            root.currentItem = 1
        }
    }

}
