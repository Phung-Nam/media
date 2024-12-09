import QtQuick 2.9
import AppEnums1 1.0
Rectangle {
    id: recTopScreen
    color: "black"
    signal clickedButonHome()

    DateTime{
        anchors.centerIn: parent
    }
    Image {
        id: btn_home
        height: 0.6*parent.height
        width: height
        source: "qrc:/images/HomeIma"
        anchors {
            verticalCenter: parent.verticalCenter

        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
               // SCREEN_CTRL.popToRoot()

                clickedButonHome()
            }
            onPressed: parent.opacity = 0.3
            onReleased: parent.opacity = 1

        }
    }

//    Image {
//        id: btn_back
//        height: 0.6*parent.height
//        width: height
//        anchors {
//            verticalCenter: parent.verticalCenter
//            left: parent.left
//            leftMargin: 5
//        }

//        source: "qrc:/images/Back"
//        MouseArea {
//            anchors.fill: parent
//            onClicked: {
//                SCREEN_CTRL.popScreen()
//            }
//            onPressed: parent.opacity = 0.3
//            onReleased: parent.opacity = 1
//        }
//    }
}
