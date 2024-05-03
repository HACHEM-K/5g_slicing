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

#include "AccNetChId.h"
#include "Helpers.h"

#include <sstream>

namespace oai::model::pcf {

AccNetChId::AccNetChId() {
  m_AccNetChaIdValue    = 0;
  m_RefPccRuleIdsIsSet  = false;
  m_SessionChScope      = false;
  m_SessionChScopeIsSet = false;
}

void AccNetChId::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw oai::model::common::helpers::ValidationException(msg.str());
  }
}

bool AccNetChId::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool AccNetChId::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "AccNetChId" : pathPrefix;

  /* AccNetChaIdValue */ {
    const int32_t& value               = m_AccNetChaIdValue;
    const std::string currentValuePath = _pathPrefix + ".accNetChaIdValue";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
    if (value > 4294967295) {
      success = false;
      msg << currentValuePath << ": must be less than or equal to 4294967295;";
    }
  }

  if (refPccRuleIdsIsSet()) {
    const std::vector<std::string>& value = m_RefPccRuleIds;
    const std::string currentValuePath    = _pathPrefix + ".refPccRuleIds";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    /*
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const std::string& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        i++;
      }
    }
    */
  }

  return success;
}

bool AccNetChId::operator==(const AccNetChId& rhs) const {
  return

      (getAccNetChaIdValue() == rhs.getAccNetChaIdValue()) &&

      ((!refPccRuleIdsIsSet() && !rhs.refPccRuleIdsIsSet()) ||
       (refPccRuleIdsIsSet() && rhs.refPccRuleIdsIsSet() &&
        getRefPccRuleIds() == rhs.getRefPccRuleIds())) &&

      ((!sessionChScopeIsSet() && !rhs.sessionChScopeIsSet()) ||
       (sessionChScopeIsSet() && rhs.sessionChScopeIsSet() &&
        isSessionChScope() == rhs.isSessionChScope()))

          ;
}

bool AccNetChId::operator!=(const AccNetChId& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const AccNetChId& o) {
  j                     = nlohmann::json();
  j["accNetChaIdValue"] = o.m_AccNetChaIdValue;
  if (o.refPccRuleIdsIsSet() || !o.m_RefPccRuleIds.empty())
    j["refPccRuleIds"] = o.m_RefPccRuleIds;
  if (o.sessionChScopeIsSet()) j["sessionChScope"] = o.m_SessionChScope;
}

void from_json(const nlohmann::json& j, AccNetChId& o) {
  j.at("accNetChaIdValue").get_to(o.m_AccNetChaIdValue);
  if (j.find("refPccRuleIds") != j.end()) {
    j.at("refPccRuleIds").get_to(o.m_RefPccRuleIds);
    o.m_RefPccRuleIdsIsSet = true;
  }
  if (j.find("sessionChScope") != j.end()) {
    j.at("sessionChScope").get_to(o.m_SessionChScope);
    o.m_SessionChScopeIsSet = true;
  }
}

uint32_t AccNetChId::getAccNetChaIdValue() const {
  return m_AccNetChaIdValue;
}
void AccNetChId::setAccNetChaIdValue(uint32_t const value) {
  m_AccNetChaIdValue = value;
}
std::vector<std::string> AccNetChId::getRefPccRuleIds() const {
  return m_RefPccRuleIds;
}
void AccNetChId::setRefPccRuleIds(std::vector<std::string> const& value) {
  m_RefPccRuleIds      = value;
  m_RefPccRuleIdsIsSet = true;
}
bool AccNetChId::refPccRuleIdsIsSet() const {
  return m_RefPccRuleIdsIsSet;
}
void AccNetChId::unsetRefPccRuleIds() {
  m_RefPccRuleIdsIsSet = false;
}
bool AccNetChId::isSessionChScope() const {
  return m_SessionChScope;
}
void AccNetChId::setSessionChScope(bool const value) {
  m_SessionChScope      = value;
  m_SessionChScopeIsSet = true;
}
bool AccNetChId::sessionChScopeIsSet() const {
  return m_SessionChScopeIsSet;
}
void AccNetChId::unsetSessionChScope() {
  m_SessionChScopeIsSet = false;
}

}  // namespace oai::model::pcf