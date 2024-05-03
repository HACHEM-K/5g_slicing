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

#include "Ipv6Addr.h"
#include "Helpers.h"

#include <sstream>

namespace oai::model::common {

Ipv6Addr::Ipv6Addr() {}

void Ipv6Addr::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw oai::model::common::helpers::ValidationException(msg.str());
  }
}

bool Ipv6Addr::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Ipv6Addr::validate(
    std::stringstream& /* msg */, const std::string& /* pathPrefix */) const {
  bool success = true;
  /*
  const std::string _pathPrefix = pathPrefix.empty() ? "Ipv6Addr" : pathPrefix;
  */
  return success;
}

bool Ipv6Addr::operator==(const Ipv6Addr& rhs) const {
  return getIpv6Addr() == rhs.getIpv6Addr();
}

bool Ipv6Addr::operator!=(const Ipv6Addr& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Ipv6Addr& o) {
  j = nlohmann::json();
  j = o.getIpv6Addr();
}

void from_json(const nlohmann::json& j, Ipv6Addr& o) {
  o.setIpv6Addr(j);
}

std::string Ipv6Addr::getIpv6Addr() const {
  return m_Ipv6Addr;
}
void Ipv6Addr::setIpv6Addr(std::string const& value) {
  m_Ipv6Addr = value;
}

}  // namespace oai::model::common
