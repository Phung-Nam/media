import QtQuick 2.9

Rectangle {
    id: recTopScreen
    color: "black"
    DateTime{
    anchors.centerIn: parent
    }
    Image {
        id: btn_home
        visible: mVisibleIma
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: 10
        }
        source: "qrc:/images/homeBtn"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                SCREEN_CTRL.popToRoot()
                mVisibleIma = false
            }
        }
    }

    Image {
        id: btn_back
        visible: mVisibleIma
        anchors {
            verticalCenter: parent.verticalCenter
            left: btn_home.right
            leftMargin: 20
        }
        source: "qrc:/images/backBtn"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                mVisibleIma = false
                SCREEN_CTRL.popScreen()
            }
        }
    }
}
