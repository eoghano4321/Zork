import QtQuick 2.15

Item {

    Loader {
        id: loader
        x: 0
        y: 0
        width: 640
        height: 480

        Rectangle {
            id: rectangle
            x: 0
            y: 402
            width: 640
            height: 78
            color: "#616161"

            Rectangle {
                id: west
                x: 482
                y: 24
                width: 36
                height: 31
                color: "#ffffff"

                Text {
                    id: westtxt
                    x: 0
                    y: 0
                    width: 36
                    height: 31
                    text: qsTr("West")
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Rectangle {
                id: east
                x: 566
                y: 24
                width: 36
                height: 31
                color: "#ffffff"

                Text {
                    id: easttxt
                    x: 0
                    y: 0
                    width: 36
                    height: 31
                    text: qsTr("East")
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Rectangle {
                id: south
                x: 524
                y: 45
                width: 36
                height: 31
                color: "#ffffff"
                state: "n"

                Text {
                    id: southtxt
                    x: 0
                    y: 0
                    width: 36
                    height: 31
                    text: qsTr("South")
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Rectangle {
                id: rectangle1
                x: 199
                y: 8
                width: 243
                height: 62
                color: "#ffffff"

                Text {
                    id: output
                    x: 0
                    y: 0
                    width: 243
                    height: 62
                    text: qsTr("Output Text")
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            MouseArea {
                id: northbtn
                x: 524
                y: 11
                width: 36
                height: 28
                cursorShape: Qt.OpenHandCursor

                Rectangle {
                    id: north
                    x: 0
                    y: -3
                    width: 36
                    height: 31
                    color: "#ffffff"
                    state: "n"

                    Text {
                        id: northtxt
                        x: 0
                        y: 0
                        width: 36
                        height: 31
                        text: qsTr("North")
                        font.pixelSize: 12
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }
        }

        Image {
            id: background
            x: 0
            y: 0
            width: 640
            height: 401
            source: "qrc:/qtquickplugin/images/template_image.png"
            fillMode: Image.PreserveAspectFit
        }
    }
}
