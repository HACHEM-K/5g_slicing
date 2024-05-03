/**
 * 3gpp-iptvconfiguration
 * API for IPTV configuration. © 2021, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.0.1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * AccessRightStatus_anyOf.h
 *
 *
 */

#ifndef AccessRightStatus_anyOf_H_
#define AccessRightStatus_anyOf_H_

#include <nlohmann/json.hpp>

namespace oai::nef::model {

/// <summary>
///
/// </summary>
class AccessRightStatus_anyOf {
 public:
  AccessRightStatus_anyOf();
  virtual ~AccessRightStatus_anyOf() = default;

  enum class eAccessRightStatus_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    FULLY_ALLOWED,
    PREVIEW_ALLOWED,
    NO_ALLOWED
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

  bool operator==(const AccessRightStatus_anyOf& rhs) const;
  bool operator!=(const AccessRightStatus_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// AccessRightStatus_anyOf members

  AccessRightStatus_anyOf::eAccessRightStatus_anyOf getValue() const;
  void setValue(AccessRightStatus_anyOf::eAccessRightStatus_anyOf value);

  friend void to_json(nlohmann::json& j, const AccessRightStatus_anyOf& o);
  friend void from_json(const nlohmann::json& j, AccessRightStatus_anyOf& o);

 protected:
  AccessRightStatus_anyOf::eAccessRightStatus_anyOf m_value =
      AccessRightStatus_anyOf::eAccessRightStatus_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace oai::nef::model

#endif /* AccessRightStatus_anyOf_H_ */