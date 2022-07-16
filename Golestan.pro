QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminaddclass.cpp \
    adminaddpeople.cpp \
    adminclassinfo.cpp \
    adminmainmenu.cpp \
    adminprofile.cpp \
    adminsendassertion.cpp \
    adminwatchstudent.cpp \
    enterenewpass.cpp \
    forgotpasspage.cpp \
    loginpage.cpp \
    main.cpp \
    studentenrolment.cpp \
    studentmainmenu.cpp \
    studentmessages.cpp \
    studentprofile.cpp \
    studentteachersurvey.cpp \
    studentterms.cpp \
    studenttermscores.cpp \
    studentwatchmessagecomplitly.cpp \
    studentwatchsurvey.cpp \
    studentweeklyschedule.cpp \
    teacherclassinfo.cpp \
    teacherclasssetscore.cpp \
    teachermainmenu.cpp \
    teachermessages.cpp \
    teacherprofile.cpp \
    teachersendassertion.cpp \
    teacherstudentsetscore.cpp \
    teacherwatchmessagecomplitly.cpp \
    teacherwatchstudent.cpp \
    teacherweeklyschedule.cpp

HEADERS += \
    adminaddclass.h \
    adminaddpeople.h \
    adminclassinfo.h \
    adminmainmenu.h \
    adminprofile.h \
    adminsendassertion.h \
    adminwatchstudent.h \
    enterenewpass.h \
    forgotpasspage.h \
    loginpage.h \
    studentenrolment.h \
    studentmainmenu.h \
    studentmessages.h \
    studentprofile.h \
    studentteachersurvey.h \
    studentterms.h \
    studenttermscores.h \
    studentwatchmessagecomplitly.h \
    studentwatchsurvey.h \
    studentweeklyschedule.h \
    teacherclassinfo.h \
    teacherclasssetscore.h \
    teachermainmenu.h \
    teachermessages.h \
    teacherprofile.h \
    teachersendassertion.h \
    teacherstudentsetscore.h \
    teacherwatchmessagecomplitly.h \
    teacherwatchstudent.h \
    teacherweeklyschedule.h

FORMS += \
    adminaddclass.ui \
    adminaddpeople.ui \
    adminclassinfo.ui \
    adminmainmenu.ui \
    adminprofile.ui \
    adminsendassertion.ui \
    adminwatchstudent.ui \
    enterenewpass.ui \
    forgotpasspage.ui \
    loginpage.ui \
    studentenrolment.ui \
    studentmainmenu.ui \
    studentmessages.ui \
    studentprofile.ui \
    studentteachersurvey.ui \
    studentterms.ui \
    studenttermscores.ui \
    studentwatchmessagecomplitly.ui \
    studentwatchsurvey.ui \
    studentweeklyschedule.ui \
    teacherclassinfo.ui \
    teacherclasssetscore.ui \
    teachermainmenu.ui \
    teachermessages.ui \
    teacherprofile.ui \
    teachersendassertion.ui \
    teacherstudentsetscore.ui \
    teacherwatchmessagecomplitly.ui \
    teacherwatchstudent.ui \
    teacherweeklyschedule.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    arrowIcon.qrc \
    classIcon.qrc \
    endIcon.qrc \
    icon.qrc \
    pictures.qrc \
    second-icon.qrc \
    term-management-icon.qrc \
    third-icon-group.qrc

DISTFILES += \
    scorecard.png
