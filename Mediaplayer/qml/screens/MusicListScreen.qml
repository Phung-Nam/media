import QtQuick 2.9
import "../"
import "../components"



//Item {
//    id: root1
////    anchors.fill: parent
////    StatusBar{
////        z:1
////        id:st1
////        anchors{
////            top: parent.top
////        }
////        width: parent.width
////        height: parent.height/6
////    }

    ListView{
        id:idLV


        model: MLIST.model
        spacing: 10

        delegate: Item {
            property string songTitle: idt1.text
            id: it1
            height:idLV.height/10
            width: idLV.width
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    root.currentIndexLv = index
                    MUSIC_PLAY_CONTROLER.play(idt1.text)
                    console.log(idt1.text)
                    if(root.bRun === false) {root.bRun = true}
                    itMusicPlayer.listSonginFo()
                }
            }
            Image {
                id:idIm1
                anchors.verticalCenter: it1.verticalCenter
                x: parent.height/2
                height: 0.8*it1.height
                width: height
                source: "qrc:/images/MusicImaRun.jpg"
                visible: index ==root.currentIndexLv? true:false
            }

            Text {
                id:idt1
                text: modelData
                anchors.verticalCenter:  parent.verticalCenter
                x: index == root.currentIndexLv?parent.height/2+idIm1.width+idIm1.width/2 :parent.height/2
                font.pixelSize: it1.height/3
                color: index == root.currentIndexLv?"red":"black"
                font.bold: index ==root.currentIndexLv? true:false
            }
            Rectangle{
                height: 1
                width: parent.width*0.97
                color: "blue"
                anchors{
                    bottom: parent.bottom
                    horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }
//}






































