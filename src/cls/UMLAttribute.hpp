/**
 * @file UMLAttribute.hpp
 * @author xzimol04, xholan11 and dr.Koci
 * @brief Class representing uml attribute
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <string>
#include "Element.hpp"

#define typeName "typeName"
#define modifierName "modifierName"

class UMLAttribute : public Element
{
public:
  /**
   * @brief returns if all is correcly set from the view of the class
   *
   * @param attr
   * @return true
   * @return false
   */
  static bool isCorrect(const UMLAttribute &attr);

  QString type;
  QChar modifier;

  /**
   * @brief Default construct a new UMLAttribute object
   *
   */
  UMLAttribute();

  /**
   * @brief Construct a new UMLAttribute object
   *
   * @param name
   */
  UMLAttribute(QString name);
  /**
   * @brief Construct a new UMLAttribute object
   *
   * @param name
   * @param type
   */
  UMLAttribute(QString name, QString type);
  /**
   * @brief Construct a new UMLAttribute object
   *
   * @param modifier
   * @param name
   * @param type
   */
  UMLAttribute(QChar modifier, QString name, QString type);
  ~UMLAttribute();

  /**
   * @brief converts object to json
   *
   * @param json
   */
  void write(QJsonObject &json) const;
  /**
   * @brief reads object from json
   *
   * @param json
   */
  void read(const QJsonObject &json);

  bool operator<(const UMLAttribute &ua) const
  {
    return this->name < ua.name;
  };

  // Automaticly generated files
  bool operator==(const UMLAttribute &other) const;
  bool operator!=(const UMLAttribute &other) const;
};
