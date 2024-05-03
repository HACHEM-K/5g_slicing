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
 * CellGlobalId.h
 *
 *
 */

#ifndef CellGlobalId_H_
#define CellGlobalId_H_

#include <string>
#include "PlmnId.h"
#include <nlohmann/json.hpp>

namespace oai::model::common {

/// <summary>
///
/// </summary>
class CellGlobalId {
 public:
  CellGlobalId();
  virtual ~CellGlobalId() = default;

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

  bool operator==(const CellGlobalId& rhs) const;
  bool operator!=(const CellGlobalId& rhs) const;

  /////////////////////////////////////////////
  /// CellGlobalId members

  /// <summary>
  ///
  /// </summary>
  oai::model::common::PlmnId getPlmnId() const;
  void setPlmnId(oai::model::common::PlmnId const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getLac() const;
  void setLac(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getCellId() const;
  void setCellId(std::string const& value);

  friend void to_json(nlohmann::json& j, const CellGlobalId& o);
  friend void from_json(const nlohmann::json& j, CellGlobalId& o);

 protected:
  oai::model::common::PlmnId m_PlmnId;

  std::string m_Lac;

  std::string m_CellId;
};

}  // namespace oai::model::common

#endif /* CellGlobalId_H_ */