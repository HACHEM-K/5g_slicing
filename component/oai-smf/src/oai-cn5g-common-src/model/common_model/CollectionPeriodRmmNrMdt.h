/**
 * Common Data Types
 * Common Data Types for Service Based Interfaces. © 2022, 3GPP Organizational
 * Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.2.7
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * CollectionPeriodRmmNrMdt.h
 *
 *
 */

#ifndef CollectionPeriodRmmNrMdt_H_
#define CollectionPeriodRmmNrMdt_H_

#include "CollectionPeriodRmmNrMdt_anyOf.h"
#include <nlohmann/json.hpp>

namespace oai::model::common {

/// <summary>
///
/// </summary>
class CollectionPeriodRmmNrMdt {
 public:
  CollectionPeriodRmmNrMdt();
  virtual ~CollectionPeriodRmmNrMdt() = default;

  /// <summary>
  /// Validate the current data in the model. Throws a ValidationException on
  /// failure.
  /// </summary>
  void validate() const;

  /// <summary>
  /// Validate the current data in the model. Returns false on error and writes
  /// an error message into the given stringstream.
  /// </summary>
  bool validate(std::stringstream& msg) const;

  /// <summary>
  /// Helper overload for validate. Used when one model stores another model and
  /// calls it's validate. Not meant to be called outside that case.
  /// </summary>
  bool validate(std::stringstream& msg, const std::string& pathPrefix) const;

  bool operator==(const CollectionPeriodRmmNrMdt& rhs) const;
  bool operator!=(const CollectionPeriodRmmNrMdt& rhs) const;

  /////////////////////////////////////////////
  /// CollectionPeriodRmmNrMdt members

  CollectionPeriodRmmNrMdt_anyOf getValue() const;
  void setValue(CollectionPeriodRmmNrMdt_anyOf value);
  CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf getEnumValue()
      const;
  void setEnumValue(
      CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf value);
  friend void to_json(nlohmann::json& j, const CollectionPeriodRmmNrMdt& o);
  friend void from_json(const nlohmann::json& j, CollectionPeriodRmmNrMdt& o);
  friend void to_json(
      nlohmann::json& j, const CollectionPeriodRmmNrMdt_anyOf& o);
  friend void from_json(
      const nlohmann::json& j, CollectionPeriodRmmNrMdt_anyOf& o);

 protected:
  CollectionPeriodRmmNrMdt_anyOf m_value;
};

}  // namespace oai::model::common

#endif /* CollectionPeriodRmmNrMdt_H_ */