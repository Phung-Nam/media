import QtQuick 2.9
import AppEnums 1.0
Rectangle{
    id: recSetting
    anchors.top: parent.top
    anchors.topMargin: root.height/8.5
    anchors.left: parent.left
    anchors.leftMargin: root.width/21
    height: 3*root.height/5
    width: 3*root.width/7
    color: "#f5f5f5"
    border.width: 1
    border.color: "blue"
    Image {
        id: imaSetting
        height: root.height/5
        width: root.width/5
        anchors.centerIn: recSetting
        source: "qrc:/images/setting.png"
    }
    Text {
        id: txtSetting
        font.pixelSize: root.height/24
        text: qsTr("Settings")
        anchors.horizontalCenter: recSetting.horizontalCenter
        anchors.top: recSetting.top
        anchors.topMargin: recSetting.height/5
    }
    MouseArea {
        anchors.fill: recSetting
        onClicked: {
            mVisibleIma = true
            SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_HOME_SETTUP)
        }
        hoverEnabled : true
        onEntered: {
            parent.opacity = 0.3
        }
        onExited: {
            parent.opacity = 1
        }

    }
}

