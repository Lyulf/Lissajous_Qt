#-------------------------------------------------
#
# Project created by QtCreator 2019-01-25T07:20:46
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lissajous
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += \
               DarkStyle/framelesswindow

SOURCES += \
    DarkStyle/framelesswindow/framelesswindow.cpp \
    DarkStyle/framelesswindow/windowdragger.cpp \
    DarkStyle/DarkStyle.cpp \
    DarkStyle/mainwindow.cpp \
    lissajous.cpp \
    main.cpp

HEADERS += \
    DarkStyle/framelesswindow/framelesswindow.h \
    DarkStyle/framelesswindow/windowdragger.h \
    DarkStyle/DarkStyle.h \
    DarkStyle/mainwindow.h \
    lissajous.h

FORMS += \
    DarkStyle/framelesswindow/framelesswindow.ui \
    DarkStyle/mainwindow.ui \
    lissajous.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    DarkStyle/darkstyle.qrc \
    DarkStyle/framelesswindow.qrc

DISTFILES += \
    DarkStyle/darkstyle/icon_branch_closed.png \
    DarkStyle/darkstyle/icon_branch_end.png \
    DarkStyle/darkstyle/icon_branch_more.png \
    DarkStyle/darkstyle/icon_branch_open.png \
    DarkStyle/darkstyle/icon_checkbox_checked.png \
    DarkStyle/darkstyle/icon_checkbox_checked_disabled.png \
    DarkStyle/darkstyle/icon_checkbox_checked_pressed.png \
    DarkStyle/darkstyle/icon_checkbox_indeterminate.png \
    DarkStyle/darkstyle/icon_checkbox_indeterminate_disabled.png \
    DarkStyle/darkstyle/icon_checkbox_indeterminate_pressed.png \
    DarkStyle/darkstyle/icon_checkbox_unchecked.png \
    DarkStyle/darkstyle/icon_checkbox_unchecked_disabled.png \
    DarkStyle/darkstyle/icon_checkbox_unchecked_pressed.png \
    DarkStyle/darkstyle/icon_close.png \
    DarkStyle/darkstyle/icon_radiobutton_checked.png \
    DarkStyle/darkstyle/icon_radiobutton_checked_disabled.png \
    DarkStyle/darkstyle/icon_radiobutton_checked_pressed.png \
    DarkStyle/darkstyle/icon_radiobutton_unchecked.png \
    DarkStyle/darkstyle/icon_radiobutton_unchecked_disabled.png \
    DarkStyle/darkstyle/icon_radiobutton_unchecked_pressed.png \
    DarkStyle/darkstyle/icon_restore.png \
    DarkStyle/darkstyle/icon_undock.png \
    DarkStyle/darkstyle/icon_vline.png \
    DarkStyle/images/icon_window_close.png \
    DarkStyle/images/icon_window_maximize.png \
    DarkStyle/images/icon_window_minimize.png \
    DarkStyle/images/icon_window_restore.png \
    DarkStyle/screenshot_mac_frameless_window_qt_dark_style_disabled.png \
    DarkStyle/screenshot_mac_frameless_window_qt_dark_style_enabled.png \
    DarkStyle/screenshot_win7_frameless_window_qt_dark_style_enabled.png \
    DarkStyle/README.md \
    DarkStyle/darkstyle/darkstyle.qss \
    DarkStyle/.gitignore
