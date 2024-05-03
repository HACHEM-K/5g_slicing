/**
 * Npcf_SMPolicyControl API
 * Session Management Policy Control Service © 2023, 3GPP Organizational
 * Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.9
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "ConditionData.h"
#include "Helpers.h"

#include <sstream>

namespace oai::model::pcf {
using namespace oai::model::common;

ConditionData::ConditionData() {
  m_CondId                = "";
  m_ActivationTime        = "";
  m_ActivationTimeIsSet   = false;
  m_DeactivationTime      = "";
  m_DeactivationTimeIsSet = false;
  m_AccessTypeIsSet       = false;
  m_RatTypeIsSet          = false;
}

void ConditionData::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw oai::model::common::helpers::ValidationException(msg.str());
  }
}

bool ConditionData::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ConditionData::validate(
    std::stringstream& /* msg */, const std::string& /* pathPrefix */) const {
  bool success = true;
  /*
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ConditionData" : pathPrefix;
  */
  return success;
}

bool ConditionData::operator==(const ConditionData& rhs) const {
  return

      (getCondId() == rhs.getCondId()) &&

      ((!activationTimeIsSet() && !rhs.activationTimeIsSet()) ||
       (activationTimeIsSet() && rhs.activationTimeIsSet() &&
        getActivationTime() == rhs.getActivationTime())) &&

      ((!deactivationTimeIsSet() && !rhs.deactivationTimeIsSet()) ||
       (deactivationTimeIsSet() && rhs.deactivationTimeIsSet() &&
        getDeactivationTime() == rhs.getDeactivationTime())) &&

      ((!accessTypeIsSet() && !rhs.accessTypeIsSet()) ||
       (accessTypeIsSet() && rhs.accessTypeIsSet() &&
        getAccessType() == rhs.getAccessType())) &&

      ((!ratTypeIsSet() && !rhs.ratTypeIsSet()) ||
       (ratTypeIsSet() && rhs.ratTypeIsSet() &&
        getRatType() == rhs.getRatType()))

          ;
}

bool ConditionData::operator!=(const ConditionData& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ConditionData& o) {
  j           = nlohmann::json();
  j["condId"] = o.m_CondId;
  if (o.activationTimeIsSet()) j["activationTime"] = o.m_ActivationTime;
  if (o.deactivationTimeIsSet()) j["deactivationTime"] = o.m_DeactivationTime;
  if (o.accessTypeIsSet()) j["accessType"] = o.m_AccessType;
  if (o.ratTypeIsSet()) j["ratType"] = o.m_RatType;
}

void from_json(const nlohmann::json& j, ConditionData& o) {
  j.at("condId").get_to(o.m_CondId);
  if (j.find("activationTime") != j.end()) {
    j.at("activationTime").get_to(o.m_ActivationTime);
    o.m_ActivationTimeIsSet = true;
  }
  if (j.find("deactivationTime") != j.end()) {
    j.at("deactivationTime").get_to(o.m_DeactivationTime);
    o.m_DeactivationTimeIsSet = true;
  }
  if (j.find("accessType") != j.end()) {
    j.at("accessType").get_to(o.m_AccessType);
    o.m_AccessTypeIsSet = true;
  }
  if (j.find("ratType") != j.end()) {
    j.at("ratType").get_to(o.m_RatType);
    o.m_RatTypeIsSet = true;
  }
}

std::string ConditionData::getCondId() const {
  return m_CondId;
}
void ConditionData::setCondId(std::string const& value) {
  m_CondId = value;
}
std::string ConditionData::getActivationTime() const {
  return m_ActivationTime;
}
void ConditionData::setActivationTime(std::string const& value) {
  m_ActivationTime      = value;
  m_ActivationTimeIsSet = true;
}
bool ConditionData::activationTimeIsSet() const {
  return m_ActivationTimeIsSet;
}
void ConditionData::unsetActivationTime() {
  m_ActivationTimeIsSet = false;
}
std::string ConditionData::getDeactivationTime() const {
  return m_DeactivationTime;
}
void ConditionData::setDeactivationTime(std::string const& value) {
  m_DeactivationTime      = value;
  m_DeactivationTimeIsSet = true;
}
bool ConditionData::deactivationTimeIsSet() const {
  return m_DeactivationTimeIsSet;
}
void ConditionData::unsetDeactivationTime() {
  m_DeactivationTimeIsSet = false;
}
AccessType ConditionData::getAccessType() const {
  return m_AccessType;
}
void ConditionData::setAccessType(AccessType const& value) {
  m_AccessType      = value;
  m_AccessTypeIsSet = true;
}
bool ConditionData::accessTypeIsSet() const {
  return m_AccessTypeIsSet;
}
void ConditionData::unsetAccessType() {
  m_AccessTypeIsSet = false;
}
RatType ConditionData::getRatType() const {
  return m_RatType;
}
void ConditionData::setRatType(RatType const& value) {
  m_RatType      = value;
  m_RatTypeIsSet = true;
}
bool ConditionData::ratTypeIsSet() const {
  return m_RatTypeIsSet;
}
void ConditionData::unsetRatType() {
  m_RatTypeIsSet = false;
}

}  // namespace oai::model::pcf