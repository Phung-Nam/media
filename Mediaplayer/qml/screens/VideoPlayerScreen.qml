import QtQuick 2.9
import "../components"
import AppEnums1 1.0
import QtQuick.Controls 2.5
import QtMultimedia 5.5
Item {
    id: name
    height: root.height
    width: root.width
    property bool mVisible: true
    Rectangle {
        id: itVideoPlayer
        height: root.height
        width: root.width
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(mVisible == false)
                {
                    mVisible = true
                    console.log("1")
                }
                else{
                    console.log("2")
                }
            }
        }

        StatusBar{
            id: status1
            height: root.height/6
            width: root.width
            Image {
                id: btn_Zoom
                source: "qrc:/images/Zoom"
                height: 0.6*parent.height
                width: height
                anchors{
                    top: status1.top
                    topMargin: status1.height/2 - height/2
                    left: status1.left
                    leftMargin: (width + 13)*2
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mVisible = false
                    }
                    onPressed: parent.opacity = 0.3
                    onReleased: parent.opacity = 1
                }
            }
        }
        Item {
            id: itVideo
            anchors.top: status1.bottom
            width: root.width
            anchors.bottom: itVideoPlayer.bottom
        }
        VideoOutput {
            fillMode: VideoOutput.Stretch
            anchors.fill: (mVisible)?itVideo:itVideoPlayer
            source: PLAY_VIDEO
        }
        BaseButton{
            id: btnBefore
            visible: mVisible
            anchors{
                top: btnRun.top
                right: btnRun.left
                rightMargin: root.width/8
            }
            onClickMusic: {
            }
            mSource: "qrc:/images/LoadBefore.jpg"
        }
        BaseButton{
            id: btnRun
            visible: mVisible
            anchors{
                verticalCenter: itVideoPlayer.verticalCenter
                left: parent.left
                leftMargin: root.width/2 - root.width/20
            }
            onClickMusic: {
                if(mSourceRun == "qrc:/images/Run.jpg" )
                {
                    mSourceRun = "qrc:/images/Stop.jpn.jpg"

                    PLAY_VIDEO.requestPlay()
                }
                else if(mSourceRun == "qrc:/images/Stop.jpn.jpg")
                {
                    mSourceRun = "qrc:/images/Run.jpg"
                    PLAY_VIDEO.pauseVideo()
                }
                timer1.restart()

            }
            mSource: mSourceRun
        }
        BaseButton{
            id: btnAfter
            visible: mVisible
            anchors{
                top: btnRun.top
                left: btnRun.right
                leftMargin: root.width/8
            }
            onClickMusic: {
            }
            mSource: "qrc:/images/LoadAfter.jpg"
        }
        Slider {
            id: tarbarRun
            z:0
            visible: mVisible
            anchors{
                bottom: parent.bottom
                bottomMargin: root.height/8
                left: parent.left
                leftMargin: root.width/8
            }
            height: root.height/60
            width: 2*root.width/3
            from: 1
            value: 0
            to: 100

        }
        Text {
            id: txtDuration1
            visible: mVisible
            font.pixelSize: root.height/24
            anchors{
                right: tarbarRun.left
                rightMargin: root.width/40
                verticalCenter: tarbarRun.verticalCenter
            }
            text: qsTr("0:00")
        }
        Text {
            id: txtDuration2
            visible: mVisible
            font.pixelSize: root.height/24
            anchors{
                left: tarbarRun.right
                leftMargin: root.width/40
                verticalCenter: tarbarRun.verticalCenter
            }
            text: qsTr("5:00")
        }
    }
    Timer {
        id: timer1
        interval: 10000; running: (mVisible); repeat: false
        onTriggered: mVisible = false
    }

}
