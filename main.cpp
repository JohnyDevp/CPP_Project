#include "mainwindow.h"

#include <QApplication>

#include "Element.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Element el = Element(std::string("here"));
    MainWindow w;
    w.show();
    return a.exec();
}
