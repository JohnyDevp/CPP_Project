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
#include <QString>

int main(int argc, char *argv[])
{

    UMLAttribute a;
    a.name = "ahoj tome";
    a.type = "int a b";
    if (a.isCorrect(a))
    {
        std::cout << "Element is correct" << std::endl;
    }

    a.name = "tom";
    a.type = "int";

    if (a.isCorrect(a))
    {
        std::cout << "Element is correct" << std::endl;
    }
}
