import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import AppEnums 1.0
Item{
    id: recRadioButton
    RadioButton {
        x: parent.x
        y: parent.y + root.height/10- root.height/48
        id: rad1
       // checked: true
        font.pixelSize: root.height/24
        Text {
            id: txtRadio1
            anchors{
                left: rad1.right
                leftMargin: root.width/48
                verticalCenter: rad1.verticalCenter
            }
            font.pixelSize: root.height/24
            font.bold: true
            color: "red"
            text: qsTr("English")
        }
        onClicked: {
            txtRadio1.font.bold = true
            txtRadio2.font.bold = false
            txtRadio1.color = "red"
            txtRadio2.color = "black"
            SETUP_HOME.language = "English"
            // SCREEN_CTRL.replaceScreen()(AppEnums.)
        }
    }
    RadioButton {
        id: rad2
        checked: !rad1.checked
        x: parent.x
        y: parent.y + 3*root.height/10 -root.height/48
        font.pixelSize: root.height/24
        Text {
            id: txtRadio2
            anchors{
                left: rad2.right
                leftMargin: root.width/48
                verticalCenter: rad2.verticalCenter
            }
            font.pixelSize: root.height/24
            text: qsTr("VietNam")
        }
        onClicked: {
            txtRadio1.font.bold = false
            txtRadio2.font.bold = true
            txtRadio2.color = "red"
            txtRadio1.color = "black"
            SETUP_HOME.language = "VietNam"
            //SCREEN_CTRL.replaceScreen()(AppEnums.SCREEN_ID_HOME_SETTUP)
        }
    }
    Rectangle{
        height: 1
        width: parent.width
        color: "blue"
        x: parent.x
        y: parent.y + root.height/5-1
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
    }
    Rectangle{
        height: 1
        width: parent.width
        color: "blue"
        x: parent.x
        y: parent.y + 2*root.height/5-1
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
    }
    Component.onCompleted: {
        if(SETUP_HOME.language === "VietNam")
        {
            rad1.checked = false
            rad2.checked = true
            txtRadio1.font.bold = false
            txtRadio2.font.bold = true
            txtRadio2.color = "red"
            txtRadio1.color = "black"
        }
        else if (SETUP_HOME.language === "English")
        {
            rad1.checked = true
            rad2.checked = false
            txtRadio1.font.bold = true
            txtRadio2.font.bold = false
            txtRadio1.color = "red"
            txtRadio2.color = "black"
        }

    }
}
