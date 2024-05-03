/**
 * Nsmf_PDUSession
 * SMF PDU Session Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "SmContextUpdatedData.h"

namespace oai {
namespace smf_server {
namespace model {

using namespace oai::model::common;

SmContextUpdatedData::SmContextUpdatedData() {
  m_UpCnxStateIsSet       = false;
  m_HoStateIsSet          = false;
  m_ReleaseEbiListIsSet   = false;
  m_AllocatedEbiListIsSet = false;
  m_ModifiedEbiListIsSet  = false;
  m_N1SmMsgIsSet          = false;
  m_N2SmInfoIsSet         = false;
  m_N2SmInfoTypeIsSet     = false;
  m_EpsBearerSetupIsSet   = false;
  m_DataForwarding        = false;
  m_DataForwardingIsSet   = false;
  m_CauseIsSet            = false;
}

SmContextUpdatedData::~SmContextUpdatedData() {}

void SmContextUpdatedData::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const SmContextUpdatedData& o) {
  j = nlohmann::json();
  if (o.upCnxStateIsSet()) j["upCnxState"] = o.m_UpCnxState;
  if (o.hoStateIsSet()) j["hoState"] = o.m_HoState;
  if (o.releaseEbiListIsSet()) j["releaseEbiList"] = o.m_ReleaseEbiList;
  if (o.allocatedEbiListIsSet()) j["allocatedEbiList"] = o.m_AllocatedEbiList;
  if (o.modifiedEbiListIsSet()) j["modifiedEbiList"] = o.m_ModifiedEbiList;
  if (o.n1SmMsgIsSet()) j["n1SmMsg"] = o.m_N1SmMsg;
  if (o.n2SmInfoIsSet()) j["n2SmInfo"] = o.m_N2SmInfo;
  if (o.n2SmInfoTypeIsSet()) j["n2SmInfoType"] = o.m_N2SmInfoType;
  if (o.epsBearerSetupIsSet()) j["epsBearerSetup"] = o.m_EpsBearerSetup;
  if (o.dataForwardingIsSet()) j["dataForwarding"] = o.m_DataForwarding;
  if (o.causeIsSet()) j["cause"] = o.m_Cause;
}

void from_json(const nlohmann::json& j, SmContextUpdatedData& o) {
  if (j.find("upCnxState") != j.end()) {
    j.at("upCnxState").get_to(o.m_UpCnxState);
    o.m_UpCnxStateIsSet = true;
  }
  if (j.find("hoState") != j.end()) {
    j.at("hoState").get_to(o.m_HoState);
    o.m_HoStateIsSet = true;
  }
  if (j.find("releaseEbiList") != j.end()) {
    j.at("releaseEbiList").get_to(o.m_ReleaseEbiList);
    o.m_ReleaseEbiListIsSet = true;
  }
  if (j.find("allocatedEbiList") != j.end()) {
    j.at("allocatedEbiList").get_to(o.m_AllocatedEbiList);
    o.m_AllocatedEbiListIsSet = true;
  }
  if (j.find("modifiedEbiList") != j.end()) {
    j.at("modifiedEbiList").get_to(o.m_ModifiedEbiList);
    o.m_ModifiedEbiListIsSet = true;
  }
  if (j.find("n1SmMsg") != j.end()) {
    j.at("n1SmMsg").get_to(o.m_N1SmMsg);
    o.m_N1SmMsgIsSet = true;
  }
  if (j.find("n2SmInfo") != j.end()) {
    j.at("n2SmInfo").get_to(o.m_N2SmInfo);
    o.m_N2SmInfoIsSet = true;
  }
  if (j.find("n2SmInfoType") != j.end()) {
    j.at("n2SmInfoType").get_to(o.m_N2SmInfoType);
    o.m_N2SmInfoTypeIsSet = true;
  }
  if (j.find("epsBearerSetup") != j.end()) {
    j.at("epsBearerSetup").get_to(o.m_EpsBearerSetup);
    o.m_EpsBearerSetupIsSet = true;
  }
  if (j.find("dataForwarding") != j.end()) {
    j.at("dataForwarding").get_to(o.m_DataForwarding);
    o.m_DataForwardingIsSet = true;
  }
  if (j.find("cause") != j.end()) {
    j.at("cause").get_to(o.m_Cause);
    o.m_CauseIsSet = true;
  }
}

UpCnxState SmContextUpdatedData::getUpCnxState() const {
  return m_UpCnxState;
}
void SmContextUpdatedData::setUpCnxState(UpCnxState const& value) {
  m_UpCnxState      = value;
  m_UpCnxStateIsSet = true;
}
bool SmContextUpdatedData::upCnxStateIsSet() const {
  return m_UpCnxStateIsSet;
}
void SmContextUpdatedData::unsetUpCnxState() {
  m_UpCnxStateIsSet = false;
}
HoState SmContextUpdatedData::getHoState() const {
  return m_HoState;
}
void SmContextUpdatedData::setHoState(HoState const& value) {
  m_HoState      = value;
  m_HoStateIsSet = true;
}
bool SmContextUpdatedData::hoStateIsSet() const {
  return m_HoStateIsSet;
}
void SmContextUpdatedData::unsetHoState() {
  m_HoStateIsSet = false;
}
std::vector<int32_t>& SmContextUpdatedData::getReleaseEbiList() {
  return m_ReleaseEbiList;
}
bool SmContextUpdatedData::releaseEbiListIsSet() const {
  return m_ReleaseEbiListIsSet;
}
void SmContextUpdatedData::unsetReleaseEbiList() {
  m_ReleaseEbiListIsSet = false;
}
std::vector<EbiArpMapping>& SmContextUpdatedData::getAllocatedEbiList() {
  return m_AllocatedEbiList;
}
bool SmContextUpdatedData::allocatedEbiListIsSet() const {
  return m_AllocatedEbiListIsSet;
}
void SmContextUpdatedData::unsetAllocatedEbiList() {
  m_AllocatedEbiListIsSet = false;
}
std::vector<EbiArpMapping>& SmContextUpdatedData::getModifiedEbiList() {
  return m_ModifiedEbiList;
}
bool SmContextUpdatedData::modifiedEbiListIsSet() const {
  return m_ModifiedEbiListIsSet;
}
void SmContextUpdatedData::unsetModifiedEbiList() {
  m_ModifiedEbiListIsSet = false;
}
RefToBinaryData SmContextUpdatedData::getN1SmMsg() const {
  return m_N1SmMsg;
}
void SmContextUpdatedData::setN1SmMsg(RefToBinaryData const& value) {
  m_N1SmMsg      = value;
  m_N1SmMsgIsSet = true;
}
bool SmContextUpdatedData::n1SmMsgIsSet() const {
  return m_N1SmMsgIsSet;
}
void SmContextUpdatedData::unsetN1SmMsg() {
  m_N1SmMsgIsSet = false;
}
RefToBinaryData SmContextUpdatedData::getN2SmInfo() const {
  return m_N2SmInfo;
}
void SmContextUpdatedData::setN2SmInfo(RefToBinaryData const& value) {
  m_N2SmInfo      = value;
  m_N2SmInfoIsSet = true;
}
bool SmContextUpdatedData::n2SmInfoIsSet() const {
  return m_N2SmInfoIsSet;
}
void SmContextUpdatedData::unsetN2SmInfo() {
  m_N2SmInfoIsSet = false;
}
N2SmInfoType SmContextUpdatedData::getN2SmInfoType() const {
  return m_N2SmInfoType;
}
void SmContextUpdatedData::setN2SmInfoType(N2SmInfoType const& value) {
  m_N2SmInfoType      = value;
  m_N2SmInfoTypeIsSet = true;
}
bool SmContextUpdatedData::n2SmInfoTypeIsSet() const {
  return m_N2SmInfoTypeIsSet;
}
void SmContextUpdatedData::unsetN2SmInfoType() {
  m_N2SmInfoTypeIsSet = false;
}
std::vector<std::string>& SmContextUpdatedData::getEpsBearerSetup() {
  return m_EpsBearerSetup;
}
bool SmContextUpdatedData::epsBearerSetupIsSet() const {
  return m_EpsBearerSetupIsSet;
}
void SmContextUpdatedData::unsetEpsBearerSetup() {
  m_EpsBearerSetupIsSet = false;
}
bool SmContextUpdatedData::isDataForwarding() const {
  return m_DataForwarding;
}
void SmContextUpdatedData::setDataForwarding(bool const value) {
  m_DataForwarding      = value;
  m_DataForwardingIsSet = true;
}
bool SmContextUpdatedData::dataForwardingIsSet() const {
  return m_DataForwardingIsSet;
}
void SmContextUpdatedData::unsetDataForwarding() {
  m_DataForwardingIsSet = false;
}
Cause SmContextUpdatedData::getCause() const {
  return m_Cause;
}
void SmContextUpdatedData::setCause(Cause const& value) {
  m_Cause      = value;
  m_CauseIsSet = true;
}
bool SmContextUpdatedData::causeIsSet() const {
  return m_CauseIsSet;
}
void SmContextUpdatedData::unsetCause() {
  m_CauseIsSet = false;
}

}  // namespace model
}  // namespace smf_server
}  // namespace oai
