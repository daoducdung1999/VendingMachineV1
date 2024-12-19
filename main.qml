import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls.Basic
import QtQuick.Layouts
import QtMultimedia
import "./Common/"
import "./Common/Components/"
import Flux 1.0

Window {
    id: root
    width: CommonStyles.appWidth
    height: CommonStyles.appHeight
    visible: true
    title: qsTr("Vending Machine")
    color: CommonStyles.backGroundColor

    // //video area
    Rectangle {
        anchors.fill: parent
        anchors.bottomMargin: parent.height * 2/3
        color: CommonStyles.transparentColor

        Video {
            id: videoPlayer
            anchors.fill: parent
            source: "qrc:/Video/70796-538877060_tiny.avi"
            fillMode: VideoOutput.Stretch
            loops: MediaPlayer.Once
            muted: true
            volume: 0
        }
    }

    Connections {
        target: videoPlayer
        function onPlaybackStateChanged() {
            if (videoPlayer.playbackState === MediaPlayer.StoppedState) {
                videoPlayer.play()
            }
        }
    }

    Component.onCompleted: {
        btn1.setToFocusColor()
        btn2.setToMainColor()
        btn3.setToMainColor()
        btn4.setToMainColor()
        btn5.setToMainColor()
        btn6.setToMainColor()
        btn7.setToMainColor()
        //
        gridView.model = MainWindowStore.proteinProductInfoModel
        //
        videoPlayer.play()
    }

    Rectangle {
        id: rec1
        anchors.fill: parent
        anchors.topMargin: parent.height * 1/3
        color: CommonStyles.transparentColor

        //button area
        ColumnLayout {
            anchors.fill: parent
            anchors.bottomMargin: parent.height * 0.82
            spacing: 0
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

            RowLayout {
                Layout.preferredHeight: 1
                Layout.preferredWidth: 1
                Layout.fillHeight: true
                Layout.fillWidth: true
                spacing: 0
                TabViewButton {
                    id: btn1
                    Layout.preferredHeight: 1
                    Layout.preferredWidth: 1
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    buttonName: "Protein"
                    ButtonGroup.group: groupBtn
                    onClicked: {
                        gridView.model = MainWindowStore.proteinProductInfoModel
                    }
                }

                TabViewButton {
                    id: btn2
                    Layout.preferredHeight: 1
                    Layout.preferredWidth: 1
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    buttonName: "BCAA"
                    ButtonGroup.group: groupBtn
                    onClicked: {
                        gridView.model = MainWindowStore.bcaaProductInfoModel
                    }
                }

                TabViewButton {
                    id: btn3
                    Layout.preferredHeight: 1
                    Layout.preferredWidth: 1
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    buttonName: "PreWorkout"
                    ButtonGroup.group: groupBtn
                    onClicked: {
                        gridView.model = MainWindowStore.preWorkoutProductInfoModel
                    }
                }

                TabViewButton {
                    id: btn4
                    Layout.preferredHeight: 1
                    Layout.preferredWidth: 1
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    buttonName: "Supplements\n& Diet"
                    ButtonGroup.group: groupBtn
                    onClicked: {
                        gridView.model = MainWindowStore.supAndDietProductInfoModel
                    }
                }
            }

            RowLayout {
                Layout.preferredHeight: 1
                Layout.preferredWidth: 1
                Layout.fillHeight: true
                Layout.fillWidth: true
                spacing: 0

                RowLayout {
                    Layout.preferredHeight: 1
                    Layout.preferredWidth: 1
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    spacing: 0
                    TabViewButton {
                        id: btn5
                        Layout.preferredHeight: 1
                        Layout.preferredWidth: 1
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        buttonName: "Ice & Cup"
                        ButtonGroup.group: groupBtn
                        onClicked: {
                            gridView.model = []
                        }
                    }

                    TabViewButton {
                        id: btn6
                        Layout.preferredHeight: 1
                        Layout.preferredWidth: 1
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        buttonName: "Snack Bar"
                        ButtonGroup.group: groupBtn
                        onClicked: {
                            gridView.model = []
                        }
                    }
                }

                TabViewButton {
                    id: btn7
                    Layout.preferredHeight: 1
                    Layout.preferredWidth: 1
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    buttonName: "Coming Soon"
                    enabled: false
                    ButtonGroup.group: groupBtn
                    onClicked: {

                    }
                }
            }
        }

        //product area
        Rectangle {
            anchors.fill: parent
            anchors.topMargin: parent.height * 0.18
            anchors.bottomMargin: parent.height * 0.18
            color: CommonStyles.transparentColor

            Flickable {
                id: flickable
                anchors.fill: parent
                contentWidth: gridView.contentWidth
                contentHeight: gridView.height
                clip: true
                GridView {
                    id: gridView
                    width: flickable.width
                    height: flickable.height
                    model: MainWindowStore.proteinProductInfoModel
                    cellWidth: parent.width * 1/4
                    cellHeight: parent.height * 1/3
                    flow: GridView.FlowLeftToRight
                    layoutDirection: Qt.LeftToRight

                    ScrollBar.vertical: ScrollBar {
                        id: verticalScrollBar
                        policy: gridView.count > 12 ? ScrollBar.AlwaysOn : ScrollBar.AlwaysOff
                        anchors.right: parent.right
                        width: parent.width * 0.02
                    }

                    delegate: Rectangle {
                        width: gridView.cellWidth
                        height: gridView.cellHeight
                        color: CommonStyles.transparentColor
                        ProductInforItem {
                            anchors.fill: parent
                            anchors.margins: parent.width * 0.01
                            imgSource: getProteinImg(model.object.type, model.object.id)
                            itemName: model.object.name
                            itemCost: model.object.cost + "won"
                            onItemClick: {
                                var data = {
                                    itemId: model.object.id,
                                    type: model.object.type
                                }
                                ActionProvider.selectProduct(data)
                                rec1.visible = false
                                modalWindowDetail.imgSource = getProteinImg(model.object.type, model.object.id)
                                modalWindowDetail.visible = true
                            }
                        }
                    }
                }
            }
        }

        //action detail area
        Rectangle {
            anchors.fill: parent
            anchors.topMargin: parent.height * 0.83
            color: CommonStyles.transparentColor

            Rectangle {
                anchors.fill: parent
                anchors.rightMargin:  parent.width * 0.4
                color: CommonStyles.transparentColor

                RowLayout {
                    anchors.fill: parent
                    anchors.leftMargin: parent.width * 0.1
                    anchors.rightMargin: parent.width * 0.15
                    anchors.topMargin: parent.height * 0.1
                    anchors.bottomMargin: parent.height * 0.1
                    spacing: 0

                    Item {
                        Layout.preferredHeight: 1
                        Layout.preferredWidth: 1
                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        Rectangle {
                            anchors.fill: parent
                            anchors.margins: parent.width * 0.03
                            color: CommonStyles.gray15
                            radius: parent.width * 0.01
                            visible: listItemSelect.count < 1
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
                    }

                    Item {
                        Layout.preferredHeight: 1
                        Layout.preferredWidth: 1
                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        Rectangle {
                            anchors.fill: parent
                            anchors.margins: parent.width * 0.03
                            color: CommonStyles.gray15
                            radius: parent.width * 0.01
                            visible: listItemSelect.count < 2

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
                    }

                    Item {
                        Layout.preferredHeight: 1
                        Layout.preferredWidth: 1
                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        Rectangle {
                            anchors.fill: parent
                            anchors.margins: parent.width * 0.03
                            color: CommonStyles.gray15
                            radius: parent.width * 0.01
                            visible: listItemSelect.count < 3

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
                    }
                }
            }

            //item select
            Rectangle {
                anchors.fill: parent
                anchors.rightMargin:  parent.width * 0.4
                color: CommonStyles.transparentColor

                Image {
                    id: leftArrow
                    anchors.fill: parent
                    anchors.leftMargin: parent.width * 0.03
                    anchors.rightMargin: parent.width * 0.9
                    anchors.topMargin: parent.height * 0.4
                    anchors.bottomMargin: parent.height * 0.4
                    fillMode: Image.Stretch
                    source: "qrc:/Image/Components/leftarrow.svg"
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if (listItemSelect.currentIndex < listItemSelect.count - 1) {
                                listItemSelect.currentIndex += 1
                            }
                        }
                    }
                }

                Image {
                    id: rightArrow
                    anchors.fill: parent
                    anchors.leftMargin: parent.width * 0.85
                    anchors.rightMargin: parent.width * 0.08
                    anchors.topMargin: parent.height * 0.4
                    anchors.bottomMargin: parent.height * 0.4
                    fillMode: Image.Stretch
                    source: "qrc:/Image/Components/rightarrow.svg"
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if (listItemSelect.currentIndex > 0) {
                                listItemSelect.currentIndex -= 1
                            }
                        }
                    }
                }

                ListView {
                    id: listItemSelect
                    anchors.fill: parent
                    anchors.leftMargin: parent.width * 0.1
                    anchors.rightMargin: parent.width * 0.15
                    anchors.topMargin: parent.height * 0.1
                    anchors.bottomMargin: parent.height * 0.1
                    clip: true

                    model: MainWindowStore.selectedProductModel
                    orientation: ListView.Horizontal

                    delegate: Rectangle {
                        width: listItemSelect.width / 3
                        height: listItemSelect.height
                        color: CommonStyles.transparentColor
                        SelectedProductItem  {
                            anchors.fill: parent
                            anchors.margins: parent.width * 0.03
                            imgSource: getProteinImg(model.object.type, model.object.id)
                            visibleThis: false
                        }
                    }
                }
            }

            Rectangle {
                anchors.fill: parent
                anchors.leftMargin:  parent.width * 0.6
                color: CommonStyles.transparentColor

                Rectangle {
                    anchors.fill: parent
                    anchors.rightMargin: parent.width * 0.5
                    color: CommonStyles.transparentColor

                    Rectangle
                    {
                        anchors.fill: parent
                        anchors.bottomMargin: parent.height * 0.5
                        color: CommonStyles.gray25

                        Label {
                            anchors.fill: parent
                            anchors.bottomMargin: parent.height * 0.5
                            anchors.rightMargin: parent.width * 0.05
                            horizontalAlignment: Text.AlignRight
                            verticalAlignment: Text.AlignVCenter
                            wrapMode: Text.WordWrap
                            text: "Payment Amount"
                            font.pixelSize: parent.height * 0.2
                            font.family: CommonStyles.notoSanFontRegular
                            font.bold: true
                            color: CommonStyles.textColor
                        }

                        Label {
                            anchors.fill: parent
                            anchors.topMargin: parent.height * 0.5
                            anchors.rightMargin: parent.width * 0.05
                            horizontalAlignment: Text.AlignRight
                            verticalAlignment: Text.AlignVCenter
                            wrapMode: Text.WordWrap
                            text: "₩ " + MainWindowStore.totalPayment
                            font.pixelSize: Math.min(parent.width, parent.height) * 0.35
                            font.family: CommonStyles.notoSanFontRegular
                            font.bold: true
                            color: CommonStyles.primaryColor
                        }
                    }

                    CustomButton
                    {
                        anchors.fill: parent
                        anchors.topMargin: parent.height * 0.5
                        buttonName: "Cancel All"
                        buttonRadius: 0
                        btnColor: CommonStyles.secondaryColor
                        textColor: CommonStyles.whiteColor
                        textSize: parent.height * 0.15
                        btnBorderColor: CommonStyles.secondaryColor
                        onClicked: {
                            ActionProvider.cancelAllSelectedProduct()
                        }
                    }
                }

                Rectangle {
                    anchors.fill: parent
                    anchors.leftMargin: parent.width * 0.5
                    color: CommonStyles.primaryColor

                    Image {
                        id: name
                        anchors.fill: parent
                        anchors.topMargin: parent.height * 0.05
                        anchors.bottomMargin: parent.height * 0.5
                        anchors.rightMargin: parent.width * 0.15
                        anchors.leftMargin: parent.width * 0.15
                        source: "qrc:/Image/Components/credit-card (1).png"
                        fillMode: Image.Stretch
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {

                            }
                        }
                    }

                    CustomButton {
                        anchors.fill: parent
                        anchors.topMargin: parent.height * 0.5
                        buttonName: "Payment"
                        buttonRadius: 0
                        textColor: CommonStyles.whiteColor
                        textSize: parent.height * 0.15
                        onClicked: {
                        }
                    }
                }
            }
        }
    }

    ModalWindowDetail {
        id: modalWindowDetail
        anchors.fill: parent
        anchors.topMargin: parent.height * 1/3
        visible: false

        onBtnCancelClicked: {
            modalWindowDetail.visible = false
            rec1.visible = true
        }

        onBtnConfirmClicked: {
            modalWindowDetail.visible = false
            rec1.visible = true
        }
    }
    function getProteinImg(type, itemId)
    {
        if (type === 1)
        {
            if (itemId === 1)
            {
                return "qrc:/Image/Protein/protein_01.png"
            }
            else if (itemId === 2)
            {
                return "qrc:/Image/Protein/protein_02.png"
            }
            else if (itemId === 3)
            {
                return "qrc:/Image/Protein/protein_03.png"
            }
            else if (itemId === 4)
            {
                return "qrc:/Image/Protein/protein_04.png"
            }
            else if (itemId === 5)
            {
                return "qrc:/Image/Protein/protein_05.png"
            }
            else if (itemId === 6)
            {
                return "qrc:/Image/Protein/protein_06.png"
            }
            else
            {
                return ""
            }
        }
        else if (type === 2)
        {
            if (itemId === 1)
            {
                return "qrc:/Image/BCAA/bcaa_1.png"
            }
            else if (itemId === 2)
            {
                return "qrc:/Image/BCAA/bcaa_2.png"
            }
            else if (itemId === 3)
            {
                return "qrc:/Image/BCAA/bcaa_3.png"
            }
            else if (itemId === 4)
            {
                return "qrc:/Image/BCAA/bcaa_4.png"
            }
            else
            {
                return ""
            }
        }
        else if (type === 3)
        {
            if (itemId === 1)
            {
                return "qrc:/Image/Preworkout/pw_01.png"
            }
            else if (itemId === 2)
            {
                return "qrc:/Image/Preworkout/pw_02.png"
            }
            else if (itemId === 3)
            {
                return "qrc:/Image/Preworkout/pw_03.png"
            }
            else if (itemId === 4)
            {
                return "qrc:/Image/Preworkout/pw_04.png"
            }
            else if (itemId === 5)
            {
                return "qrc:/Image/Preworkout/pw_05.png"
            }
            else
            {
                return ""
            }
        }
        else if (type === 4)
        {
            if (itemId === 1)
            {
                return "qrc:/Image/SupAndDiet/sup_diet_01.png"
            }
            else if (itemId === 2)
            {
                return "qrc:/Image/SupAndDiet/sup_diet_02.png"
            }
            else if (itemId === 3)
            {
                return "qrc:/Image/SupAndDiet/sup_diet_03.png"
            }
            else if (itemId === 4)
            {
                return "qrc:/Image/SupAndDiet/sup_diet_04.png"
            }
            else if (itemId === 5)
            {
                return "qrc:/Image/SupAndDiet/sup_diet_05.png"
            }
            else if (itemId === 6)
            {
                return "qrc:/Image/SupAndDiet/sup_diet_06.png"
            }
            else if (itemId === 7)
            {
                return "qrc:/Image/SupAndDiet/sup_diet_07.png"
            }
            else
            {
                return ""
            }
        }
    }
}
