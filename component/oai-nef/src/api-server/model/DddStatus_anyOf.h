/**
 * Nnef_EventExposure
 * NEF Event Exposure Service. © 2021, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.0.5
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * DddStatus_anyOf.h
 *
 *
 */

#ifndef DddStatus_anyOf_H_
#define DddStatus_anyOf_H_

#include <nlohmann/json.hpp>

namespace oai::nef::model {

/// <summary>
///
/// </summary>
class DddStatus_anyOf {
 public:
  DddStatus_anyOf();
  virtual ~DddStatus_anyOf() = default;

  enum class eDddStatus_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    BUFFERED,
    TRANSMITTED,
    DISCARDED
  };

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

  bool operator==(const DddStatus_anyOf& rhs) const;
  bool operator!=(const DddStatus_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// DddStatus_anyOf members

  DddStatus_anyOf::eDddStatus_anyOf getValue() const;
  void setValue(DddStatus_anyOf::eDddStatus_anyOf value);

  friend void to_json(nlohmann::json& j, const DddStatus_anyOf& o);
  friend void from_json(const nlohmann::json& j, DddStatus_anyOf& o);

 protected:
  DddStatus_anyOf::eDddStatus_anyOf m_value =
      DddStatus_anyOf::eDddStatus_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace oai::nef::model

#endif /* DddStatus_anyOf_H_ */