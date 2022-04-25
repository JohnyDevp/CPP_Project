QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controllers/ClassDiagramController.cpp \
    main.cpp \
    controllers/mainwindow.cpp\
    main.cpp \
    mainwindow.cpp\
    Element.cpp \
    UMLAttribute.cpp \
    UMLOperation.cpp \
    UMLClassInterfaceTemplate.cpp \
    UMLInterface.cpp \
    UMLRelation.cpp \
    UMLClass.cpp \
    ClassDiagram.cpp \
    Mess.cpp \
    SequenceDiagram.cpp \
    Element.hpp \
    UMLAttribute.hpp \
    UMLOperation.hpp \
    UMLClassInterfaceTemplate.hpp \
    UMLInterface.hpp \
    UMLRelation.hpp \
    UMLClass.hpp \
    ClassDiagram.hpp \
    Mess.hpp \
    SequenceDiagram.hpp


HEADERS += \
    controllers/ClassDiagramController.h \
    controllers/mainwindow.h

FORMS += \
    views/classDiagram_view.ui \
    views/mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
