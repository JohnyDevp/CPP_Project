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
