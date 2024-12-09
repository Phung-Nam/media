import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import "components"
import "screens"
Window {
    id: root
    visible: /*false*/ true
    property int currentIndexLv: 0  // chi so current index cua listview
    property var mSourceRun: "qrc:/images/Run.jpg"
    property bool bRun: true
    Connections
    {
        target: SCREEN_CTRL
        onVisibleMedia:{
            root.visible = true
            root.showMaximized()
        }
    }
    Connections{
        target: MUSIC_PLAY_CONTROLER
        onSignalplayWhenLoadListMp3:{
            currentIndexLv = 0
        }
    }

    width: 640
    height: 480
    property var layer_base: layer_base_1
    // nhan signal

//ê

    // common screen loader
    Item {
        id: constainScreen
        height: root.height
        width: root.width
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
