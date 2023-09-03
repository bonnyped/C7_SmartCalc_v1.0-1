QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../calc_polish_revers_entry.c \
    ../check_sequence.c \
    ../s21_credit_calc.c \
    ../s21_deposit_calc.c \
    ../s21_smart_calc.c \
    ../stack.c \
    ../string_conversion.c \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \

HEADERS += \
    ../s21_smart_calc.h \
    mainwindow.h \
    qcustomplot.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    platforms/libqeglfs.a \
    platforms/libqeglfs.prl \
    platforms/libqlinuxfb.a \
    platforms/libqlinuxfb.prl \
    platforms/libqminimal.a \
    platforms/libqminimal.prl \
    platforms/libqminimalegl.a \
    platforms/libqminimalegl.prl \
    platforms/libqoffscreen.a \
    platforms/libqoffscreen.prl \
    platforms/libqvnc.a \
    platforms/libqvnc.prl
