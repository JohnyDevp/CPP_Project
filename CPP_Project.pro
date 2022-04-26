QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
	src/controllers/ClassDiagramController.cpp \
	src/controllers/mainwindow.cpp\
    src/main.cpp
HEADERS += \
	src/controllers/ClassDiagramController.h \
	src/controllers/mainwindow.h \

INCLUDEPATH += ../staticLibrary
LIBS += -L../staticLibrary/debug -lstaticLibrary

FORMS += \
    src/views/classDiagram_view.ui \
    src/views/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
