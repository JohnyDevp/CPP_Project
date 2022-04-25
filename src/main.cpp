
#include "cls/UMLOperation.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::cout << "hello " << std::endl;

    UMLOperation el = UMLOperation(std::string("hereaaa"));

    std::cout << el.name << std::endl;
}