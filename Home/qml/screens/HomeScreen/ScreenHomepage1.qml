import QtQuick 2.12
import AppEnums 1.0
import "../../components"
Row{

    Connections{
        target: SCREEN_CTRL
        onSignalsHome:{
            console.log("da nhan duoc signal __appHome")
            root.visible = true
            console.log(songTitle)
            console.log(artistName)
            console.log(coverArt)
            idSongTitle.strText = songTitle
            idArtistName.strText = artistName
            imaMusic.source = coverArt
            idSongTitle.startAnimation()
        }
    }
    anchors.centerIn: parent
    spacing: root.width/21
    Rectangle{
        id: recMusic
        height: 3*root.height/5
        width: 3*root.width/7
        color: "#f5f5f5"
        border.width: 1
        border.color: "blue"
        clip: true
        Image {
            id: imaMusic
            height: root.height/5
            width: root.width/7
            anchors.centerIn: recMusic
            source: "qrc:/images/music.png"
        }
        Text {
            id: txtMusic
            font.pixelSize: root.height/24
            text: qsTr("Music")
            anchors.horizontalCenter: recMusic.horizontalCenter
            anchors.top: recMusic.top
            anchors.topMargin: recMusic.height/5
            font.bold: true
        }
        ScrollingText{
            id: idSongTitle
            textSize: root.height/30
            strText: qsTr("Song Title")
            anchors{
                horizontalCenter: recMusic.horizontalCenter
                top: imaMusic.bottom
            }
            onFinishedAnimation: {
                idArtistName.startAnimation()
            }
        }

        //        Text{
        //            id:idSongTitle
        //            text: "Song Title"
        //            font.pixelSize: root.height/30
        //            anchors{
        //                horizontalCenter: recMusic.horizontalCenter
        //                top: imaMusic.bottom
        //            }
        //        }
        ScrollingText{
            id: idArtistName
            textSize: root.height/30
            strText: qsTr("Artist Name")
            anchors{
                horizontalCenter: recMusic.horizontalCenter
                top: idSongTitle.bottom
            }
            onFinishedAnimation: {
                idSongTitle.startAnimation()
            }
        }

//        Text{
//            id:idArtistName
//            text: "Artist Name"
//            font.pixelSize: root.height/30
//            anchors{
//                horizontalCenter: imaMusic.horizontalCenter
//                top: idSongTitle.bottom
//            }
//        }

        MouseArea{
            anchors.fill: parent
            onPressed:  {
                SCREEN_CTRL.broadcastDbusSignal(1)
                root.visible = false
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
    Rectangle{
        id: recVideo
        height: 3*root.height/5
        width: 3*root.width/7
        color: "#f5f5f5"
        border.width: 1
        border.color: "blue"
        Image {
            id: imaVideo
            height: root.height/5
            width: root.width/5
            anchors.centerIn: recVideo
            source: "qrc:/images/video.png"
        }
        Text {
            id: txtVideo
            font.pixelSize: root.height/24
            font.bold: true
            text: qsTr("Video")
            anchors.horizontalCenter: recVideo.horizontalCenter
            anchors.top: recVideo.top
            anchors.topMargin: recVideo.height/5
        }
        MouseArea{
            anchors.fill: parent
            onPressed: {
                SCREEN_CTRL.broadcastDbusSignal(2)
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
}

