import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import "."
import "../"

Rectangle {
    property string imgSource: ""
    property bool visibleThis: true
    border.color: CommonStyles.gray25
    color: CommonStyles.gray15
    radius: parent.width * 0.01
    Rectangle {
        anchors.fill: parent
        color: CommonStyles.transparentColor
        visible: visibleThis

        Label {
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            text: "Ordered\nItem"
            font.pixelSize: parent.height * 0.2
            font.family: CommonStyles.notoSanFontRegular
            font.bold: true
            color: CommonStyles.textColor
        }
    }

    Image {
        anchors.fill: parent
        source: imgSource
        fillMode: Image.Stretch
    }
}
