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

#include "RuleReport.h"
#include "Helpers.h"

#include <sstream>

namespace oai::model::pcf {

RuleReport::RuleReport() {
  m_ContVersIsSet        = false;
  m_FailureCodeIsSet     = false;
  m_FinUnitActIsSet      = false;
  m_RanNasRelCausesIsSet = false;
}

void RuleReport::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw oai::model::common::helpers::ValidationException(msg.str());
  }
}

bool RuleReport::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RuleReport::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RuleReport" : pathPrefix;

  /* PccRuleIds */ {
    const std::vector<std::string>& value = m_PccRuleIds;
    const std::string currentValuePath    = _pathPrefix + ".pccRuleIds";

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

  if (contVersIsSet()) {
    const std::vector<int32_t>& value  = m_ContVers;
    const std::string currentValuePath = _pathPrefix + ".contVers";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    /*
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const int32_t& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        i++;
      }
    }
    */
  }

  if (ranNasRelCausesIsSet()) {
    const std::vector<oai::model::pcf::RanNasRelCause>& value =
        m_RanNasRelCauses;
    const std::string currentValuePath = _pathPrefix + ".ranNasRelCauses";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const oai::model::pcf::RanNasRelCause& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success = value.validate(msg, currentValuePath + ".ranNasRelCauses") &&
                  success;

        i++;
      }
    }
  }

  return success;
}

bool RuleReport::operator==(const RuleReport& rhs) const {
  return

      (getPccRuleIds() == rhs.getPccRuleIds()) &&

      (getRuleStatus() == rhs.getRuleStatus()) &&

      ((!contVersIsSet() && !rhs.contVersIsSet()) ||
       (contVersIsSet() && rhs.contVersIsSet() &&
        getContVers() == rhs.getContVers())) &&

      ((!failureCodeIsSet() && !rhs.failureCodeIsSet()) ||
       (failureCodeIsSet() && rhs.failureCodeIsSet() &&
        getFailureCode() == rhs.getFailureCode())) &&

      ((!finUnitActIsSet() && !rhs.finUnitActIsSet()) ||
       (finUnitActIsSet() && rhs.finUnitActIsSet() &&
        getFinUnitAct() == rhs.getFinUnitAct())) &&

      ((!ranNasRelCausesIsSet() && !rhs.ranNasRelCausesIsSet()) ||
       (ranNasRelCausesIsSet() && rhs.ranNasRelCausesIsSet() &&
        getRanNasRelCauses() == rhs.getRanNasRelCauses()))

          ;
}

bool RuleReport::operator!=(const RuleReport& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RuleReport& o) {
  j               = nlohmann::json();
  j["pccRuleIds"] = o.m_PccRuleIds;
  j["ruleStatus"] = o.m_RuleStatus;
  if (o.contVersIsSet() || !o.m_ContVers.empty()) j["contVers"] = o.m_ContVers;
  if (o.failureCodeIsSet()) j["failureCode"] = o.m_FailureCode;
  if (o.finUnitActIsSet()) j["finUnitAct"] = o.m_FinUnitAct;
  if (o.ranNasRelCausesIsSet() || !o.m_RanNasRelCauses.empty())
    j["ranNasRelCauses"] = o.m_RanNasRelCauses;
}

void from_json(const nlohmann::json& j, RuleReport& o) {
  j.at("pccRuleIds").get_to(o.m_PccRuleIds);
  j.at("ruleStatus").get_to(o.m_RuleStatus);
  if (j.find("contVers") != j.end()) {
    j.at("contVers").get_to(o.m_ContVers);
    o.m_ContVersIsSet = true;
  }
  if (j.find("failureCode") != j.end()) {
    j.at("failureCode").get_to(o.m_FailureCode);
    o.m_FailureCodeIsSet = true;
  }
  if (j.find("finUnitAct") != j.end()) {
    j.at("finUnitAct").get_to(o.m_FinUnitAct);
    o.m_FinUnitActIsSet = true;
  }
  if (j.find("ranNasRelCauses") != j.end()) {
    j.at("ranNasRelCauses").get_to(o.m_RanNasRelCauses);
    o.m_RanNasRelCausesIsSet = true;
  }
}

std::vector<std::string> RuleReport::getPccRuleIds() const {
  return m_PccRuleIds;
}
void RuleReport::setPccRuleIds(std::vector<std::string> const& value) {
  m_PccRuleIds = value;
}
oai::model::pcf::RuleStatus RuleReport::getRuleStatus() const {
  return m_RuleStatus;
}
void RuleReport::setRuleStatus(oai::model::pcf::RuleStatus const& value) {
  m_RuleStatus = value;
}
std::vector<int32_t> RuleReport::getContVers() const {
  return m_ContVers;
}
void RuleReport::setContVers(std::vector<int32_t> const value) {
  m_ContVers      = value;
  m_ContVersIsSet = true;
}
bool RuleReport::contVersIsSet() const {
  return m_ContVersIsSet;
}
void RuleReport::unsetContVers() {
  m_ContVersIsSet = false;
}
oai::model::pcf::FailureCode RuleReport::getFailureCode() const {
  return m_FailureCode;
}
void RuleReport::setFailureCode(oai::model::pcf::FailureCode const& value) {
  m_FailureCode      = value;
  m_FailureCodeIsSet = true;
}
bool RuleReport::failureCodeIsSet() const {
  return m_FailureCodeIsSet;
}
void RuleReport::unsetFailureCode() {
  m_FailureCodeIsSet = false;
}
oai::model::pcf::FinalUnitAction RuleReport::getFinUnitAct() const {
  return m_FinUnitAct;
}
void RuleReport::setFinUnitAct(oai::model::pcf::FinalUnitAction const& value) {
  m_FinUnitAct      = value;
  m_FinUnitActIsSet = true;
}
bool RuleReport::finUnitActIsSet() const {
  return m_FinUnitActIsSet;
}
void RuleReport::unsetFinUnitAct() {
  m_FinUnitActIsSet = false;
}
std::vector<oai::model::pcf::RanNasRelCause> RuleReport::getRanNasRelCauses()
    const {
  return m_RanNasRelCauses;
}
void RuleReport::setRanNasRelCauses(
    std::vector<oai::model::pcf::RanNasRelCause> const& value) {
  m_RanNasRelCauses      = value;
  m_RanNasRelCausesIsSet = true;
}
bool RuleReport::ranNasRelCausesIsSet() const {
  return m_RanNasRelCausesIsSet;
}
void RuleReport::unsetRanNasRelCauses() {
  m_RanNasRelCausesIsSet = false;
}

}  // namespace oai::model::pcf
