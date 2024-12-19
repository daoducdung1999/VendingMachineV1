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

    background: Rectangle {
        id: btn
        anchors.fill: parent
        radius: buttonRadius
        color: CommonStyles.transparentColor
        border.color: CommonStyles.primaryColor

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
        color: CommonStyles.whiteColor
        font.bold: true
    }

    function setToFocusColor() {
        btn.color = CommonStyles.primaryColor
        text.color = CommonStyles.whiteColor
    }

    function setToMainColor() {
        btn.color = CommonStyles.transparentColor
        text.color = CommonStyles.primaryColor
    }
}
