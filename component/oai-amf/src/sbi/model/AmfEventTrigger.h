/**
 * Namf_EventExposure
 * AMF Event Exposure Service © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * AmfEventTrigger.h
 *
 *
 */

#ifndef AmfEventTrigger_H_
#define AmfEventTrigger_H_

#include "AmfEventTrigger_anyOf.h"
#include <nlohmann/json.hpp>

namespace oai::amf::model {

/// <summary>
///
/// </summary>
class AmfEventTrigger {
 public:
  AmfEventTrigger();
  virtual ~AmfEventTrigger() = default;

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

  bool operator==(const AmfEventTrigger& rhs) const;
  bool operator!=(const AmfEventTrigger& rhs) const;

  /////////////////////////////////////////////
  /// AmfEventTrigger members

  friend void to_json(nlohmann::json& j, const AmfEventTrigger& o);
  friend void from_json(const nlohmann::json& j, AmfEventTrigger& o);

 protected:
  // Helper overload for validate. Used when one model stores another model and
  // calls it's validate.
  bool validate(std::stringstream& msg, const std::string& pathPrefix) const;
};

}  // namespace oai::amf::model

#endif /* AmfEventTrigger_H_ */
