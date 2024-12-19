import QtQuick 2.15
pragma Singleton
QtObject {
    //app
    property int appHeight: 3840 * resolution
    property int appWidth: 2160 * resolution
    property real resolution: 0.25

    property FontLoader fontRegular: FontLoader {
        id: notoSansKrRegularFont; source: "qrc:/Common/Font/NotoSansKR-Regular.ttf";
    }

    property string notoSanFontRegular: fontRegular.name
    property int fontSizeDefault: 14
    //app color
    property color backGroundColor: "#F2F2F2"
    property color primaryColor: "#28A745"
    property color secondaryColor: "#6C757D"

    //common color
    property color transparentColor: "transparent"
    property color textColor: "#000000"
    property color accentColor: "#FFC107"
    property color whiteColor: "#FFFFFF"
    property color grayColor: "#444444"

    //product type
    property int proteinType: 1
    property int bcaaType: 2
    property int preWorkoutType: 3
}
