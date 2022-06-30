QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CalendarCreator.cpp \
    adminaddpeople.cpp \
    adminsendassertion.cpp \
    teachersendassertion.cpp \
    Auth.cpp \
    Filemanager.cpp \
    Permission.cpp \
    TeacherWeeklyCalendar.cpp \
    WeeklyCalendar.cpp \
    adminprofile.cpp \
    Teacher.cpp \
    User.cpp \
    adminmainmenu.cpp \
    enterenewpass.cpp \
    forgotpasspage.cpp \
    loginpage.cpp \
    main.cpp \
	dist/jsoncpp.cpp \
    studentmainmenu.cpp \
    studentprofile.cpp \
    teachermainmenu.cpp \
    teacherprofile.cpp

HEADERS += \
    CalendarCreator.h \
    adminaddpeople.h \
    adminsendassertion.h \
    teachersendassertion.h \
    Auth.h \
    Filemanager.h \
    Permission.h \
    TeacherWeeklyCalendar.h \
    WeeklyCalendar.h \
    adminprofile.h \
    Teacher.h \
    User.h \
    adminmainmenu.h \
    enterenewpass.h \
    forgotpasspage.h \
    loginpage.h \
	dist/json/json.h \
	dist/json/json-forwards.h \
    studentmainmenu.h \
    studentprofile.h \
    teachermainmenu.h \
    teacherprofile.h

FORMS += \
    adminaddpeople.ui \
    adminsendassertion.ui \
    teachersendassertion.ui \
    Teacher.ui \
    adminmainmenu.ui \
    adminprofile.ui \
    enterenewpass.ui \
    forgotpasspage.ui \
    loginpage.ui \
    studentmainmenu.ui \
    studentprofile.ui \
    teachermainmenu.ui \
    teacherprofile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    arrowIcon.qrc \
    icon.qrc \
    pictures.qrc \
    second-icon.qrc \
    third-icon-group.qrc

DISTFILES += \
    scorecard.png