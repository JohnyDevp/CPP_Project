TEMPLATE = lib
CONFIG += staticlib
#Input
SOURCES += \
    src/cls/Element.cpp \
    src/cls/UMLAttribute.cpp \
    src/cls/UMLOperation.cpp \
    src/cls/UMLClassInterfaceTemplate.cpp \
    src/cls/UMLInterface.cpp \
    src/cls/UMLRelation.cpp \
    src/cls/UMLClass.cpp \
    src/cls/ClassDiagram.cpp \
    src/cls/Mess.cpp \
    src/cls/SequenceDiagram.cpp\
    src/main.cpp 

HEADERS += \
    src/cls/Element.hpp \
    src/cls/UMLAttribute.hpp \
    src/cls/UMLOperation.hpp \
    src/cls/UMLClassInterfaceTemplate.hpp \
    src/cls/UMLInterface.hpp \
    src/cls/UMLRelation.hpp \
    src/cls/UMLClass.hpp \
    src/cls/ClassDiagram.hpp \
    src/cls/Mess.hpp \
    src/cls/SequenceDiagram.hpp
