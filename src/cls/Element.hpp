/**
 * class representing element in string format - to be inherited
 * @author dr.Koci, rewritten to c++ by xzimol04
 * */
#pragma once

#include <string>
class Element
{
public:
    std::string name;

    Element(std::string name);
    /**
     * @brief Destroy the Element object
     *
     */
    ~Element();

    bool operator==(const Element &other) const;
    bool operator!=(const Element &other) const;
};