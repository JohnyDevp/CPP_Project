/**
 * @file main.cpp
 * @author Jan Zimola (xzimol04) and Jan Holáň (xholan11)
 * @brief
 * @date 2022-04-28
 * @copyright Copyright (c) 2022
 *
 */

#include "controllers/mainwindow.h"
#include "cls/ClassDiagram.hpp"

#include <QApplication>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
