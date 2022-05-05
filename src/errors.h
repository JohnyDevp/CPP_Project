/**
 * @file errors.h
 * @author xholan11
 * @brief Header file for errors.cpp
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef ERRORS_H
#define ERRORS_H

#include <QString>

class Errors
{
public:
    Errors();
    static void raiseWarning(QString alertText);
    static void raiseError(QString alertText);
    static void raiseInformation(QString alertText);
};

#endif // ERRORS_H
