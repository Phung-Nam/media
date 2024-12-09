import QtQuick 2.9
import AppEnums 1.0
import QtQuick.Controls 2.12
import "HomeScreen"
Item {
    id: name
    SwipeView{
        id: view
        anchors.fill: parent
        Item {
            id: screen1
            ScreenHomepage1{}
        }
        Item {
            id: screen2
            ScreenHomePage2{}
        }
    }
    Row{
        spacing: 20
        anchors{
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
            bottomMargin: 30
        }

        Rectangle{
            width: 40
            height: 10
            color: view.currentIndex == 0 ? "blue" : "white"
            border{
                width: 1
                color: "blue"
            }
        }
        Rectangle{
            width: 40
            height: 10
            color: view.currentIndex == 1 ? "blue" : "white"
            border{
                width: 1
                color: "blue"
            }
        }
    }
}


