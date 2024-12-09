import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import "components"
Window {
    id: root
    visible: true
    width: 640
    height: 480
//    MouseArea{
//        anchors.fill: parent
//        onClicked: {
//            root.visible = false
//        }
//    }
    Connections{
        target: SCREEN_CTRL
        onSignalsHome:{
//            console.log("da nhan duoc signal __appHome")
            root.visible = true
//            console.log(songTitle)
//            console.log(artistName)
//            console.log(coverArt)
        }
    }

    property var layer_base: layer_base_1
    property bool mVisibleIma: false
    // common screen loader
    //Component.onCompleted: root.showMaximized()
    StatusBar{
        id: screenTop
        height: parent.height/6
        width: parent.width
    }
    Item {
        id: constainScreen
        anchors.top: screenTop.bottom
        height: 5*parent.height/6
        width: parent.width
    }
    Loader {
        id: layer_base_1
        anchors.fill: constainScreen
        onLoaded: {
            switchLayerBase(layer_base_2, layer_base_1);
        }
    }
    Loader {
        id: layer_base_2
        anchors.fill: constainScreen
        onLoaded: {
            switchLayerBase(layer_base_1, layer_base_2);
        }
    }
    function switchLayerBase(from, to) {
        if (from.item !== null) {
            from.item.visible = false
            from.source = ""
        }
        if (to.item !== null) {
            to.item.visible = true
        }
        layer_base = from
    }
    function reloadScreen() {
        layer_base.source = ""
        layer_base.source = SCREEN_MODEL.currentScreen
    }
}
