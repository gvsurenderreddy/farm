import QtQuick 2.4
import QtQuick.Controls 1.3
//import QtQuick.Window 2.2
//import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Hello World")
    width: 480
    height: 640
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

//     ListModel {
//         id: nameModel
//         ListElement { name: "Alice"; team: "Crypto" }
//         ListElement { name: "Bob"; team: "Crypto" }
//         ListElement { name: "Jane"; team: "QA" }
//         ListElement { name: "Victor"; team: "QA" }
//         ListElement { name: "Wendy"; team: "Graphics" }
//     }
//     Component {
//         id: nameDelegate
//         Text {
//             text: modelData;
//             font.pixelSize: 24
//             anchors.left: parent.left
//             anchors.leftMargin: 2
//         }
//     }

    ListView {
        anchors.fill: parent

        model: myModel
        header: bannercomponent
        footer: Rectangle {
            width: parent.width; height: 30;
            gradient: clubcolors
        }
        delegate: Rectangle {
//             height: 25
            id: delegateComponent
            height: child.height
            width: child.width
            Button {
                id: child
                text: modelData
                onClicked: {
                    console.log("MouseArea clicked")
                    delegateComponent.width += 10;
                }
            }
        }
    }

//     ListView {
//         anchors.fill: parent
//         clip: true
//         model: nameModel
//         delegate: nameDelegate
//         focus: true
//         highlight: Rectangle {
//             color: "lightblue"
//             width: parent.width
//         }
//         section {
//             property: "team"
//             criteria: ViewSection.FullString
//             delegate: Rectangle {
//                 color: "#b0dfb0"
//                 width: parent.width
//                 height: childrenRect.height + 4
//                 Text {
//                     anchors.horizontalCenter: parent.horizontalCenter
//                     font.pixelSize: 16
//                     font.bold: true
//                     text: section
//                 }
//             }
//         }
//     }

    Component {     //instantiated when header is processed
        id: bannercomponent
        Rectangle {
            id: banner
            width: parent.width; height: 50
            gradient: clubcolors
            border {color: "#9EDDF2"; width: 2}
            Text {
                anchors.centerIn: parent
                text: "Club Members"
                font.pixelSize: 32
            }
        }
    }
    Gradient {
        id: clubcolors
        GradientStop { position: 0.0; color: "#8EE2FE"}
        GradientStop { position: 0.66; color: "#7ED2EE"}
    }

//    MessageDialog {
//        id: messageDialog
//        title: qsTr("May I have your attention, please?")

//        function show(caption) {
//            messageDialog.text = caption;
//            messageDialog.open();
//        }
//    }
}
