QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        classobjectgui.cpp \
        cls/Element.cpp \
        cls/UMLClass.cpp \
        cls/UMLAttribute.cpp \
        cls/UMLOperation.cpp \
        cls/UMLRelation.cpp \
        cls/Message.cpp \
        cls/UMLSeqClass.cpp \
        cls/ClassDiagram.cpp \
        cls/SequenceDiagram.cpp \
        controllers/editobjectdialog.cpp \
        controllers/editrelationdialog.cpp \
        controllers/sequencediagramview.cpp \
        diagraminterface.cpp \
        errors.cpp \
        interfaceobjectgui.cpp \
        jsonreader.cpp \
        main.cpp \
        controllers/mainwindow.cpp \
        controllers/classdiagramview.cpp \
        objectgui.cpp \
        relationgui.cpp \
        undo.cpp \
        views/addclassdiagramobjectdialog.cpp

HEADERS += \
        classobjectgui.h \
        cls/Element.hpp \
        cls/UMLClass.hpp \
        cls/UMLAttribute.hpp \
        cls/UMLOperation.hpp \
        cls/UMLRelation.hpp \
        cls/Message.hpp \
        cls/UMLSeqClass.hpp \
        cls/ClassDiagram.hpp \
        cls/SequenceDiagram.hpp \
        controllers/editobjectdialog.h \
        controllers/editrelationdialog.h \
        controllers/mainwindow.h \
        controllers/classdiagramview.h \
        controllers/sequencediagramview.h \
        diagraminterface.h \
        errors.h \
        interfaceobjectgui.h \
        jsonreader.h \
        objectgui.h \
        relationgui.h \
        undo.h \
        views/addclassdiagramobjectdialog.h

FORMS += \
    controllers/editobjectdialog.ui \
    controllers/editrelationdialog.ui \
    views/addclassdiagramobjectdialog.ui \
    views/sequencediagramview.ui \
    views/classdiagramview.ui \
    views/mainwindow.ui

CONFIG += console

docs.depends += $(SOURCES)
docs.depends += $(HEADERS)
docs.commands = (cat Doxyfile; echo "INPUT = $?") | doxygen -
QMAKE_EXTRA_TARGETS += docs

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
