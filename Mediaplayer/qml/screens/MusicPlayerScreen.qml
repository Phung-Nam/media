import QtQuick 2.9
import AppEnums1 1.0
import "../components"
import"../"
import QtQuick.Controls 2.5

Item {
    id: itMusicPlayer
    onWidthChanged :  {
        txtSongTitle.stopAnimation()
        txtAbum.stopAnimation()
        artist.stopAnimation()
        txtSongTitle.startAnimation()
    }
    onHeightChanged: {
        txtSongTitle.stopAnimation()
        txtAbum.stopAnimation()
        artist.stopAnimation()
        txtSongTitle.startAnimation()
    }


    //Component.onCompleted: console.log("kkkkkkkkkkk" + itMusicPlayer.width)
    anchors.fill: parent
    StatusBar{
        id: status1
        height: parent.height/6
        width: parent.width
        onClickedButonHome: {
            SCREEN_CTRL.broadcastDbusSignalButonHome(txtSongTitle.strText,  artist.strText, imaMuic.source )
            root.visible = false
            console.log(imaMuic.source)

        }
        MouseArea{
            anchors.fill: parent
            anchors.leftMargin: status1.width/4
            onClicked: {
                // listSonginFo()
                console.log(idFolderTree.count)
                //SCREEN_CTRL.replaceScreen(AppEnums1.SCREEN_ID_MUSIC_PLAYER)
            }
        }
        Rectangle{
            id: idButonFolder
            color: "White"
            height: parent.height/1.5
            width: height
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            border.width: 2
            Text{
                font.pixelSize: idButonFolder.height/5
                text: qsTr("FOLDER")+ MUSIC_PLAY_CONTROLER.upDateTxt
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onPressed: parent.opacity = 0.3
                onReleased: parent.opacity = 1
                onClicked: {
                    console.log("da nhan nut Folder")
                    MLIST_CTRL.getFileName()
                    SCREEN_CTRL.replaceScreen(AppEnums1.SCREEN_ID_MUSIC_PLAYER)
                    //listSonginFo()

                }
            }
        }

        Rectangle{
            id: idBack
            color: "White"
            height: parent.height/1.5
            width: height
            anchors.right: idButonFolder.left
            anchors.verticalCenter: parent.verticalCenter
            border.width: 2
            Text{
                font.pixelSize: idButonFolder.height/5
                text: qsTr("BACK")+ MUSIC_PLAY_CONTROLER.upDateTxt
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onPressed: parent.opacity = 0.3
                onReleased: parent.opacity = 1
                onClicked: {
                    MLIST_CTRL.clickBack()
                    SCREEN_CTRL.replaceScreen(AppEnums1.SCREEN_ID_MUSIC_PLAYER)
                }
            }
        }
    }

    Rectangle{
        id: recMainMedia
        width: parent.width
        anchors{
            top: status1.bottom
            bottom: parent.bottom
        }

        color: "white"
        border.color: "steelblue"
        border.width: 2
        MusicListScreen{
            id:idMusicList
            z:1
            clip: true
            width: recMainMedia.width/3
            height: recMainMedia.height*0.7
            anchors{
                //top: st1.bottom
                top:recMainMedia.top
                bottom: recMainMedia.bottom
                bottomMargin: recMainMedia.height/4
                right: idFolderTree.left
                //rightMargin: width/7
                left: recMainMedia.horizontalCenter
                leftMargin: 0.1*recMainMedia.width
            }

            Text{
                id:idTextNoHaveMusic
                anchors.centerIn: parent
                font.pixelSize: 30

            }
        }
        ListView{
            id:idFolderTree
            height: idMusicList.height
            width: parent.width/10
            anchors{
                top: idMusicList.top
                right: parent.right
            }
            model:MLIST_CTRL.folderList
            delegate: Rectangle{
                id:idDelegateFolder
                height: idFolderTree.height/10
                width: idFolderTree.width
                border.width: 1
                color: "green"
                Text {
                    id:t12
                    text: modelData
                    anchors.verticalCenter: idDelegateFolder.verticalCenter
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        MLIST_CTRL.clickFolder(t12.text)
                        SCREEN_CTRL.replaceScreen(AppEnums1.SCREEN_ID_MUSIC_PLAYER)
                    }
                }
            }



        }

        Rectangle{
            id:rec1
            //border.width: 1
            clip: true
            //width: itMusicPlayer.width/4
            anchors{
                right: imaMuic.left
                top: parent.top
                topMargin: 0.7*row1.height
                bottom: row1.top
                bottomMargin: row1.height/3
                left: parent.left
                leftMargin: row1.height

            }
            ScrollingText{
                textSize: itMusicPlayer.height/15
                id: txtSongTitle
                strText:  ""
                anchors.top: parent.top
                onFinishedAnimation: {
                    txtAbum.startAnimation()
                }
            }

            ScrollingText{
                textSize: itMusicPlayer.height/20
                id: txtAbum
                strText:  ""
                anchors
                {
                    top: txtSongTitle.bottom
                    topMargin:txtSongTitle.height/2
                }
                onFinishedAnimation: {
                    artist.startAnimation()
                }
            }

            ScrollingText{
                textSize: itMusicPlayer.height/20
                id: artist
                strText:  ""
                anchors
                {
                    top: txtAbum.bottom
                    topMargin:txtAbum.height/2
                }
                onFinishedAnimation: {
                    txtSongTitle.startAnimation()
                }
            }
        }


        Image {
            id: imaMuic
            visible: true
            width: itMusicPlayer.width/7
            height: root.height/4
            x: itMusicPlayer.width/3 + width/10
            y: itMusicPlayer.height/12

        }
        Row{
            id: row1
            spacing: imaBefore.width/2.5
            x: parent.height/6
            anchors{
                bottom: parent.bottom
                bottomMargin: parent.height/3

            }

            Image {
                id: imaBefore
                width: root.width/10
                height: root.height/10
                source: "qrc:/images/LoadBefore"

                MouseArea {
                    anchors.fill: parent
                    onPressed: parent.opacity = 0.3
                    onReleased: parent.opacity = 1
                    onClicked: {
                        if(MLIST_CTRL.getSizeModel() > 0)
                        {

                            if(root.currentIndexLv > 0)
                            {
                                root.currentIndexLv --
                                console.log(root.currentIndexLv )
                                MUSIC_PLAY_CONTROLER.next_prev(root.currentIndexLv)
                                listSonginFo()
                                txtSongTitle.startAnimation()
                                txtAbum.stopAnimation()
                                artist.stopAnimation()
                                if(root.bRun === false) {root.bRun = true}
                            }
                            else if (root.currentIndexLv  ===  0)
                            {
                                MUSIC_PLAY_CONTROLER.next_prev(root.currentIndexLv)
                                listSonginFo()
                                txtSongTitle.startAnimation()
                                txtAbum.stopAnimation()
                                artist.stopAnimation()
                                if(root.bRun === false) {root.bRun = true}
                            }
                        }
                    }
                }
            }

            Image {
                id: imaRun_stop
                width: root.width/10
                height: root.height/10
                source: root.bRun? "qrc:/images/Stop.jpn.jpg":"qrc:/images/Run"

                MouseArea {
                    anchors.fill: parent
                    onPressed: parent.opacity = 0.3
                    onReleased: parent.opacity = 1
                    onClicked: {
                        if(MLIST_CTRL.getSizeModel()>0)
                        {
                            if(root.bRun === true)
                            {
                                MUSIC_PLAY_CONTROLER.pause()
                                root.bRun = false
                            }
                            else
                            {
                                MUSIC_PLAY_CONTROLER.resume()
                                root.bRun = true
                            }
                        }
                    }
                }
            }


            Image {
                id: imaAfter
                width: root.width/10
                height: root.height/10
                source: "qrc:/images/LoadAfter"
                MouseArea {
                    anchors.fill: parent
                    onPressed: parent.opacity = 0.3
                    onReleased: parent.opacity = 1
                    onClicked: {
                        console.log(MLIST_CTRL.getSizeModel())
                        idMusicList.currentIndex +=1
                        //console.log("test current item: "+ idMusicList.currentItem.songTitle)
                        if(root.currentIndexLv < MLIST_CTRL.getSizeModel()-1)
                        {
                            root.currentIndexLv ++
                            txtSongTitle.startAnimation()
                            txtAbum.stopAnimation()
                            artist.stopAnimation()
                            MUSIC_PLAY_CONTROLER.next_prev(root.currentIndexLv)
                            listSonginFo()
                        }

                        if(root.bRun === false) {root.bRun = true}
                    }
                }
            }
        }


        Slider {
            id: tarbarRun
            anchors{
                bottom: parent.bottom
                bottomMargin: itMusicPlayer.height/8
                horizontalCenter: parent.horizontalCenter
            }
            height: itMusicPlayer.height/60
            width: 2.2*itMusicPlayer.width/3
            //from: 0
            //            value: MUSIC_PLAY_CONTROLER.getPosition()
            //to: MUSIC_PLAY_CONTROLER.getDuration()
            onMoved: {
                console.log("onMoved _ nam: "+ value)
                MUSIC_PLAY_CONTROLER.mySetPosition(tarbarRun.value)
            }
        }

        Text {
            id: txtDuration1


            font.pixelSize: itMusicPlayer.height/24
            anchors{
                right: tarbarRun.left
                rightMargin: itMusicPlayer.width/65
                verticalCenter: tarbarRun.verticalCenter
            }

        }


        Text {
            id: txtDuration2
            font.pixelSize: itMusicPlayer.height/24
            anchors{
                left: tarbarRun.right
                leftMargin: itMusicPlayer.width/65
                verticalCenter: tarbarRun.verticalCenter
            }
            text: ""
        }
        Component.onCompleted: {
            //console.log("MUSIC_PLAY_CONTROLER.playWhenLoadListMp3()")
            if(idMusicList.count > 0)
            {
                MUSIC_PLAY_CONTROLER.playWhenLoadListMp3()
                listSonginFo()
            }
            else {MUSIC_PLAY_CONTROLER.noMusic()}
            //    MUSIC_PLAYBACK_MODEL.loadMediaList()
            //(MLIST_CTRL.getSizeModel()>0)?

            //if(MLIST_CTRL.getSizeModel()>0) {listSonginFo()}
            console.log("so luong thu muc: " + idFolderTree.count)
            console.log("so luong bai hat: " + idMusicList.count)
            idTextNoHaveMusic.text = (idMusicList.count === 0)? qsTr("NO MUSIC") + MUSIC_PLAY_CONTROLER.upDateTxt: ""

        }
    }

    Connections{
        target: MUSIC_PLAY_CONTROLER
        onMyPositionChange:{
            //console.log("nam test connect signal: " + position)
            txtDuration1.text = MUSIC_PLAY_CONTROLER.convertMilisecondToMinute(position)
            tarbarRun.value = position

            txtDuration2.text = MUSIC_PLAY_CONTROLER.convertMilisecondToMinute(MUSIC_PLAY_CONTROLER.getDuration())
            tarbarRun.from = 0
            tarbarRun.to = MUSIC_PLAY_CONTROLER.getDuration()
        }
        onMyDurationChange:{
            //console.log("nam test connect signal duration: " + duration)
            txtDuration2.text =   MUSIC_PLAY_CONTROLER.convertMilisecondToMinute(duration)
            tarbarRun.from = 0
            tarbarRun.to = duration
        }
    }

    Connections{
        target: MUSIC_PLAY_CONTROLER
        onSwitchSong:{
            if(root.currentIndexLv < MUSIC_PLAY_CONTROLER.getNumberSong())
            {
                root.currentIndexLv ++
                txtSongTitle.startAnimation()
                txtAbum.stopAnimation()
                artist.stopAnimation()
            }
            console.log(root.currentIndexLv )
            MUSIC_PLAY_CONTROLER.next_prev(root.currentIndexLv)
            listSonginFo()
            idT1.start()
        }
    }

    Timer{
        id: idT1
        interval: 100
        repeat: false
        running: false
        onTriggered: {
            MUSIC_PLAY_CONTROLER.pause()
            MUSIC_PLAY_CONTROLER.resume()
        }
    }
    function listSonginFo()
    {
        console.log("da goi listSonginFo()")
        txtSongTitle.strText  = MUSIC_PLAYBACK_MODEL.getTitle(root.currentIndexLv)

        txtAbum.strText = MUSIC_PLAYBACK_MODEL.getAlbum(root.currentIndexLv)
        artist.strText = MUSIC_PLAYBACK_MODEL.getArtist(root.currentIndexLv)
        imaMuic.source = MUSIC_PLAYBACK_MODEL.getAlbumArt(root.currentIndexLv)

        //              txtSongTitle.strText = idMusicList.itemAtIndex(currentIndexLv).songTitle


        txtSongTitle.stopAnimation()
        txtAbum.stopAnimation()
        artist.stopAnimation()
        txtSongTitle.startAnimation()

        //        //                console.log("getTitle Nam: " + MUSIC_PLAYBACK_MODEL.getTitle(root.currentIndexLv))
        //        //                console.log("getAlbum Nam: " + MUSIC_PLAYBACK_MODEL.getAlbum(root.currentIndexLv))
        //        //                console.log("getArtist Nam: " + MUSIC_PLAYBACK_MODEL.getArtist(root.currentIndexLv))
        //        //                console.log("getAlbumArt Nam: " + MUSIC_PLAYBACK_MODEL.getAlbumArt(root.currentIndexLv))

        //        //        if(txtSongTitle.strText == "") {txtSongTitle.strText = "Unknown"}
        //        //        if(txtAbum.strText == "") {txtAbum.strText = "Unknown"}
        //        //        if(artist.strText == "") {artist.strText = "Unknown"}
        //        //        if(imaMuic.source == "qrc:/images/video") {imaMuic.source = "qrc:/images/MusicIma.jpg"}



    }
}






