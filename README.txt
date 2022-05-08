AUTHORS
-------

Jan Holáň (xholan11)\
Jan Zimola (xzimol04)

DESCRIPTION
-----------

This program represents a tool for creating class diagrams and related sequence diagrams. This implementation-supported mode consists of only one must-opened class diagram and several related sequence diagrams. The application can either create a whole new project or load one from an existing file - the only supported format is JSON.

In the class diagram, the user can create classes and add attributes and operations to them. Between objects, the user can create relations. All of these values can be modified.

In the sequence diagram, the user can add classes from the class diagram as the representation of the whole class or instance of it. Between classes, the user can add messages that represent operations from the class diagram with optional arguments and return values.

The user can undo a class of rename and of adding operations and attributes.


USAGE
-----------

To create documentation: "make doxygen"
To build the program and documentation: "make"
To start the program: "make run" 
To clean all build files run: "make clean"
To pack everything into a zip file: "make pack"

SOURCES
-------

[1] https://doc.qt.io/qt-5/qtcore-serialization-savegame-example.html
