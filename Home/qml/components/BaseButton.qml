import QtQuick 2.9

Item {
    property string mColor: "#f5f5f5"
    property var mHeight
    property var mWidth
    signal btnPressed()
    signal btnReleased()
    Rectangle{
        id: recBtn
        color: mColor
        height: mHeight
        width: mWidth
        border.color: "blue"
        border.width: 1
        MouseArea{
            anchors.fill: parent
            onPressed: {
                btnPressed()
                mColor = "blue"
            }
            onReleased: {
                btnReleased()
                mColor = "#f5f5f5"
            }
        }
    }
}
