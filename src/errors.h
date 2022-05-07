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

/**
 * @brief The Errors class
 * class for creating error, warning and information messages in message boxes
 * it is called whenever alert is necessary to be shown everywhere in this program
 */
class Errors
{
public:
    Errors();
    static void raiseWarning(QString alertText);
    static void raiseError(QString alertText);
    static void raiseInformation(QString alertText);
};

#endif // ERRORS_H
