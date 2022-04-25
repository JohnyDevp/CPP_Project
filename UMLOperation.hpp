#pragma once

#include <algorithm>
#include "UMLAttribute.hpp"

/**
 * class for representing uml operation for both interface and class
 * @author xzimol04
 * */

#include <vector>
#include <string>

class UMLOperation : public UMLAttribute
{
public:
    /**
     * @brief list of all parameters of this operation
     *
     */
    std::vector<UMLAttribute> parameterssOfOperationList;

    /**
     * @brief adding parameter for this operation
     *
     * @param param UMLAttribute parameter of this operation
     * @return true success
     * @return false fail
     */
    bool addOperationParameter(UMLAttribute param);
    /**
     * @brief Get the Parameters Of Operation List object
     *
     * @return const std::vector<UMLAttribute>
     */
    const std::vector<UMLAttribute> getParametersOfOperationList();
    /**
     * @brief Construct a new UMLOperation object
     *
     * @param name
     */
    UMLOperation(std::string name);
    /**
     * @brief Construct a new UMLOperation object
     *
     * @param name
     * @param returnType
     * @param modifier
     */
    UMLOperation(std::string name, std::string returnType, char modifier);
    /**
     * @brief Destroy the UMLOperation object
     *
     */
    ~UMLOperation();
};
