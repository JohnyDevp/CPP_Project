QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cls/Element.cpp \
        cls/UMLClass.cpp \
        cls/UMLAttribute.cpp \
        cls/UMLOperation.cpp \
        cls/UMLRelation.cpp \
        cls/Message.cpp \
        cls/ClassDiagram.cpp \
        cls/SequenceDiagram.cpp \
        jsonreader.cpp \
        main.cpp \
        controllers/mainwindow.cpp \
        controllers/classdiagramview.cpp

HEADERS += \
        cls/Element.hpp \
        cls/UMLClass.hpp \
        cls/UMLAttribute.hpp \
        cls/UMLOperation.hpp \
        cls/UMLRelation.hpp \
        cls/Message.hpp \
        cls/ClassDiagram.hpp \
        cls/SequenceDiagram.hpp \
        controllers/mainwindow.h \
        controllers/classdiagramview.h \
        jsonreader.h

FORMS += \
    views/classdiagramview.ui \
    views/mainwindow.ui

CONFIG += console

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target