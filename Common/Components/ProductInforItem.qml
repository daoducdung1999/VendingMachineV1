import QtQuick 2.15
import QtQuick.Controls 2.15
import "."
import "../"

Item {
    property string imgSource: ""
    property string itemName: ""
    property string itemCost: ""
    signal itemClick()
    Image {
        id: img
        anchors.fill: parent
        anchors.bottomMargin: parent.height * 1/4
        anchors.margins: 8
        source: imgSource
        fillMode: Image.Stretch
    }

    Rectangle {
        anchors.fill: parent
        anchors.topMargin: parent.height * 3/4
        anchors.bottomMargin: parent.height * 1/8
        color: CommonStyles.transparentColor
        Label {
            anchors.centerIn: parent
            text: itemName
            wrapMode: Text.WordWrap
            font.pointSize: CommonStyles.fontSizeDefault - 5
            font.family: CommonStyles.notoSanFontRegular
            font.bold: true
            color: CommonStyles.textColor
        }
    }

    Label {
        anchors.top: parent.top
        anchors.topMargin: parent.height * 0.875
        anchors.right: parent.right
        anchors.rightMargin: parent.width * 0.05
        text: itemCost
        wrapMode: Text.WordWrap
        font.pointSize: CommonStyles.fontSizeDefault - 2
        font.family: CommonStyles.notoSanFontRegular
        color: CommonStyles.primaryColor
    }

    MouseArea {
        anchors.fill: parent
        onClicked:
        {
            itemClick()
        }
    }
}
