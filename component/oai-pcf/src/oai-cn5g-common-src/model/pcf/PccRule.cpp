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

#include "PccRule.h"
#include "Helpers.h"

#include <sstream>

namespace oai::model::pcf {

PccRule::PccRule() {
  m_FlowInfosIsSet       = false;
  m_AppId                = "";
  m_AppIdIsSet           = false;
  m_AppDescriptorIsSet   = false;
  m_ContVer              = 0;
  m_ContVerIsSet         = false;
  m_PccRuleId            = "";
  m_Precedence           = 0;
  m_PrecedenceIsSet      = false;
  m_AfSigProtocolIsSet   = false;
  m_AppReloc             = false;
  m_AppRelocIsSet        = false;
  m_RefQosDataIsSet      = false;
  m_RefAltQosParamsIsSet = false;
  m_RefTcDataIsSet       = false;
  m_RefChgDataIsSet      = false;
  m_RefChgN3gDataIsSet   = false;
  m_RefUmDataIsSet       = false;
  m_RefUmN3gDataIsSet    = false;
  m_RefCondData          = "";
  m_RefCondDataIsSet     = false;
  m_RefQosMonIsSet       = false;
  m_AddrPreserInd        = false;
  m_AddrPreserIndIsSet   = false;
  m_TscaiInputDlIsSet    = false;
  m_TscaiInputUlIsSet    = false;
  m_DdNotifCtrlIsSet     = false;
  m_DdNotifCtrl2IsSet    = false;
  m_DisUeNotif           = false;
  m_DisUeNotifIsSet      = false;
}

void PccRule::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw oai::model::common::helpers::ValidationException(msg.str());
  }
}

bool PccRule::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PccRule::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "PccRule" : pathPrefix;

  if (flowInfosIsSet()) {
    const std::vector<oai::model::pcf::FlowInformation>& value = m_FlowInfos;
    const std::string currentValuePath = _pathPrefix + ".flowInfos";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const oai::model::pcf::FlowInformation& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".flowInfos") && success;

        i++;
      }
    }
  }

  if (precedenceIsSet()) {
    const int32_t& value               = m_Precedence;
    const std::string currentValuePath = _pathPrefix + ".precedence";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
  }

  if (refQosDataIsSet()) {
    const std::vector<std::string>& value = m_RefQosData;
    const std::string currentValuePath    = _pathPrefix + ".refQosData";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    if (value.size() > 1) {
      success = false;
      msg << currentValuePath << ": must have at most 1 elements;";
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

  if (refAltQosParamsIsSet()) {
    const std::vector<std::string>& value = m_RefAltQosParams;
    const std::string currentValuePath    = _pathPrefix + ".refAltQosParams";

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

  if (refTcDataIsSet()) {
    const std::vector<std::string>& value = m_RefTcData;
    const std::string currentValuePath    = _pathPrefix + ".refTcData";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    if (value.size() > 1) {
      success = false;
      msg << currentValuePath << ": must have at most 1 elements;";
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

  if (refChgDataIsSet()) {
    const std::vector<std::string>& value = m_RefChgData;
    const std::string currentValuePath    = _pathPrefix + ".refChgData";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    if (value.size() > 1) {
      success = false;
      msg << currentValuePath << ": must have at most 1 elements;";
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

  if (refChgN3gDataIsSet()) {
    const std::vector<std::string>& value = m_RefChgN3gData;
    const std::string currentValuePath    = _pathPrefix + ".refChgN3gData";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    if (value.size() > 1) {
      success = false;
      msg << currentValuePath << ": must have at most 1 elements;";
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

  if (refUmDataIsSet()) {
    const std::vector<std::string>& value = m_RefUmData;
    const std::string currentValuePath    = _pathPrefix + ".refUmData";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    if (value.size() > 1) {
      success = false;
      msg << currentValuePath << ": must have at most 1 elements;";
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

  if (refUmN3gDataIsSet()) {
    const std::vector<std::string>& value = m_RefUmN3gData;
    const std::string currentValuePath    = _pathPrefix + ".refUmN3gData";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    if (value.size() > 1) {
      success = false;
      msg << currentValuePath << ": must have at most 1 elements;";
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

  if (refQosMonIsSet()) {
    const std::vector<std::string>& value = m_RefQosMon;
    const std::string currentValuePath    = _pathPrefix + ".refQosMon";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    if (value.size() > 1) {
      success = false;
      msg << currentValuePath << ": must have at most 1 elements;";
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

bool PccRule::operator==(const PccRule& rhs) const {
  return

      ((!flowInfosIsSet() && !rhs.flowInfosIsSet()) ||
       (flowInfosIsSet() && rhs.flowInfosIsSet() &&
        getFlowInfos() == rhs.getFlowInfos())) &&

      ((!appIdIsSet() && !rhs.appIdIsSet()) ||
       (appIdIsSet() && rhs.appIdIsSet() && getAppId() == rhs.getAppId())) &&

      ((!appDescriptorIsSet() && !rhs.appDescriptorIsSet()) ||
       (appDescriptorIsSet() && rhs.appDescriptorIsSet() &&
        getAppDescriptor() == rhs.getAppDescriptor())) &&

      ((!contVerIsSet() && !rhs.contVerIsSet()) ||
       (contVerIsSet() && rhs.contVerIsSet() &&
        getContVer() == rhs.getContVer())) &&

      (getPccRuleId() == rhs.getPccRuleId()) &&

      ((!precedenceIsSet() && !rhs.precedenceIsSet()) ||
       (precedenceIsSet() && rhs.precedenceIsSet() &&
        getPrecedence() == rhs.getPrecedence())) &&

      ((!afSigProtocolIsSet() && !rhs.afSigProtocolIsSet()) ||
       (afSigProtocolIsSet() && rhs.afSigProtocolIsSet() &&
        getAfSigProtocol() == rhs.getAfSigProtocol())) &&

      ((!appRelocIsSet() && !rhs.appRelocIsSet()) ||
       (appRelocIsSet() && rhs.appRelocIsSet() &&
        isAppReloc() == rhs.isAppReloc())) &&

      ((!refQosDataIsSet() && !rhs.refQosDataIsSet()) ||
       (refQosDataIsSet() && rhs.refQosDataIsSet() &&
        getRefQosData() == rhs.getRefQosData())) &&

      ((!refAltQosParamsIsSet() && !rhs.refAltQosParamsIsSet()) ||
       (refAltQosParamsIsSet() && rhs.refAltQosParamsIsSet() &&
        getRefAltQosParams() == rhs.getRefAltQosParams())) &&

      ((!refTcDataIsSet() && !rhs.refTcDataIsSet()) ||
       (refTcDataIsSet() && rhs.refTcDataIsSet() &&
        getRefTcData() == rhs.getRefTcData())) &&

      ((!refChgDataIsSet() && !rhs.refChgDataIsSet()) ||
       (refChgDataIsSet() && rhs.refChgDataIsSet() &&
        getRefChgData() == rhs.getRefChgData())) &&

      ((!refChgN3gDataIsSet() && !rhs.refChgN3gDataIsSet()) ||
       (refChgN3gDataIsSet() && rhs.refChgN3gDataIsSet() &&
        getRefChgN3gData() == rhs.getRefChgN3gData())) &&

      ((!refUmDataIsSet() && !rhs.refUmDataIsSet()) ||
       (refUmDataIsSet() && rhs.refUmDataIsSet() &&
        getRefUmData() == rhs.getRefUmData())) &&

      ((!refUmN3gDataIsSet() && !rhs.refUmN3gDataIsSet()) ||
       (refUmN3gDataIsSet() && rhs.refUmN3gDataIsSet() &&
        getRefUmN3gData() == rhs.getRefUmN3gData())) &&

      ((!refCondDataIsSet() && !rhs.refCondDataIsSet()) ||
       (refCondDataIsSet() && rhs.refCondDataIsSet() &&
        getRefCondData() == rhs.getRefCondData())) &&

      ((!refQosMonIsSet() && !rhs.refQosMonIsSet()) ||
       (refQosMonIsSet() && rhs.refQosMonIsSet() &&
        getRefQosMon() == rhs.getRefQosMon())) &&

      ((!addrPreserIndIsSet() && !rhs.addrPreserIndIsSet()) ||
       (addrPreserIndIsSet() && rhs.addrPreserIndIsSet() &&
        isAddrPreserInd() == rhs.isAddrPreserInd())) &&

      ((!tscaiInputDlIsSet() && !rhs.tscaiInputDlIsSet()) ||
       (tscaiInputDlIsSet() && rhs.tscaiInputDlIsSet() &&
        getTscaiInputDl() == rhs.getTscaiInputDl())) &&

      ((!tscaiInputUlIsSet() && !rhs.tscaiInputUlIsSet()) ||
       (tscaiInputUlIsSet() && rhs.tscaiInputUlIsSet() &&
        getTscaiInputUl() == rhs.getTscaiInputUl())) &&

      ((!ddNotifCtrlIsSet() && !rhs.ddNotifCtrlIsSet()) ||
       (ddNotifCtrlIsSet() && rhs.ddNotifCtrlIsSet() &&
        getDdNotifCtrl() == rhs.getDdNotifCtrl())) &&

      ((!ddNotifCtrl2IsSet() && !rhs.ddNotifCtrl2IsSet()) ||
       (ddNotifCtrl2IsSet() && rhs.ddNotifCtrl2IsSet() &&
        getDdNotifCtrl2() == rhs.getDdNotifCtrl2())) &&

      ((!disUeNotifIsSet() && !rhs.disUeNotifIsSet()) ||
       (disUeNotifIsSet() && rhs.disUeNotifIsSet() &&
        isDisUeNotif() == rhs.isDisUeNotif()))

          ;
}

bool PccRule::operator!=(const PccRule& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PccRule& o) {
  j = nlohmann::json();
  if (o.flowInfosIsSet() || !o.m_FlowInfos.empty())
    j["flowInfos"] = o.m_FlowInfos;
  if (o.appIdIsSet()) j["appId"] = o.m_AppId;
  if (o.appDescriptorIsSet()) j["appDescriptor"] = o.m_AppDescriptor;
  if (o.contVerIsSet()) j["contVer"] = o.m_ContVer;
  j["pccRuleId"] = o.m_PccRuleId;
  if (o.precedenceIsSet()) j["precedence"] = o.m_Precedence;
  if (o.afSigProtocolIsSet()) j["afSigProtocol"] = o.m_AfSigProtocol;
  if (o.appRelocIsSet()) j["appReloc"] = o.m_AppReloc;
  if (o.refQosDataIsSet() || !o.m_RefQosData.empty())
    j["refQosData"] = o.m_RefQosData;
  if (o.refAltQosParamsIsSet() || !o.m_RefAltQosParams.empty())
    j["refAltQosParams"] = o.m_RefAltQosParams;
  if (o.refTcDataIsSet() || !o.m_RefTcData.empty())
    j["refTcData"] = o.m_RefTcData;
  if (o.refChgDataIsSet() || !o.m_RefChgData.empty())
    j["refChgData"] = o.m_RefChgData;
  if (o.refChgN3gDataIsSet() || !o.m_RefChgN3gData.empty())
    j["refChgN3gData"] = o.m_RefChgN3gData;
  if (o.refUmDataIsSet() || !o.m_RefUmData.empty())
    j["refUmData"] = o.m_RefUmData;
  if (o.refUmN3gDataIsSet() || !o.m_RefUmN3gData.empty())
    j["refUmN3gData"] = o.m_RefUmN3gData;
  if (o.refCondDataIsSet()) j["refCondData"] = o.m_RefCondData;
  if (o.refQosMonIsSet() || !o.m_RefQosMon.empty())
    j["refQosMon"] = o.m_RefQosMon;
  if (o.addrPreserIndIsSet()) j["addrPreserInd"] = o.m_AddrPreserInd;
  if (o.tscaiInputDlIsSet()) j["tscaiInputDl"] = o.m_TscaiInputDl;
  if (o.tscaiInputUlIsSet()) j["tscaiInputUl"] = o.m_TscaiInputUl;
  if (o.ddNotifCtrlIsSet()) j["ddNotifCtrl"] = o.m_DdNotifCtrl;
  if (o.ddNotifCtrl2IsSet()) j["ddNotifCtrl2"] = o.m_DdNotifCtrl2;
  if (o.disUeNotifIsSet()) j["disUeNotif"] = o.m_DisUeNotif;
}

void from_json(const nlohmann::json& j, PccRule& o) {
  if (j.find("flowInfos") != j.end()) {
    j.at("flowInfos").get_to(o.m_FlowInfos);
    o.m_FlowInfosIsSet = true;
  }
  if (j.find("appId") != j.end()) {
    j.at("appId").get_to(o.m_AppId);
    o.m_AppIdIsSet = true;
  }
  if (j.find("appDescriptor") != j.end()) {
    j.at("appDescriptor").get_to(o.m_AppDescriptor);
    o.m_AppDescriptorIsSet = true;
  }
  if (j.find("contVer") != j.end()) {
    j.at("contVer").get_to(o.m_ContVer);
    o.m_ContVerIsSet = true;
  }
  if (j.find("pccRuleId") != j.end()) {
    j.at("pccRuleId").get_to(o.m_PccRuleId);
  }
  if (j.find("precedence") != j.end()) {
    j.at("precedence").get_to(o.m_Precedence);
    o.m_PrecedenceIsSet = true;
  }
  if (j.find("afSigProtocol") != j.end()) {
    j.at("afSigProtocol").get_to(o.m_AfSigProtocol);
    o.m_AfSigProtocolIsSet = true;
  }
  if (j.find("appReloc") != j.end()) {
    j.at("appReloc").get_to(o.m_AppReloc);
    o.m_AppRelocIsSet = true;
  }
  if (j.find("refQosData") != j.end()) {
    j.at("refQosData").get_to(o.m_RefQosData);
    o.m_RefQosDataIsSet = true;
  }
  if (j.find("refAltQosParams") != j.end()) {
    j.at("refAltQosParams").get_to(o.m_RefAltQosParams);
    o.m_RefAltQosParamsIsSet = true;
  }
  if (j.find("refTcData") != j.end()) {
    j.at("refTcData").get_to(o.m_RefTcData);
    o.m_RefTcDataIsSet = true;
  }
  if (j.find("refChgData") != j.end()) {
    j.at("refChgData").get_to(o.m_RefChgData);
    o.m_RefChgDataIsSet = true;
  }
  if (j.find("refChgN3gData") != j.end()) {
    j.at("refChgN3gData").get_to(o.m_RefChgN3gData);
    o.m_RefChgN3gDataIsSet = true;
  }
  if (j.find("refUmData") != j.end()) {
    j.at("refUmData").get_to(o.m_RefUmData);
    o.m_RefUmDataIsSet = true;
  }
  if (j.find("refUmN3gData") != j.end()) {
    j.at("refUmN3gData").get_to(o.m_RefUmN3gData);
    o.m_RefUmN3gDataIsSet = true;
  }
  if (j.find("refCondData") != j.end()) {
    j.at("refCondData").get_to(o.m_RefCondData);
    o.m_RefCondDataIsSet = true;
  }
  if (j.find("refQosMon") != j.end()) {
    j.at("refQosMon").get_to(o.m_RefQosMon);
    o.m_RefQosMonIsSet = true;
  }
  if (j.find("addrPreserInd") != j.end()) {
    j.at("addrPreserInd").get_to(o.m_AddrPreserInd);
    o.m_AddrPreserIndIsSet = true;
  }
  if (j.find("tscaiInputDl") != j.end()) {
    j.at("tscaiInputDl").get_to(o.m_TscaiInputDl);
    o.m_TscaiInputDlIsSet = true;
  }
  if (j.find("tscaiInputUl") != j.end()) {
    j.at("tscaiInputUl").get_to(o.m_TscaiInputUl);
    o.m_TscaiInputUlIsSet = true;
  }
  if (j.find("ddNotifCtrl") != j.end()) {
    j.at("ddNotifCtrl").get_to(o.m_DdNotifCtrl);
    o.m_DdNotifCtrlIsSet = true;
  }
  if (j.find("ddNotifCtrl2") != j.end()) {
    j.at("ddNotifCtrl2").get_to(o.m_DdNotifCtrl2);
    o.m_DdNotifCtrl2IsSet = true;
  }
  if (j.find("disUeNotif") != j.end()) {
    j.at("disUeNotif").get_to(o.m_DisUeNotif);
    o.m_DisUeNotifIsSet = true;
  }
}

std::vector<oai::model::pcf::FlowInformation> PccRule::getFlowInfos() const {
  return m_FlowInfos;
}
void PccRule::setFlowInfos(
    std::vector<oai::model::pcf::FlowInformation> const& value) {
  m_FlowInfos      = value;
  m_FlowInfosIsSet = true;
}
bool PccRule::flowInfosIsSet() const {
  return m_FlowInfosIsSet;
}
void PccRule::unsetFlowInfos() {
  m_FlowInfosIsSet = false;
}
std::string PccRule::getAppId() const {
  return m_AppId;
}
void PccRule::setAppId(std::string const& value) {
  m_AppId      = value;
  m_AppIdIsSet = true;
}
bool PccRule::appIdIsSet() const {
  return m_AppIdIsSet;
}
void PccRule::unsetAppId() {
  m_AppIdIsSet = false;
}
std::string PccRule::getAppDescriptor() const {
  return m_AppDescriptor;
}
void PccRule::setAppDescriptor(std::string const& value) {
  m_AppDescriptor      = value;
  m_AppDescriptorIsSet = true;
}
bool PccRule::appDescriptorIsSet() const {
  return m_AppDescriptorIsSet;
}
void PccRule::unsetAppDescriptor() {
  m_AppDescriptorIsSet = false;
}
int32_t PccRule::getContVer() const {
  return m_ContVer;
}
void PccRule::setContVer(int32_t const value) {
  m_ContVer      = value;
  m_ContVerIsSet = true;
}
bool PccRule::contVerIsSet() const {
  return m_ContVerIsSet;
}
void PccRule::unsetContVer() {
  m_ContVerIsSet = false;
}
std::string PccRule::getPccRuleId() const {
  return m_PccRuleId;
}
void PccRule::setPccRuleId(std::string const& value) {
  m_PccRuleId = value;
}
int32_t PccRule::getPrecedence() const {
  return m_Precedence;
}
void PccRule::setPrecedence(int32_t const value) {
  m_Precedence      = value;
  m_PrecedenceIsSet = true;
}
bool PccRule::precedenceIsSet() const {
  return m_PrecedenceIsSet;
}
void PccRule::unsetPrecedence() {
  m_PrecedenceIsSet = false;
}
oai::model::pcf::AfSigProtocol PccRule::getAfSigProtocol() const {
  return m_AfSigProtocol;
}
void PccRule::setAfSigProtocol(oai::model::pcf::AfSigProtocol const& value) {
  m_AfSigProtocol      = value;
  m_AfSigProtocolIsSet = true;
}
bool PccRule::afSigProtocolIsSet() const {
  return m_AfSigProtocolIsSet;
}
void PccRule::unsetAfSigProtocol() {
  m_AfSigProtocolIsSet = false;
}
bool PccRule::isAppReloc() const {
  return m_AppReloc;
}
void PccRule::setAppReloc(bool const value) {
  m_AppReloc      = value;
  m_AppRelocIsSet = true;
}
bool PccRule::appRelocIsSet() const {
  return m_AppRelocIsSet;
}
void PccRule::unsetAppReloc() {
  m_AppRelocIsSet = false;
}
std::vector<std::string> PccRule::getRefQosData() const {
  return m_RefQosData;
}
void PccRule::setRefQosData(std::vector<std::string> const& value) {
  m_RefQosData      = value;
  m_RefQosDataIsSet = true;
}
bool PccRule::refQosDataIsSet() const {
  return m_RefQosDataIsSet;
}
void PccRule::unsetRefQosData() {
  m_RefQosDataIsSet = false;
}
std::vector<std::string> PccRule::getRefAltQosParams() const {
  return m_RefAltQosParams;
}
void PccRule::setRefAltQosParams(std::vector<std::string> const& value) {
  m_RefAltQosParams      = value;
  m_RefAltQosParamsIsSet = true;
}
bool PccRule::refAltQosParamsIsSet() const {
  return m_RefAltQosParamsIsSet;
}
void PccRule::unsetRefAltQosParams() {
  m_RefAltQosParamsIsSet = false;
}
std::vector<std::string> PccRule::getRefTcData() const {
  return m_RefTcData;
}
void PccRule::setRefTcData(std::vector<std::string> const& value) {
  m_RefTcData      = value;
  m_RefTcDataIsSet = true;
}
bool PccRule::refTcDataIsSet() const {
  return m_RefTcDataIsSet;
}
void PccRule::unsetRefTcData() {
  m_RefTcDataIsSet = false;
}
std::vector<std::string> PccRule::getRefChgData() const {
  return m_RefChgData;
}
void PccRule::setRefChgData(std::vector<std::string> const& value) {
  m_RefChgData      = value;
  m_RefChgDataIsSet = true;
}
bool PccRule::refChgDataIsSet() const {
  return m_RefChgDataIsSet;
}
void PccRule::unsetRefChgData() {
  m_RefChgDataIsSet = false;
}
std::vector<std::string> PccRule::getRefChgN3gData() const {
  return m_RefChgN3gData;
}
void PccRule::setRefChgN3gData(std::vector<std::string> const& value) {
  m_RefChgN3gData      = value;
  m_RefChgN3gDataIsSet = true;
}
bool PccRule::refChgN3gDataIsSet() const {
  return m_RefChgN3gDataIsSet;
}
void PccRule::unsetRefChgN3gData() {
  m_RefChgN3gDataIsSet = false;
}
std::vector<std::string> PccRule::getRefUmData() const {
  return m_RefUmData;
}
void PccRule::setRefUmData(std::vector<std::string> const& value) {
  m_RefUmData      = value;
  m_RefUmDataIsSet = true;
}
bool PccRule::refUmDataIsSet() const {
  return m_RefUmDataIsSet;
}
void PccRule::unsetRefUmData() {
  m_RefUmDataIsSet = false;
}
std::vector<std::string> PccRule::getRefUmN3gData() const {
  return m_RefUmN3gData;
}
void PccRule::setRefUmN3gData(std::vector<std::string> const& value) {
  m_RefUmN3gData      = value;
  m_RefUmN3gDataIsSet = true;
}
bool PccRule::refUmN3gDataIsSet() const {
  return m_RefUmN3gDataIsSet;
}
void PccRule::unsetRefUmN3gData() {
  m_RefUmN3gDataIsSet = false;
}
std::string PccRule::getRefCondData() const {
  return m_RefCondData;
}
void PccRule::setRefCondData(std::string const& value) {
  m_RefCondData      = value;
  m_RefCondDataIsSet = true;
}
bool PccRule::refCondDataIsSet() const {
  return m_RefCondDataIsSet;
}
void PccRule::unsetRefCondData() {
  m_RefCondDataIsSet = false;
}
std::vector<std::string> PccRule::getRefQosMon() const {
  return m_RefQosMon;
}
void PccRule::setRefQosMon(std::vector<std::string> const& value) {
  m_RefQosMon      = value;
  m_RefQosMonIsSet = true;
}
bool PccRule::refQosMonIsSet() const {
  return m_RefQosMonIsSet;
}
void PccRule::unsetRefQosMon() {
  m_RefQosMonIsSet = false;
}
bool PccRule::isAddrPreserInd() const {
  return m_AddrPreserInd;
}
void PccRule::setAddrPreserInd(bool const value) {
  m_AddrPreserInd      = value;
  m_AddrPreserIndIsSet = true;
}
bool PccRule::addrPreserIndIsSet() const {
  return m_AddrPreserIndIsSet;
}
void PccRule::unsetAddrPreserInd() {
  m_AddrPreserIndIsSet = false;
}
oai::model::pcf::TscaiInputContainer PccRule::getTscaiInputDl() const {
  return m_TscaiInputDl;
}
void PccRule::setTscaiInputDl(
    oai::model::pcf::TscaiInputContainer const& value) {
  m_TscaiInputDl      = value;
  m_TscaiInputDlIsSet = true;
}
bool PccRule::tscaiInputDlIsSet() const {
  return m_TscaiInputDlIsSet;
}
void PccRule::unsetTscaiInputDl() {
  m_TscaiInputDlIsSet = false;
}
oai::model::pcf::TscaiInputContainer PccRule::getTscaiInputUl() const {
  return m_TscaiInputUl;
}
void PccRule::setTscaiInputUl(
    oai::model::pcf::TscaiInputContainer const& value) {
  m_TscaiInputUl      = value;
  m_TscaiInputUlIsSet = true;
}
bool PccRule::tscaiInputUlIsSet() const {
  return m_TscaiInputUlIsSet;
}
void PccRule::unsetTscaiInputUl() {
  m_TscaiInputUlIsSet = false;
}
oai::model::pcf::DownlinkDataNotificationControl PccRule::getDdNotifCtrl()
    const {
  return m_DdNotifCtrl;
}
void PccRule::setDdNotifCtrl(
    oai::model::pcf::DownlinkDataNotificationControl const& value) {
  m_DdNotifCtrl      = value;
  m_DdNotifCtrlIsSet = true;
}
bool PccRule::ddNotifCtrlIsSet() const {
  return m_DdNotifCtrlIsSet;
}
void PccRule::unsetDdNotifCtrl() {
  m_DdNotifCtrlIsSet = false;
}
oai::model::pcf::DownlinkDataNotificationControlRm PccRule::getDdNotifCtrl2()
    const {
  return m_DdNotifCtrl2;
}
void PccRule::setDdNotifCtrl2(
    oai::model::pcf::DownlinkDataNotificationControlRm const& value) {
  m_DdNotifCtrl2      = value;
  m_DdNotifCtrl2IsSet = true;
}
bool PccRule::ddNotifCtrl2IsSet() const {
  return m_DdNotifCtrl2IsSet;
}
void PccRule::unsetDdNotifCtrl2() {
  m_DdNotifCtrl2IsSet = false;
}
bool PccRule::isDisUeNotif() const {
  return m_DisUeNotif;
}
void PccRule::setDisUeNotif(bool const value) {
  m_DisUeNotif      = value;
  m_DisUeNotifIsSet = true;
}
bool PccRule::disUeNotifIsSet() const {
  return m_DisUeNotifIsSet;
}
void PccRule::unsetDisUeNotif() {
  m_DisUeNotifIsSet = false;
}

std::string PccRule::getFirstFlowDescription() const {
  std::string flow = "";
  if (flowInfosIsSet() && getFlowInfos().size() > 0) {
    if (getFlowInfos()[0].flowDescriptionIsSet()) {
      flow = getFlowInfos()[0].getFlowDescription();
    }
  }
  return flow;
}

}  // namespace oai::model::pcf