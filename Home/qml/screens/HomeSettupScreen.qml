import QtQuick 2.9
import AppEnums 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import "../components"
Item {
    id: itRec
   // property var mSettup: "HomeScreen/ScreenSetupLanguage.qml"
    Rectangle{
        id: recSelection
        height: root.height
        width: root.width/4
        color: "#f5f5f5"
        border.color: 'blue'
        border.width: 1
        BaseButton{
            id: btnLanguage
            anchors.top: parent.top
            mHeight: root.height/5
            mWidth: parent.width
            Text {
                id: txtBtnLanguage
                font.pixelSize: root.height/24
                anchors{
                    left: parent.left
                    leftMargin: parent.mWidth/10
                    top: parent.top
                    topMargin: (btnLanguage.mHeight - root.height/24)/2
                }
                font.bold: true
                color: "red"
                text: qsTr("Language")
            }
            onBtnPressed: {
                txtBtnLanguage.color = "red"
                txtBtnVolume.color = "black"
                txtBtnLanguage.font.bold = true
                txtBtnVolume.font.bold = false
                SETUP_HOME.sourceLanguegeScreen =  "HomeScreen/ScreenSetupLanguage.qml"
            }
        }
        BaseButton{
            id: btnVolume
            x: btnLanguage.x
            y: btnLanguage.y + btnLanguage.mHeight
            mHeight: parent.height/5
            mWidth: parent.width
            Text {
                id: txtBtnVolume
                font.pixelSize: root.height/24
                anchors{
                    left: parent.left
                    leftMargin: parent.mWidth/10
                    top: parent.top
                    topMargin: (btnVolume.mHeight - root.height/24)/2
                }
                color: "black"
                text: qsTr("Volume")
            }
            onBtnPressed: {
                txtBtnLanguage.color = "black"
                txtBtnVolume.color = "red"
                txtBtnLanguage.font.bold = false
                txtBtnVolume.font.bold = true
                SETUP_HOME.sourceLanguegeScreen =  "HomeScreen/ScreenSetupVolume.qml"
            }
        }
    }
    Rectangle{
        id: recRadioButton
        height: parent.height
        width: parent.width - recSelection.width
        border.color: 'blue'
        border.width: 1
        anchors.top: parent.top
        anchors.left: recSelection.right
        Loader{
            anchors.fill: parent
            source: SETUP_HOME.sourceLanguegeScreen
        }
    }
}
