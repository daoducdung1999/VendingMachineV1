import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls.Basic
import QtQuick.Layouts
import "./Common/"
import "./Common/Components/"
import Flux 1.0

Rectangle {
    property string imgSource: ""
    signal btnCancelClicked()
    signal btnConfirmClicked()
    anchors.fill: parent
    anchors.leftMargin: parent.width * 0.02
    anchors.rightMargin: parent.width * 0.02
    color: CommonStyles.backGroundColor

    onVisibleChanged: {
        btn1.setToFocusColor()
        btn2.setToMainColor()
        btn3.setToMainColor()
        //
        listView.model = MainWindowStore.productInfoDetailItem.additionalProtein
    }

    //image and ingredient
    Rectangle {
        anchors.fill: parent
        anchors.topMargin: parent.height * 0.01
        anchors.bottomMargin: parent.height * 0.78
        color: CommonStyles.transparentColor

        Image {
            id: img
            anchors.fill: parent
            anchors.rightMargin: parent.width * 0.7
            source: imgSource
            fillMode: Image.Stretch
        }

        Rectangle {
            anchors.fill: parent
            anchors.leftMargin: parent.width * 0.31
            color: CommonStyles.transparentColor

            Label {
                id: name
                anchors.top: parent.top
                width: parent.width
                horizontalAlignment: Text.AlignLeft
                text: MainWindowStore.productInfoDetailItem.name
                wrapMode: Text.WordWrap
                font.pointSize: CommonStyles.fontSizeDefault + 1
                font.family: CommonStyles.notoSanFontRegular
                font.bold: true
                color: CommonStyles.textColor
            }

            Label {
                id: ingredient
                anchors.top: name.bottom
                width: parent.width
                anchors.topMargin: parent.height * 0.05
                horizontalAlignment: Text.AlignLeft
                text: MainWindowStore.productInfoDetailItem.ingredient
                wrapMode: Text.WordWrap
                font.pointSize: CommonStyles.fontSizeDefault
                font.family: CommonStyles.notoSanFontRegular
                color: CommonStyles.textColor
            }
        }
    }

    ButtonGroup {
        id: groupBtn
        onClicked: function(button) {
            button.setToFocusColor()
            for(var i = 0; i < buttons.length; i++) {
                if(buttons[i] !== button) {
                    buttons[i].setToMainColor()
                }
            }
        }
    }

    //btn area
    RowLayout {
        anchors.fill: parent
        anchors.topMargin: parent.height * 0.23
        anchors.bottomMargin: parent.height * 0.7
        spacing: parent.width * 0.03

        TabViewButton {
            id: btn1
            Layout.preferredHeight: 1
            Layout.preferredWidth: 1
            Layout.fillHeight: true
            Layout.fillWidth: true
            buttonName: "Add Protein"
            ButtonGroup.group: groupBtn
            buttonRadius: parent.width * 0.04
            onClicked: {
                listView.model = MainWindowStore.productInfoDetailItem.additionalProtein
            }
        }

        TabViewButton {
            id: btn2
            Layout.preferredHeight: 1
            Layout.preferredWidth: 1
            Layout.fillHeight: true
            Layout.fillWidth: true
            buttonName: "Add Nutrients"
            ButtonGroup.group: groupBtn
            buttonRadius: parent.width * 0.04
            onClicked: {
                listView.model = MainWindowStore.productInfoDetailItem.additionalNutrients
            }
        }

        TabViewButton {
            id: btn3
            Layout.preferredHeight: 1
            Layout.preferredWidth: 1
            Layout.fillHeight: true
            Layout.fillWidth: true
            buttonName: "Add Ice"
            ButtonGroup.group: groupBtn
            buttonRadius: parent.width * 0.04
            onClicked: {
            }
        }
    }

    //detail
    ListView {
        id: listView
        anchors.fill: parent
        anchors.topMargin: parent.height * 0.33
        anchors.bottomMargin: parent.height * 0.3
        clip: true
        ScrollBar.vertical: ScrollBar {
            policy: listView.count > 4 ? ScrollBar.AlwaysOn : ScrollBar.AlwaysOff
            anchors.right: parent.right
            width: parent.width * 0.02
        }
        model: MainWindowStore.productInfoDetailItem.additionalProtein
        delegate: Rectangle {
            width: listView.width
            height: listView.height / 4
            color: CommonStyles.transparentColor
            IngredientItem {
                anchors.fill: parent
                anchors.margins: parent.width * 0.01
                name: model.object.name
                quantity: model.object.quantity + "g"
                cost: "₩ " + model.object.cost
                totalAmount: model.object.amount

                onBtnSubClicked: {

                }

                onBtnAddClicked: {

                }
            }
        }
    }

    //price
    Rectangle {
        anchors.fill: parent
        anchors.topMargin: parent.height * 0.71
        anchors.bottomMargin: parent.height * 0.20
        color: CommonStyles.transparentColor

        Label {
            anchors.left: parent.left
            anchors.top: parent.top
            text: "Order Amount"
            font.pixelSize: parent.height * 0.6
            font.family: CommonStyles.notoSanFontRegular
            font.bold: true
            font.weight: Font.Bold
            color: CommonStyles.textColor
        }

        Label {
            anchors.right: parent.right
            anchors.top: parent.top
            text: MainWindowStore.productInfoDetailItem.cost + " ₩"
            font.pixelSize: parent.height * 0.6
            font.bold: true
            font.weight: Font.Bold
            color: CommonStyles.primaryColor
        }
    }

    //confirm/cancel
    RowLayout {
        anchors.fill: parent
        anchors.topMargin: parent.height * 0.83
        anchors.bottomMargin: parent.height * 0.08
        anchors.leftMargin: parent.width * 0.1
        anchors.rightMargin: parent.width * 0.1
        spacing: parent.width * 0.05

        CustomButton {
            Layout.preferredHeight: 1
            Layout.preferredWidth: 1
            Layout.fillHeight: true
            Layout.fillWidth: true
            buttonName: "Cancel"
            buttonRadius: parent.width * 0.05
            btnBorderColor: CommonStyles.primaryColor
            btnColor: CommonStyles.transparentColor
            textColor: CommonStyles.primaryColor
            onClicked: {
                btnCancelClicked()
            }
        }

        CustomButton {
            Layout.preferredHeight: 1
            Layout.preferredWidth: 1
            Layout.fillHeight: true
            Layout.fillWidth: true
            buttonName: "Select"
            buttonRadius: parent.width * 0.05
            onClicked: {
                btnConfirmClicked()
            }
        }
    }
}
