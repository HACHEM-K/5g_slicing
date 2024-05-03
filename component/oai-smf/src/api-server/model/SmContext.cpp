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

#include "SmContext.h"

namespace oai {
namespace smf_server {
namespace model {

using namespace oai::model::common;
using namespace oai::model::nrf;

SmContext::SmContext() {
  m_Supi                               = "";
  m_SupiIsSet                          = false;
  m_UnauthenticatedSupi                = false;
  m_UnauthenticatedSupiIsSet           = false;
  m_Pei                                = "";
  m_PeiIsSet                           = false;
  m_Gpsi                               = "";
  m_GpsiIsSet                          = false;
  m_PduSessionId                       = 0;
  m_Dnn                                = "";
  m_HplmnSnssaiIsSet                   = false;
  m_ServingNfId                        = "";
  m_GuamiIsSet                         = false;
  m_ServiceNameIsSet                   = false;
  m_RatTypeIsSet                       = false;
  m_SmContextStatusUri                 = "";
  m_HSmfUri                            = "";
  m_HSmfUriIsSet                       = false;
  m_PcfId                              = "";
  m_PcfIdIsSet                         = false;
  m_SelModeIsSet                       = false;
  m_TraceDataIsSet                     = false;
  m_UdmGroupId                         = "";
  m_UdmGroupIdIsSet                    = false;
  m_RoutingIndicator                   = "";
  m_RoutingIndicatorIsSet              = false;
  m_EpsInterworkingIndIsSet            = false;
  m_SscMode                            = "";
  m_HSmfInstanceId                     = "";
  m_HSmfInstanceIdIsSet                = false;
  m_EnablePauseCharging                = false;
  m_EnablePauseChargingIsSet           = false;
  m_UeIpv4Address                      = "";
  m_UeIpv4AddressIsSet                 = false;
  m_UeIpv6PrefixIsSet                  = false;
  m_EpsPdnCnxInfoIsSet                 = false;
  m_EpsBearerInfoIsSet                 = false;
  m_MaxIntegrityProtectedDataRateIsSet = false;
  m_AlwaysOnGranted                    = false;
  m_AlwaysOnGrantedIsSet               = false;
  m_UpSecurityIsSet                    = false;
  m_HSmfServiceInstanceId              = "";
  m_HSmfServiceInstanceIdIsSet         = false;
  m_RecoveryTime                       = "";
  m_RecoveryTimeIsSet                  = false;
}

SmContext::~SmContext() {}

void SmContext::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const SmContext& o) {
  j = nlohmann::json();
  if (o.supiIsSet()) j["supi"] = o.m_Supi;
  if (o.unauthenticatedSupiIsSet())
    j["unauthenticatedSupi"] = o.m_UnauthenticatedSupi;
  if (o.peiIsSet()) j["pei"] = o.m_Pei;
  if (o.gpsiIsSet()) j["gpsi"] = o.m_Gpsi;
  j["pduSessionId"] = o.m_PduSessionId;
  j["dnn"]          = o.m_Dnn;
  j["sNssai"]       = o.m_SNssai;
  if (o.hplmnSnssaiIsSet()) j["hplmnSnssai"] = o.m_HplmnSnssai;
  j["servingNfId"] = o.m_ServingNfId;
  if (o.guamiIsSet()) j["guami"] = o.m_Guami;
  if (o.serviceNameIsSet()) j["serviceName"] = o.m_ServiceName;
  j["servingNetwork"] = o.m_ServingNetwork;
  j["anType"]         = o.m_AnType;
  if (o.ratTypeIsSet()) j["ratType"] = o.m_RatType;
  j["smContextStatusUri"] = o.m_SmContextStatusUri;
  if (o.hSmfUriIsSet()) j["hSmfUri"] = o.m_HSmfUri;
  if (o.pcfIdIsSet()) j["pcfId"] = o.m_PcfId;
  if (o.selModeIsSet()) j["selMode"] = o.m_SelMode;
  if (o.traceDataIsSet()) j["traceData"] = o.m_TraceData;
  if (o.udmGroupIdIsSet()) j["udmGroupId"] = o.m_UdmGroupId;
  if (o.routingIndicatorIsSet()) j["routingIndicator"] = o.m_RoutingIndicator;
  if (o.epsInterworkingIndIsSet())
    j["epsInterworkingInd"] = o.m_EpsInterworkingInd;
  j["pduSessionType"]    = o.m_PduSessionType;
  j["sscMode"]           = o.m_SscMode;
  j["sessionAmbr"]       = o.m_SessionAmbr;
  j["qosFlowsSetupList"] = o.m_QosFlowsSetupList;
  if (o.hSmfInstanceIdIsSet()) j["hSmfInstanceId"] = o.m_HSmfInstanceId;
  if (o.enablePauseChargingIsSet())
    j["enablePauseCharging"] = o.m_EnablePauseCharging;
  if (o.ueIpv4AddressIsSet()) j["ueIpv4Address"] = o.m_UeIpv4Address;
  if (o.ueIpv6PrefixIsSet()) j["ueIpv6Prefix"] = o.m_UeIpv6Prefix;
  if (o.epsPdnCnxInfoIsSet()) j["epsPdnCnxInfo"] = o.m_EpsPdnCnxInfo;
  if (o.epsBearerInfoIsSet()) j["epsBearerInfo"] = o.m_EpsBearerInfo;
  if (o.maxIntegrityProtectedDataRateIsSet())
    j["maxIntegrityProtectedDataRate"] = o.m_MaxIntegrityProtectedDataRate;
  if (o.alwaysOnGrantedIsSet()) j["alwaysOnGranted"] = o.m_AlwaysOnGranted;
  if (o.upSecurityIsSet()) j["upSecurity"] = o.m_UpSecurity;
  if (o.hSmfServiceInstanceIdIsSet())
    j["hSmfServiceInstanceId"] = o.m_HSmfServiceInstanceId;
  if (o.recoveryTimeIsSet()) j["recoveryTime"] = o.m_RecoveryTime;
}

void from_json(const nlohmann::json& j, SmContext& o) {
  if (j.find("supi") != j.end()) {
    j.at("supi").get_to(o.m_Supi);
    o.m_SupiIsSet = true;
  }
  if (j.find("unauthenticatedSupi") != j.end()) {
    j.at("unauthenticatedSupi").get_to(o.m_UnauthenticatedSupi);
    o.m_UnauthenticatedSupiIsSet = true;
  }
  if (j.find("pei") != j.end()) {
    j.at("pei").get_to(o.m_Pei);
    o.m_PeiIsSet = true;
  }
  if (j.find("gpsi") != j.end()) {
    j.at("gpsi").get_to(o.m_Gpsi);
    o.m_GpsiIsSet = true;
  }
  j.at("pduSessionId").get_to(o.m_PduSessionId);
  j.at("dnn").get_to(o.m_Dnn);
  j.at("sNssai").get_to(o.m_SNssai);
  if (j.find("hplmnSnssai") != j.end()) {
    j.at("hplmnSnssai").get_to(o.m_HplmnSnssai);
    o.m_HplmnSnssaiIsSet = true;
  }
  j.at("servingNfId").get_to(o.m_ServingNfId);
  if (j.find("guami") != j.end()) {
    j.at("guami").get_to(o.m_Guami);
    o.m_GuamiIsSet = true;
  }
  if (j.find("serviceName") != j.end()) {
    j.at("serviceName").get_to(o.m_ServiceName);
    o.m_ServiceNameIsSet = true;
  }
  j.at("servingNetwork").get_to(o.m_ServingNetwork);
  j.at("anType").get_to(o.m_AnType);
  if (j.find("ratType") != j.end()) {
    j.at("ratType").get_to(o.m_RatType);
    o.m_RatTypeIsSet = true;
  }
  j.at("smContextStatusUri").get_to(o.m_SmContextStatusUri);
  if (j.find("hSmfUri") != j.end()) {
    j.at("hSmfUri").get_to(o.m_HSmfUri);
    o.m_HSmfUriIsSet = true;
  }
  if (j.find("pcfId") != j.end()) {
    j.at("pcfId").get_to(o.m_PcfId);
    o.m_PcfIdIsSet = true;
  }
  if (j.find("selMode") != j.end()) {
    j.at("selMode").get_to(o.m_SelMode);
    o.m_SelModeIsSet = true;
  }
  if (j.find("traceData") != j.end()) {
    j.at("traceData").get_to(o.m_TraceData);
    o.m_TraceDataIsSet = true;
  }
  if (j.find("udmGroupId") != j.end()) {
    j.at("udmGroupId").get_to(o.m_UdmGroupId);
    o.m_UdmGroupIdIsSet = true;
  }
  if (j.find("routingIndicator") != j.end()) {
    j.at("routingIndicator").get_to(o.m_RoutingIndicator);
    o.m_RoutingIndicatorIsSet = true;
  }
  if (j.find("epsInterworkingInd") != j.end()) {
    j.at("epsInterworkingInd").get_to(o.m_EpsInterworkingInd);
    o.m_EpsInterworkingIndIsSet = true;
  }
  j.at("pduSessionType").get_to(o.m_PduSessionType);
  j.at("sscMode").get_to(o.m_SscMode);
  j.at("sessionAmbr").get_to(o.m_SessionAmbr);
  j.at("qosFlowsSetupList").get_to(o.m_QosFlowsSetupList);
  if (j.find("hSmfInstanceId") != j.end()) {
    j.at("hSmfInstanceId").get_to(o.m_HSmfInstanceId);
    o.m_HSmfInstanceIdIsSet = true;
  }
  if (j.find("enablePauseCharging") != j.end()) {
    j.at("enablePauseCharging").get_to(o.m_EnablePauseCharging);
    o.m_EnablePauseChargingIsSet = true;
  }
  if (j.find("ueIpv4Address") != j.end()) {
    j.at("ueIpv4Address").get_to(o.m_UeIpv4Address);
    o.m_UeIpv4AddressIsSet = true;
  }
  if (j.find("ueIpv6Prefix") != j.end()) {
    j.at("ueIpv6Prefix").get_to(o.m_UeIpv6Prefix);
    o.m_UeIpv6PrefixIsSet = true;
  }
  if (j.find("epsPdnCnxInfo") != j.end()) {
    j.at("epsPdnCnxInfo").get_to(o.m_EpsPdnCnxInfo);
    o.m_EpsPdnCnxInfoIsSet = true;
  }
  if (j.find("epsBearerInfo") != j.end()) {
    j.at("epsBearerInfo").get_to(o.m_EpsBearerInfo);
    o.m_EpsBearerInfoIsSet = true;
  }
  if (j.find("maxIntegrityProtectedDataRate") != j.end()) {
    j.at("maxIntegrityProtectedDataRate")
        .get_to(o.m_MaxIntegrityProtectedDataRate);
    o.m_MaxIntegrityProtectedDataRateIsSet = true;
  }
  if (j.find("alwaysOnGranted") != j.end()) {
    j.at("alwaysOnGranted").get_to(o.m_AlwaysOnGranted);
    o.m_AlwaysOnGrantedIsSet = true;
  }
  if (j.find("upSecurity") != j.end()) {
    j.at("upSecurity").get_to(o.m_UpSecurity);
    o.m_UpSecurityIsSet = true;
  }
  if (j.find("hSmfServiceInstanceId") != j.end()) {
    j.at("hSmfServiceInstanceId").get_to(o.m_HSmfServiceInstanceId);
    o.m_HSmfServiceInstanceIdIsSet = true;
  }
  if (j.find("recoveryTime") != j.end()) {
    j.at("recoveryTime").get_to(o.m_RecoveryTime);
    o.m_RecoveryTimeIsSet = true;
  }
}

std::string SmContext::getSupi() const {
  return m_Supi;
}
void SmContext::setSupi(std::string const& value) {
  m_Supi      = value;
  m_SupiIsSet = true;
}
bool SmContext::supiIsSet() const {
  return m_SupiIsSet;
}
void SmContext::unsetSupi() {
  m_SupiIsSet = false;
}
bool SmContext::isUnauthenticatedSupi() const {
  return m_UnauthenticatedSupi;
}
void SmContext::setUnauthenticatedSupi(bool const value) {
  m_UnauthenticatedSupi      = value;
  m_UnauthenticatedSupiIsSet = true;
}
bool SmContext::unauthenticatedSupiIsSet() const {
  return m_UnauthenticatedSupiIsSet;
}
void SmContext::unsetUnauthenticatedSupi() {
  m_UnauthenticatedSupiIsSet = false;
}
std::string SmContext::getPei() const {
  return m_Pei;
}
void SmContext::setPei(std::string const& value) {
  m_Pei      = value;
  m_PeiIsSet = true;
}
bool SmContext::peiIsSet() const {
  return m_PeiIsSet;
}
void SmContext::unsetPei() {
  m_PeiIsSet = false;
}
std::string SmContext::getGpsi() const {
  return m_Gpsi;
}
void SmContext::setGpsi(std::string const& value) {
  m_Gpsi      = value;
  m_GpsiIsSet = true;
}
bool SmContext::gpsiIsSet() const {
  return m_GpsiIsSet;
}
void SmContext::unsetGpsi() {
  m_GpsiIsSet = false;
}
int32_t SmContext::getPduSessionId() const {
  return m_PduSessionId;
}
void SmContext::setPduSessionId(int32_t const value) {
  m_PduSessionId = value;
}
std::string SmContext::getDnn() const {
  return m_Dnn;
}
void SmContext::setDnn(std::string const& value) {
  m_Dnn = value;
}
oai::model::common::Snssai SmContext::getSNssai() const {
  return m_SNssai;
}
void SmContext::setSNssai(oai::model::common::Snssai const& value) {
  m_SNssai = value;
}
oai::model::common::Snssai SmContext::getHplmnSnssai() const {
  return m_HplmnSnssai;
}
void SmContext::setHplmnSnssai(oai::model::common::Snssai const& value) {
  m_HplmnSnssai      = value;
  m_HplmnSnssaiIsSet = true;
}
bool SmContext::hplmnSnssaiIsSet() const {
  return m_HplmnSnssaiIsSet;
}
void SmContext::unsetHplmnSnssai() {
  m_HplmnSnssaiIsSet = false;
}
std::string SmContext::getServingNfId() const {
  return m_ServingNfId;
}
void SmContext::setServingNfId(std::string const& value) {
  m_ServingNfId = value;
}
Guami SmContext::getGuami() const {
  return m_Guami;
}
void SmContext::setGuami(Guami const& value) {
  m_Guami      = value;
  m_GuamiIsSet = true;
}
bool SmContext::guamiIsSet() const {
  return m_GuamiIsSet;
}
void SmContext::unsetGuami() {
  m_GuamiIsSet = false;
}
ServiceName SmContext::getServiceName() const {
  return m_ServiceName;
}
void SmContext::setServiceName(ServiceName const& value) {
  m_ServiceName      = value;
  m_ServiceNameIsSet = true;
}
bool SmContext::serviceNameIsSet() const {
  return m_ServiceNameIsSet;
}
void SmContext::unsetServiceName() {
  m_ServiceNameIsSet = false;
}
oai::model::common::PlmnId SmContext::getServingNetwork() const {
  return m_ServingNetwork;
}
void SmContext::setServingNetwork(oai::model::common::PlmnId const& value) {
  m_ServingNetwork = value;
}
oai::model::common::AccessType SmContext::getAnType() const {
  return m_AnType;
}
void SmContext::setAnType(oai::model::common::AccessType const& value) {
  m_AnType = value;
}
RatType SmContext::getRatType() const {
  return m_RatType;
}
void SmContext::setRatType(RatType const& value) {
  m_RatType      = value;
  m_RatTypeIsSet = true;
}
bool SmContext::ratTypeIsSet() const {
  return m_RatTypeIsSet;
}
void SmContext::unsetRatType() {
  m_RatTypeIsSet = false;
}
std::string SmContext::getSmContextStatusUri() const {
  return m_SmContextStatusUri;
}
void SmContext::setSmContextStatusUri(std::string const& value) {
  m_SmContextStatusUri = value;
}
std::string SmContext::getHSmfUri() const {
  return m_HSmfUri;
}
void SmContext::setHSmfUri(std::string const& value) {
  m_HSmfUri      = value;
  m_HSmfUriIsSet = true;
}
bool SmContext::hSmfUriIsSet() const {
  return m_HSmfUriIsSet;
}
void SmContext::unsetHSmfUri() {
  m_HSmfUriIsSet = false;
}
std::string SmContext::getPcfId() const {
  return m_PcfId;
}
void SmContext::setPcfId(std::string const& value) {
  m_PcfId      = value;
  m_PcfIdIsSet = true;
}
bool SmContext::pcfIdIsSet() const {
  return m_PcfIdIsSet;
}
void SmContext::unsetPcfId() {
  m_PcfIdIsSet = false;
}
oai::model::smf::DnnSelectionMode SmContext::getSelMode() const {
  return m_SelMode;
}
void SmContext::setSelMode(oai::model::smf::DnnSelectionMode const& value) {
  m_SelMode      = value;
  m_SelModeIsSet = true;
}
bool SmContext::selModeIsSet() const {
  return m_SelModeIsSet;
}
void SmContext::unsetSelMode() {
  m_SelModeIsSet = false;
}
TraceData SmContext::getTraceData() const {
  return m_TraceData;
}
void SmContext::setTraceData(TraceData const& value) {
  m_TraceData      = value;
  m_TraceDataIsSet = true;
}
bool SmContext::traceDataIsSet() const {
  return m_TraceDataIsSet;
}
void SmContext::unsetTraceData() {
  m_TraceDataIsSet = false;
}
std::string SmContext::getUdmGroupId() const {
  return m_UdmGroupId;
}
void SmContext::setUdmGroupId(std::string const& value) {
  m_UdmGroupId      = value;
  m_UdmGroupIdIsSet = true;
}
bool SmContext::udmGroupIdIsSet() const {
  return m_UdmGroupIdIsSet;
}
void SmContext::unsetUdmGroupId() {
  m_UdmGroupIdIsSet = false;
}
std::string SmContext::getRoutingIndicator() const {
  return m_RoutingIndicator;
}
void SmContext::setRoutingIndicator(std::string const& value) {
  m_RoutingIndicator      = value;
  m_RoutingIndicatorIsSet = true;
}
bool SmContext::routingIndicatorIsSet() const {
  return m_RoutingIndicatorIsSet;
}
void SmContext::unsetRoutingIndicator() {
  m_RoutingIndicatorIsSet = false;
}
EpsInterworkingIndication SmContext::getEpsInterworkingInd() const {
  return m_EpsInterworkingInd;
}
void SmContext::setEpsInterworkingInd(EpsInterworkingIndication const& value) {
  m_EpsInterworkingInd      = value;
  m_EpsInterworkingIndIsSet = true;
}
bool SmContext::epsInterworkingIndIsSet() const {
  return m_EpsInterworkingIndIsSet;
}
void SmContext::unsetEpsInterworkingInd() {
  m_EpsInterworkingIndIsSet = false;
}
PduSessionType SmContext::getPduSessionType() const {
  return m_PduSessionType;
}
void SmContext::setPduSessionType(PduSessionType const& value) {
  m_PduSessionType = value;
}
std::string SmContext::getSscMode() const {
  return m_SscMode;
}
void SmContext::setSscMode(std::string const& value) {
  m_SscMode = value;
}
Ambr SmContext::getSessionAmbr() const {
  return m_SessionAmbr;
}
void SmContext::setSessionAmbr(Ambr const& value) {
  m_SessionAmbr = value;
}
std::vector<QosFlowSetupItem>& SmContext::getQosFlowsSetupList() {
  return m_QosFlowsSetupList;
}
std::string SmContext::getHSmfInstanceId() const {
  return m_HSmfInstanceId;
}
void SmContext::setHSmfInstanceId(std::string const& value) {
  m_HSmfInstanceId      = value;
  m_HSmfInstanceIdIsSet = true;
}
bool SmContext::hSmfInstanceIdIsSet() const {
  return m_HSmfInstanceIdIsSet;
}
void SmContext::unsetHSmfInstanceId() {
  m_HSmfInstanceIdIsSet = false;
}
bool SmContext::isEnablePauseCharging() const {
  return m_EnablePauseCharging;
}
void SmContext::setEnablePauseCharging(bool const value) {
  m_EnablePauseCharging      = value;
  m_EnablePauseChargingIsSet = true;
}
bool SmContext::enablePauseChargingIsSet() const {
  return m_EnablePauseChargingIsSet;
}
void SmContext::unsetEnablePauseCharging() {
  m_EnablePauseChargingIsSet = false;
}
std::string SmContext::getUeIpv4Address() const {
  return m_UeIpv4Address;
}
void SmContext::setUeIpv4Address(std::string const& value) {
  m_UeIpv4Address      = value;
  m_UeIpv4AddressIsSet = true;
}
bool SmContext::ueIpv4AddressIsSet() const {
  return m_UeIpv4AddressIsSet;
}
void SmContext::unsetUeIpv4Address() {
  m_UeIpv4AddressIsSet = false;
}
std::string SmContext::getUeIpv6Prefix() const {
  return m_UeIpv6Prefix;
}
void SmContext::setUeIpv6Prefix(std::string const& value) {
  m_UeIpv6Prefix      = value;
  m_UeIpv6PrefixIsSet = true;
}
bool SmContext::ueIpv6PrefixIsSet() const {
  return m_UeIpv6PrefixIsSet;
}
void SmContext::unsetUeIpv6Prefix() {
  m_UeIpv6PrefixIsSet = false;
}
EpsPdnCnxInfo SmContext::getEpsPdnCnxInfo() const {
  return m_EpsPdnCnxInfo;
}
void SmContext::setEpsPdnCnxInfo(EpsPdnCnxInfo const& value) {
  m_EpsPdnCnxInfo      = value;
  m_EpsPdnCnxInfoIsSet = true;
}
bool SmContext::epsPdnCnxInfoIsSet() const {
  return m_EpsPdnCnxInfoIsSet;
}
void SmContext::unsetEpsPdnCnxInfo() {
  m_EpsPdnCnxInfoIsSet = false;
}
std::vector<EpsBearerInfo>& SmContext::getEpsBearerInfo() {
  return m_EpsBearerInfo;
}
bool SmContext::epsBearerInfoIsSet() const {
  return m_EpsBearerInfoIsSet;
}
void SmContext::unsetEpsBearerInfo() {
  m_EpsBearerInfoIsSet = false;
}
MaxIntegrityProtectedDataRate SmContext::getMaxIntegrityProtectedDataRate()
    const {
  return m_MaxIntegrityProtectedDataRate;
}
void SmContext::setMaxIntegrityProtectedDataRate(
    MaxIntegrityProtectedDataRate const& value) {
  m_MaxIntegrityProtectedDataRate      = value;
  m_MaxIntegrityProtectedDataRateIsSet = true;
}
bool SmContext::maxIntegrityProtectedDataRateIsSet() const {
  return m_MaxIntegrityProtectedDataRateIsSet;
}
void SmContext::unsetMaxIntegrityProtectedDataRate() {
  m_MaxIntegrityProtectedDataRateIsSet = false;
}
bool SmContext::isAlwaysOnGranted() const {
  return m_AlwaysOnGranted;
}
void SmContext::setAlwaysOnGranted(bool const value) {
  m_AlwaysOnGranted      = value;
  m_AlwaysOnGrantedIsSet = true;
}
bool SmContext::alwaysOnGrantedIsSet() const {
  return m_AlwaysOnGrantedIsSet;
}
void SmContext::unsetAlwaysOnGranted() {
  m_AlwaysOnGrantedIsSet = false;
}
UpSecurity SmContext::getUpSecurity() const {
  return m_UpSecurity;
}
void SmContext::setUpSecurity(UpSecurity const& value) {
  m_UpSecurity      = value;
  m_UpSecurityIsSet = true;
}
bool SmContext::upSecurityIsSet() const {
  return m_UpSecurityIsSet;
}
void SmContext::unsetUpSecurity() {
  m_UpSecurityIsSet = false;
}
std::string SmContext::getHSmfServiceInstanceId() const {
  return m_HSmfServiceInstanceId;
}
void SmContext::setHSmfServiceInstanceId(std::string const& value) {
  m_HSmfServiceInstanceId      = value;
  m_HSmfServiceInstanceIdIsSet = true;
}
bool SmContext::hSmfServiceInstanceIdIsSet() const {
  return m_HSmfServiceInstanceIdIsSet;
}
void SmContext::unsetHSmfServiceInstanceId() {
  m_HSmfServiceInstanceIdIsSet = false;
}
std::string SmContext::getRecoveryTime() const {
  return m_RecoveryTime;
}
void SmContext::setRecoveryTime(std::string const& value) {
  m_RecoveryTime      = value;
  m_RecoveryTimeIsSet = true;
}
bool SmContext::recoveryTimeIsSet() const {
  return m_RecoveryTimeIsSet;
}
void SmContext::unsetRecoveryTime() {
  m_RecoveryTimeIsSet = false;
}

}  // namespace model
}  // namespace smf_server
}  // namespace oai
