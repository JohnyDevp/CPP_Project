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

    ClassDiagram dia = ClassDiagram("ahoj");
    {

        UMLClass cl1 = UMLClass("cl1");
        UMLClass cl2 = UMLClass("cl2");
        UMLClass cl3 = UMLClass("cl3");

        dia.addClass(cl1);
        dia.addClass(cl2);
        dia.addClass(cl3);
    }

    QJsonObject obj;
    dia.write(obj);

    QFile file("../examples/test3/test.json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return 0;

    QTextStream out(&file);
    out << QJsonDocument(obj).toJson();

    UMLClass cl1 = UMLClass("cl1");

    cl1.isInterface = true;
    dia.updateClass(cl1.name, cl1);
    QJsonObject obj5;
    dia.write(obj5);

    QFile file5("../examples/test3/test1.json");
    if (!file5.open(QIODevice::WriteOnly | QIODevice::Text))
        return 0;

    QTextStream out5(&file5);
    out5 << QJsonDocument(obj5).toJson();

    QFile file2("../examples/test2/test2.json");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
        return 0;

    QByteArray saveData = file2.readAll();

    QJsonDocument loadDoc = QJsonDocument::fromJson(saveData);

    dia.read(loadDoc.object());

    QFile file3("../examples/test2/test4.json");
    if (!file3.open(QIODevice::WriteOnly | QIODevice::Text))
        return 0;
    QTextStream out2(&file3);

    dia.write(obj);
    out2 << QJsonDocument(obj).toJson();

    return 0;
}
