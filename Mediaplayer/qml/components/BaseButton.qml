import QtQuick 2.9

Item {
    property var mSource
    signal clickMusic()
    Image {
        width: root.width/10
        height: root.height/10
        source: mSource
        MouseArea {
            anchors.fill: parent
            onClicked: {
               clickMusic()
            }
            onPressed: {
                parent.scale = 0.8
            }
            onReleased: {
                parent.scale = 1
            }
        }
    }
}
