QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/classobjectgui.cpp \
        src/cls/Element.cpp \
        src/cls/UMLClassInterfaceTemplate.cpp \
        src/cls/UMLInterface.cpp \
        src/cls/UMLClass.cpp \
        src/cls/UMLAttribute.cpp \
        src/cls/UMLOperation.cpp \
        src/cls/UMLRelation.cpp \
        src/cls/Mess.cpp \
        src/cls/ClassDiagram.cpp \
        src/cls/SequenceDiagram.cpp \
        src/controllers/editobjectdialog.cpp \
        src/controllers/sequencediagramview.cpp \
        src/diagraminterface.cpp \
        src/interfaceobjectgui.cpp \
        src/jsonreader.cpp \
        src/main.cpp \
        src/controllers/mainwindow.cpp \
        src/controllers/classdiagramview.cpp \
        src/objectgui.cpp

HEADERS += \
        src/classobjectgui.h \
        src/cls/Element.hpp \
        src/cls/UMLClassInterfaceTemplate.hpp \
        src/cls/UMLInterface.hpp \
        src/cls/UMLClass.hpp \
        src/cls/UMLAttribute.hpp \
        src/cls/UMLOperation.hpp \
        src/cls/UMLRelation.hpp \
        src/cls/Mess.hpp \
        src/cls/ClassDiagram.hpp \
        src/cls/SequenceDiagram.hpp \
        src/controllers/editobjectdialog.h \
        src/controllers/mainwindow.h \
        src/controllers/classdiagramview.h \
        src/controllers/sequencediagramview.h \
        src/diagraminterface.h \
        src/interfaceobjectgui.h \
        src/jsonreader.h \
        src/objectgui.h

FORMS += \
    src/controllers/editobjectdialog.ui \
    src/views/sequencediagramview.ui \
    src/views/classdiagramview.ui \
    src/views/mainwindow.ui

CONFIG += console

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
