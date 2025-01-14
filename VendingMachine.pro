QT += quick qml
QT += gui
QT += gui-private

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        action/actionprovider.cpp \
        appmanager.cpp \
        arch/messageabs/innermessage.cpp \
        main.cpp \
        model/ingredientitem.cpp \
        model/innerevent.cpp \
        model/productinformationitem.cpp \
        model/qobjectlistmodel.cpp \
        store/mainwindowstore.cpp

INCLUDEPATH += $$PWD/cereal
LIBS += -L$$PWD/cereal

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    action/actionprovider.h \
    action/actiontype.h \
    appmanager.h \
    arch/flux/action.h \
    arch/flux/dispatcher.h \
    arch/flux/middleware.h \
    arch/flux/store.h \
    arch/messageabs/innermessage.h \
    commonsetting.h \
    model/ingredientitem.h \
    model/innerevent.h \
    model/productinformationitem.h \
    model/qobjectlistmodel.h \
    model/qobjectlistmodelt.h \
    store/mainwindowstore.h

DISTFILES +=
