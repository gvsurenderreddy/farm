import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Rectangle {
    property string title
    title: qsTr("Select Profile")
    anchors.fill: parent


    ColumnLayout {
        anchors.fill: parent
        Rectangle {
            id: banner
            height: 50
            Layout.fillWidth: true
            gradient: clubcolors
            border {color: "#9EDDF2"; width: 2}
            Text {
                anchors.centerIn: parent
                text: "Profiles"
                font.pixelSize: 32
            }
        }
        ListView {
            z: -1
            id: profileListView
            Layout.fillWidth: true
            Layout.fillHeight: true


            model: profileList
            highlight: Rectangle {
                color: "lightsteelblue"
                radius: 5
            }
            delegate: profileDelegate
            focus: true
        }
    }

    Component {
        id: profileDelegate
        Item {
            id: profileItem
            width: parent.width; height: child.height
            Column {
                anchors.left: parent.left
                anchors.leftMargin: 8
                anchors.verticalCenter: parent.verticalCenter
                id: child
                Text { text: '<b>Name:</b> ' + name }
                Text { text: '<b>Team:</b> ' + team }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: profileListView.currentIndex = index
            }
        }

    }


    // fake temporary ListModel
    ListModel {
        id: profileList
        ListElement { name: "Alice"; team: "Crypto" }
        ListElement { name: "Bob"; team: "Crypto" }
        ListElement { name: "Jane"; team: "QA" }
        ListElement { name: "Victor"; team: "QA" }
        ListElement { name: "Wendy"; team: "Graphics" }
    }

}
