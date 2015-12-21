import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1
import org.covolunablu.farm 1.0
import "UI.js" as UI

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
            color: "lightsteelblue"
            Text {
                anchors.centerIn: parent
                text: "Profiles"
                font.pixelSize: 32
            }
            Rectangle {
                // bottom border of the "banner" Rectangle
                anchors.bottom: parent.bottom
                height: 2
                width: parent.width
                color: "#A0B0C5"
            }
        }

        SplitView {
            z: -1
            Layout.fillWidth: true
            Layout.fillHeight: true

            ScrollView {
                Layout.fillHeight: true
                Layout.preferredWidth: 250
                Layout.minimumWidth: 150

                ListView {
                    id: profileListView

                    model: profileList
                    highlight: Rectangle {
                        color: "lightsteelblue"
                        //radius: 5
                    }
                    delegate: profileDelegate
                    focus: true
                }
            }

            Rectangle {
                // profile detailed view
                Layout.fillHeight: true
                Layout.minimumWidth: 150
                Layout.preferredWidth: 150

                Column {
                    anchors.left: parent.left
                    anchors.leftMargin: 8
                    Text { text: '<b>' + profileListView.currentItem.profileData.name + '</b>' }
                    Text { text: 'Mame version: <i>' + profileListView.currentItem.profileData.mameVersion + '</i>'}
                    Text { text: 'Type: <i>' + profileListView.currentItem.profileData.dbType + '</i>' }
                    Text { text: 'Roms: <i>' + profileListView.currentItem.profileData.romNumber + '</i>' }
                    Text { text: 'Data path: <i>' + profileListView.currentItem.profileData.dataPath + '</i>' }
                }

                Button {
                    enabled: !profileListView.currentItem.profileData.active
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    anchors.bottomMargin: 10
                    anchors.rightMargin: 10
                    text: qsTr("Select")
                    onClicked: profileListView.currentItem.profileData.active = true;
                }
            }
        }
    }

    Component {
        id: profileDelegate
        Item {
            property variant profileData: model
            id: profileItem
            width: parent.width; height: child.height+10
            Column {
                anchors.left: parent.left
                anchors.leftMargin: 8
                anchors.verticalCenter: parent.verticalCenter
                id: child
                Text { text: '<b>' + model.name
                        + (model.active ? " (" + qsTr("active") + ")" : "") + '</b>'}
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
        id: profileList2
        ListElement { name: "Default"; dbType: "Dataset"; dataPath: "/var/lib/farm/data/";    romNumber: 55; mameVersion: "14.0"; active: false; }
        ListElement { name: "Ciccolo"; dbType: "Dataset"; dataPath: "/home/test/.farm/data/"; romNumber: 53; mameVersion: "14.0"; active: false; }
        ListElement { name: "Fillo's"; dbType: "OwnRoms"; dataPath: "/home/test/farm/data/";  romNumber: 34; mameVersion: "14.0"; active: false; }
        ListElement { name: "v13";     dbType: "Backup";  dataPath: "/var/lib/farm/data/";    romNumber: 20; mameVersion: "13.0"; active: true;  }
        ListElement { name: "v13.2";   dbType: "Dataset"; dataPath: "/var/lib/farm/data/";    romNumber: 23; mameVersion: "13.2"; active: false; }
    }

}
