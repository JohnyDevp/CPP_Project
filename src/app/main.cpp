#include "../controllers/mainwindow.h"
#include "cls/ClassDiagram.hpp"
#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    UMLClass cl = UMLClass(std::string("class"));
    std::cout << cl.name << std::endl;
    w.show();
    return a.exec();
}
