import QtQuick 2.9
import "../components"

Item {
    id: root
    Rectangle{
        color: "red"
        height: parent.height
        width: parent.width
        anchors.fill: parent
        Text {
            id: txt
            text: qsTr("VideoListScreen")
        }
    }
}
