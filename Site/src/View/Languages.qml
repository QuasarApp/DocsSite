import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Controls.Universal 2.14
import ViewSolutionsModule 1.0
import QtQuick.Layouts 1.14

RowLayout {
    id: root
    property int currentItem : 0;
    property int itemHeigh : root.parent.height * 0.4;

    onHeightChanged: {
        console.log(height)
    }

    onCurrentItemChanged: {
        mainModel.changeLanguage(currentItem);
    }

    ImageView {
        background: (0 == root.currentItem)? Material.accent : "#00000000"
        Layout.preferredHeight: itemHeigh
        Layout.preferredWidth: itemHeigh
        soucre : "qrc:/img/images/EN.png"
        toolTip: qsTr("Select English language");
        power: 1.9

        onClicked: {
            root.currentItem = 0
        }
    }

    ImageView {
        background: (1 == root.currentItem)? Material.accent : "#00000000"
        Layout.preferredHeight: itemHeigh
        Layout.preferredWidth: itemHeigh
        soucre : "qrc:/img/images/EN.png"
        toolTip: qsTr("Select Russian language");
        power: 1.9

        onClicked: {
            root.currentItem = 1
        }
    }

}
