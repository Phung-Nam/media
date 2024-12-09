
import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    anchors.fill:parent
    property alias controlSlider: controlSlider
    Slider {
        id: controlSlider
        from: 0
        to: 10
        //value: 5
        stepSize: 1
        orientation: Qt.Horizontal
        height: 10
        width: parent.width - 200
        anchors.centerIn: parent
        onValueChanged: {
            console.log(value)
            SETUP_HOME.myValueVolume = controlSlider.value*10
        }
        Component.onCompleted: {
            controlSlider.value = SETUP_HOME.myValueVolume/10
        }

        background: Rectangle {
            id:rect
            height: 15
            width: parent.width
            color: "transparent"
            radius: 5
            border {
                width: 1
                color: "black"
            }
            Rectangle {
                height: 13
                radius: 4
                width: controlSlider.visualPosition * parent.width
                color: "lightblue"
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        handle: Rectangle {
            x: controlSlider.visualPosition * controlSlider.availableWidth
            implicitWidth: 40
            implicitHeight:40
            radius: width / 2
            color: controlSlider.pressed?"blue":"white"
            border.color: "lightblue"
            border.width: 2
            anchors.verticalCenter: parent.verticalCenter
            Text {
                anchors.centerIn: parent
                color: "black"
                font.pixelSize: 15
                text: controlSlider.value
            }
        }
    }
}
