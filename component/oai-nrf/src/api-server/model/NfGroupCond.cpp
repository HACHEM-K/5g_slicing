/**
 * NRF NFManagement Service
 * NRF NFManagement Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "NfGroupCond.h"

namespace oai::model::nrf {

NfGroupCond::NfGroupCond() {
  m_NfType    = "";
  m_NfGroupId = "";
}

NfGroupCond::~NfGroupCond() {}

void NfGroupCond::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const NfGroupCond& o) {
  j              = nlohmann::json();
  j["nfType"]    = o.m_NfType;
  j["nfGroupId"] = o.m_NfGroupId;
}

void from_json(const nlohmann::json& j, NfGroupCond& o) {
  j.at("nfType").get_to(o.m_NfType);
  j.at("nfGroupId").get_to(o.m_NfGroupId);
}

std::string NfGroupCond::getNfType() const {
  return m_NfType;
}
void NfGroupCond::setNfType(std::string const& value) {
  m_NfType = value;
}
std::string NfGroupCond::getNfGroupId() const {
  return m_NfGroupId;
}
void NfGroupCond::setNfGroupId(std::string const& value) {
  m_NfGroupId = value;
}

}  // namespace oai::model::nrf
