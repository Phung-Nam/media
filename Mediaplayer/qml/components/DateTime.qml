import QtQuick 2.0

Item {
    property string timeString: Qt.formatTime(new Date(),"hh:mm AP")
    property string dateString: new Date().toLocaleDateString(Qt.locale("vi_VN"),"MM.dd")
    Text {
            id: txtTime
            text: timeString
            color: "white"
            font.bold: true
            font.pointSize: root.height/20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
        Text {
            id: txtDate
            text: dateString
            color: "white"
            font.pixelSize: txtTime.font.pixelSize/2
            anchors.left: txtTime.right
            anchors.bottom: txtTime.bottom
            anchors.bottomMargin: 3.5
        }
    Timer
        {
            interval: 1000
            running: true
            repeat: true
            onTriggered:
            {
                timeString = Qt.formatTime(new Date(),"hh:mm AP")
                dateString = new Date().toLocaleDateString(Qt.locale("vi_VN"),"MM.dd")
            }
        }
}
