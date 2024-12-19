import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import "."
import "../"

Item {
    property string name: ""
    property string quantity: ""
    property string cost: ""
    property int total: 0
    signal btnSubClicked()
    signal btnAddClicked()

    Label {
        id: nameLb
        horizontalAlignment: Text.AlignLeft
        anchors.verticalCenter: parent.verticalCenter
        wrapMode: Text.WordWrap
        text: name + " " + quantity
        font.pixelSize: parent.height * 0.5
        font.family: CommonStyles.notoSanFontRegular
        font.bold: true
        color: CommonStyles.textColor
    }

    Rectangle {
        id: rect0
        anchors.fill: parent
        anchors.leftMargin: parent.width * 0.5
        color: CommonStyles.transparentColor

        Label
        {
            id: lb
            width: parent.width * 0.5
            horizontalAlignment: Text.AlignRight
            anchors.verticalCenter: parent.verticalCenter
            wrapMode: Text.WordWrap
            text: cost
            font.pixelSize: rect0.height * 0.5
            font.family: CommonStyles.notoSanFontRegular
            font.bold: true
            color: CommonStyles.secondaryColor
        }

        Rectangle {
            anchors.fill: parent
            anchors.leftMargin:  parent.width * 0.5
            color: CommonStyles.transparentColor

            Rectangle {
                anchors.right: rec2.left
                width: rect0.height * 0.5
                height: rect0.height * 0.5
                anchors.verticalCenter: parent.verticalCenter
                color: CommonStyles.transparentColor
                Image {
                    id: subBtn
                    anchors.fill: parent
                    source: "qrc:/Image/Components/minus.svg"
                    fillMode: Image.Stretch
                }
                MouseArea {
                    anchors.fill: parent
                    enabled: parseInt(total) > 0
                    onClicked: {
                        btnSubClicked()
                    }
                }
            }

            Rectangle {
                id: rec2
                anchors.right: rec1.left
                width: rect0.height * 0.9
                height: rect0.height * 0.6
                anchors.verticalCenter: parent.verticalCenter
                color: CommonStyles.transparentColor

                Label {
                    id: totalLb
                    anchors.centerIn: parent
                    wrapMode: Text.WordWrap
                    font.pixelSize: rect0.height*0.5
                    font.family: CommonStyles.notoSanFontRegular
                    color: CommonStyles.secondaryColor
                    text: total
                }

            }

            Rectangle {
                id: rec1
                anchors.right: parent.right
                width: rect0.height * 0.5
                height: rect0.height * 0.5
                anchors.verticalCenter: parent.verticalCenter
                color: CommonStyles.transparentColor
                Image {
                    id: addBtn
                    anchors.fill: parent
                    source: "qrc:/Image/Components/add.svg"
                    fillMode: Image.Stretch
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        btnAddClicked()
                    }
                }
            }
        }
    }

    Rectangle {
        anchors.bottom: parent.bottom
        width: parent.width
        height: rect0.height * 0.03
        color: CommonStyles.secondaryColor
    }
}
