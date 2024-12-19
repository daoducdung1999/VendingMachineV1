import QtQuick 2.15
import QtQuick.Controls.Basic
import "."
import "../"

Button {
    id: button
    implicitHeight: 78
    implicitWidth: 78

    property string buttonName: ""
    property int buttonRadius: 0
    property int textSize: CommonStyles.fontSizeDefault
    property color textColor: CommonStyles.whiteColor
    property color btnColor: CommonStyles.primaryColor
    property color btnBorderColor: CommonStyles.primaryColor

    background: Rectangle {
        id: btn
        anchors.fill: parent
        radius: buttonRadius
        color: btnColor
        border.color: btnBorderColor

        MouseArea {
            id: ma
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                button.clicked()
            }
        }
    }

    Text {
        id: text
        anchors.centerIn: parent
        text: buttonName
        font.family: CommonStyles.notoSanFontRegular
        font.weight: Font.Bold
        font.pointSize: textSize
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: textColor
        font.bold: true
    }
}
