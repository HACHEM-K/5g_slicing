/**
 * 3gpp-monitoring-event
 * API for Monitoring Event. © 2021, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.2.0-alpha.4
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "InterfaceIndication_anyOf.h"

#include <sstream>
#include <stdexcept>

#include "Helpers.h"

namespace oai::nef::model {

InterfaceIndication_anyOf::InterfaceIndication_anyOf() {}

void InterfaceIndication_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw oai::nef::helpers::ValidationException(msg.str());
  }
}

bool InterfaceIndication_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool InterfaceIndication_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "InterfaceIndication_anyOf" : pathPrefix;

  if (m_value == InterfaceIndication_anyOf::eInterfaceIndication_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool InterfaceIndication_anyOf::operator==(
    const InterfaceIndication_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool InterfaceIndication_anyOf::operator!=(
    const InterfaceIndication_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const InterfaceIndication_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case InterfaceIndication_anyOf::eInterfaceIndication_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case InterfaceIndication_anyOf::eInterfaceIndication_anyOf::
        EXPOSURE_FUNCTION:
      j = "EXPOSURE_FUNCTION";
      break;
    case InterfaceIndication_anyOf::eInterfaceIndication_anyOf::PDN_GATEWAY:
      j = "PDN_GATEWAY";
      break;
  }
}

void from_json(const nlohmann::json& j, InterfaceIndication_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "EXPOSURE_FUNCTION") {
    o.setValue(InterfaceIndication_anyOf::eInterfaceIndication_anyOf::
                   EXPOSURE_FUNCTION);
  } else if (s == "PDN_GATEWAY") {
    o.setValue(
        InterfaceIndication_anyOf::eInterfaceIndication_anyOf::PDN_GATEWAY);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " InterfaceIndication_anyOf::eInterfaceIndication_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

InterfaceIndication_anyOf::eInterfaceIndication_anyOf
InterfaceIndication_anyOf::getValue() const {
  return m_value;
}
void InterfaceIndication_anyOf::setValue(
    InterfaceIndication_anyOf::eInterfaceIndication_anyOf value) {
  m_value = value;
}

}  // namespace oai::nef::model