import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import ViewSolutionsModule 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ImageView {
        anchors.fill: parent
        soucre:  "qrc:/img/images/HanoiLogoAlpha.png"
        text: "Logo of Hanoi towers"
        anchors.margins: 100
//        background: "red"
        borderColor: "red"
    }
}
