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

#include "ReportItem.h"

#include <sstream>

#include "Helpers.h"

namespace oai::model::common {

ReportItem::ReportItem() {
  m_Path        = "";
  m_Reason      = "";
  m_ReasonIsSet = false;
}

void ReportItem::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw oai::model::common::helpers::ValidationException(msg.str());
  }
}

bool ReportItem::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ReportItem::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ReportItem" : pathPrefix;

  return success;
}

bool ReportItem::operator==(const ReportItem& rhs) const {
  return

      (getPath() == rhs.getPath()) &&

      ((!reasonIsSet() && !rhs.reasonIsSet()) ||
       (reasonIsSet() && rhs.reasonIsSet() && getReason() == rhs.getReason()))

          ;
}

bool ReportItem::operator!=(const ReportItem& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ReportItem& o) {
  j         = nlohmann::json();
  j["path"] = o.m_Path;
  if (o.reasonIsSet()) j["reason"] = o.m_Reason;
}

void from_json(const nlohmann::json& j, ReportItem& o) {
  j.at("path").get_to(o.m_Path);
  if (j.find("reason") != j.end()) {
    j.at("reason").get_to(o.m_Reason);
    o.m_ReasonIsSet = true;
  }
}

std::string ReportItem::getPath() const {
  return m_Path;
}
void ReportItem::setPath(std::string const& value) {
  m_Path = value;
}
std::string ReportItem::getReason() const {
  return m_Reason;
}
void ReportItem::setReason(std::string const& value) {
  m_Reason      = value;
  m_ReasonIsSet = true;
}
bool ReportItem::reasonIsSet() const {
  return m_ReasonIsSet;
}
void ReportItem::unsetReason() {
  m_ReasonIsSet = false;
}

}  // namespace oai::model::common