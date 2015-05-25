import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Rectangle {
    property string title
    title: qsTr("Select Profile")
    anchors.fill: parent


    ColumnLayout {
        anchors.fill: parent
        spacing: 0

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

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 0

            ListView {
                z: -1
                id: profileListView
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.minimumWidth: 100


                model: profileList
                highlight: Rectangle {
                    color: "lightsteelblue"
                    //radius: 5
                }
                delegate: profileDelegate
                focus: true
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 150

                color: "red"
                Column {
                    anchors.left: parent.left
                    anchors.leftMargin: 8
                    Text { text: '<b>' + profileListView.currentItem.profileData.name + '</b>' }
                    Text { text: 'Mame version: <i>' + profileListView.currentItem.profileData.mameVersion + '</i>'}
                    Text { text: 'Type: <i>' + profileListView.currentItem.profileData.dbType + '</i>' }
                    Text { text: 'Roms: <i>' + profileListView.currentItem.profileData.romNumber + '</i>' }
                    Text { text: 'Data path: <i>' + profileListView.currentItem.profileData.dataPath + '</i>' }
                }
            }
        }
    }

    Component {
        id: profileDelegate
        Item {
            property variant profileData: model
            id: profileItem
            width: parent.width; height: child.height
            Column {
                anchors.left: parent.left
                anchors.leftMargin: 8
                anchors.verticalCenter: parent.verticalCenter
                id: child
                Text { text: '<b>' + model.name + '</b>'}
                Text { text: 'Mame version: <i>' + model.mameVersion + '</i>'}
                Text { text: 'Type: <i>' + model.dbType + '</i>' }
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
        ListElement { name: "Default"; dbType: "Dataset"; dataPath: "/var/lib/farm/data/"; romNumber: 55; mameVersion: "14.0"}
        ListElement { name: "Ciccolo"; dbType: "Dataset"; dataPath: "/home/test/.farm/data/"; romNumber: 53; mameVersion: "14.0"}
        ListElement { name: "Fillo's"; dbType: "OwnRoms"; dataPath: "/home/test/farm/data/"; romNumber: 34; mameVersion: "14.0"}
        ListElement { name: "v13";     dbType: "Backup"; dataPath: "/var/lib/farm/data/"; romNumber: 20; mameVersion: "13.0"}
        ListElement { name: "v13.2";   dbType: "Dataset"; dataPath: "/var/lib/farm/data/"; romNumber: 23; mameVersion: "13.2"}
    }

}
