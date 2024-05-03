/**
 * 3gpp-analyticsexposure
 * API for Analytics Exposure. © 2021, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.0.3
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "AnalyticsEventNotif.h"

#include <sstream>

#include "Helpers.h"

namespace oai::nef::model {

AnalyticsEventNotif::AnalyticsEventNotif() {
  m_Expiry               = "";
  m_ExpiryIsSet          = false;
  m_TimeStamp            = "";
  m_UeMobilityInfosIsSet = false;
  m_UeCommInfosIsSet     = false;
  m_AbnormalInfosIsSet   = false;
  m_CongestInfosIsSet    = false;
  m_NwPerfInfosIsSet     = false;
  m_QosSustainInfosIsSet = false;
}

void AnalyticsEventNotif::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw oai::nef::helpers::ValidationException(msg.str());
  }
}

bool AnalyticsEventNotif::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool AnalyticsEventNotif::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "AnalyticsEventNotif" : pathPrefix;

  if (ueMobilityInfosIsSet()) {
    const std::vector<UeMobilityExposure>& value = m_UeMobilityInfos;
    const std::string currentValuePath = _pathPrefix + ".ueMobilityInfos";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const UeMobilityExposure& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success = value.validate(msg, currentValuePath + ".ueMobilityInfos") &&
                  success;

        i++;
      }
    }
  }

  if (ueCommInfosIsSet()) {
    const std::vector<UeCommunication>& value = m_UeCommInfos;
    const std::string currentValuePath        = _pathPrefix + ".ueCommInfos";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const UeCommunication& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".ueCommInfos") && success;

        i++;
      }
    }
  }

  if (abnormalInfosIsSet()) {
    const std::vector<AbnormalExposure>& value = m_AbnormalInfos;
    const std::string currentValuePath         = _pathPrefix + ".abnormalInfos";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const AbnormalExposure& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".abnormalInfos") && success;

        i++;
      }
    }
  }

  if (congestInfosIsSet()) {
    const std::vector<CongestInfo>& value = m_CongestInfos;
    const std::string currentValuePath    = _pathPrefix + ".congestInfos";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const CongestInfo& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".congestInfos") && success;

        i++;
      }
    }
  }

  if (nwPerfInfosIsSet()) {
    const std::vector<NetworkPerfExposure>& value = m_NwPerfInfos;
    const std::string currentValuePath = _pathPrefix + ".nwPerfInfos";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const NetworkPerfExposure& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".nwPerfInfos") && success;

        i++;
      }
    }
  }

  if (qosSustainInfosIsSet()) {
    const std::vector<QosSustainabilityExposure>& value = m_QosSustainInfos;
    const std::string currentValuePath = _pathPrefix + ".qosSustainInfos";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const QosSustainabilityExposure& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success = value.validate(msg, currentValuePath + ".qosSustainInfos") &&
                  success;

        i++;
      }
    }
  }

  return success;
}

bool AnalyticsEventNotif::operator==(const AnalyticsEventNotif& rhs) const {
  return

      (getAnalyEvent() == rhs.getAnalyEvent()) &&

      ((!expiryIsSet() && !rhs.expiryIsSet()) ||
       (expiryIsSet() && rhs.expiryIsSet() &&
        getExpiry() == rhs.getExpiry())) &&

      (getTimeStamp() == rhs.getTimeStamp()) &&

      ((!ueMobilityInfosIsSet() && !rhs.ueMobilityInfosIsSet()) ||
       (ueMobilityInfosIsSet() && rhs.ueMobilityInfosIsSet() &&
        getUeMobilityInfos() == rhs.getUeMobilityInfos())) &&

      ((!ueCommInfosIsSet() && !rhs.ueCommInfosIsSet()) ||
       (ueCommInfosIsSet() && rhs.ueCommInfosIsSet() &&
        getUeCommInfos() == rhs.getUeCommInfos())) &&

      ((!abnormalInfosIsSet() && !rhs.abnormalInfosIsSet()) ||
       (abnormalInfosIsSet() && rhs.abnormalInfosIsSet() &&
        getAbnormalInfos() == rhs.getAbnormalInfos())) &&

      ((!congestInfosIsSet() && !rhs.congestInfosIsSet()) ||
       (congestInfosIsSet() && rhs.congestInfosIsSet() &&
        getCongestInfos() == rhs.getCongestInfos())) &&

      ((!nwPerfInfosIsSet() && !rhs.nwPerfInfosIsSet()) ||
       (nwPerfInfosIsSet() && rhs.nwPerfInfosIsSet() &&
        getNwPerfInfos() == rhs.getNwPerfInfos())) &&

      ((!qosSustainInfosIsSet() && !rhs.qosSustainInfosIsSet()) ||
       (qosSustainInfosIsSet() && rhs.qosSustainInfosIsSet() &&
        getQosSustainInfos() == rhs.getQosSustainInfos()))

          ;
}

bool AnalyticsEventNotif::operator!=(const AnalyticsEventNotif& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const AnalyticsEventNotif& o) {
  j               = nlohmann::json();
  j["analyEvent"] = o.m_AnalyEvent;
  if (o.expiryIsSet()) j["expiry"] = o.m_Expiry;
  j["timeStamp"] = o.m_TimeStamp;
  if (o.ueMobilityInfosIsSet() || !o.m_UeMobilityInfos.empty())
    j["ueMobilityInfos"] = o.m_UeMobilityInfos;
  if (o.ueCommInfosIsSet() || !o.m_UeCommInfos.empty())
    j["ueCommInfos"] = o.m_UeCommInfos;
  if (o.abnormalInfosIsSet() || !o.m_AbnormalInfos.empty())
    j["abnormalInfos"] = o.m_AbnormalInfos;
  if (o.congestInfosIsSet() || !o.m_CongestInfos.empty())
    j["congestInfos"] = o.m_CongestInfos;
  if (o.nwPerfInfosIsSet() || !o.m_NwPerfInfos.empty())
    j["nwPerfInfos"] = o.m_NwPerfInfos;
  if (o.qosSustainInfosIsSet() || !o.m_QosSustainInfos.empty())
    j["qosSustainInfos"] = o.m_QosSustainInfos;
}

void from_json(const nlohmann::json& j, AnalyticsEventNotif& o) {
  j.at("analyEvent").get_to(o.m_AnalyEvent);
  if (j.find("expiry") != j.end()) {
    j.at("expiry").get_to(o.m_Expiry);
    o.m_ExpiryIsSet = true;
  }
  j.at("timeStamp").get_to(o.m_TimeStamp);
  if (j.find("ueMobilityInfos") != j.end()) {
    j.at("ueMobilityInfos").get_to(o.m_UeMobilityInfos);
    o.m_UeMobilityInfosIsSet = true;
  }
  if (j.find("ueCommInfos") != j.end()) {
    j.at("ueCommInfos").get_to(o.m_UeCommInfos);
    o.m_UeCommInfosIsSet = true;
  }
  if (j.find("abnormalInfos") != j.end()) {
    j.at("abnormalInfos").get_to(o.m_AbnormalInfos);
    o.m_AbnormalInfosIsSet = true;
  }
  if (j.find("congestInfos") != j.end()) {
    j.at("congestInfos").get_to(o.m_CongestInfos);
    o.m_CongestInfosIsSet = true;
  }
  if (j.find("nwPerfInfos") != j.end()) {
    j.at("nwPerfInfos").get_to(o.m_NwPerfInfos);
    o.m_NwPerfInfosIsSet = true;
  }
  if (j.find("qosSustainInfos") != j.end()) {
    j.at("qosSustainInfos").get_to(o.m_QosSustainInfos);
    o.m_QosSustainInfosIsSet = true;
  }
}

AnalyticsEvent AnalyticsEventNotif::getAnalyEvent() const {
  return m_AnalyEvent;
}
void AnalyticsEventNotif::setAnalyEvent(AnalyticsEvent const& value) {
  m_AnalyEvent = value;
}
std::string AnalyticsEventNotif::getExpiry() const {
  return m_Expiry;
}
void AnalyticsEventNotif::setExpiry(std::string const& value) {
  m_Expiry      = value;
  m_ExpiryIsSet = true;
}
bool AnalyticsEventNotif::expiryIsSet() const {
  return m_ExpiryIsSet;
}
void AnalyticsEventNotif::unsetExpiry() {
  m_ExpiryIsSet = false;
}
std::string AnalyticsEventNotif::getTimeStamp() const {
  return m_TimeStamp;
}
void AnalyticsEventNotif::setTimeStamp(std::string const& value) {
  m_TimeStamp = value;
}
std::vector<UeMobilityExposure> AnalyticsEventNotif::getUeMobilityInfos()
    const {
  return m_UeMobilityInfos;
}
void AnalyticsEventNotif::setUeMobilityInfos(
    std::vector<UeMobilityExposure> const& value) {
  m_UeMobilityInfos      = value;
  m_UeMobilityInfosIsSet = true;
}
bool AnalyticsEventNotif::ueMobilityInfosIsSet() const {
  return m_UeMobilityInfosIsSet;
}
void AnalyticsEventNotif::unsetUeMobilityInfos() {
  m_UeMobilityInfosIsSet = false;
}
std::vector<UeCommunication> AnalyticsEventNotif::getUeCommInfos() const {
  return m_UeCommInfos;
}
void AnalyticsEventNotif::setUeCommInfos(
    std::vector<UeCommunication> const& value) {
  m_UeCommInfos      = value;
  m_UeCommInfosIsSet = true;
}
bool AnalyticsEventNotif::ueCommInfosIsSet() const {
  return m_UeCommInfosIsSet;
}
void AnalyticsEventNotif::unsetUeCommInfos() {
  m_UeCommInfosIsSet = false;
}
std::vector<AbnormalExposure> AnalyticsEventNotif::getAbnormalInfos() const {
  return m_AbnormalInfos;
}
void AnalyticsEventNotif::setAbnormalInfos(
    std::vector<AbnormalExposure> const& value) {
  m_AbnormalInfos      = value;
  m_AbnormalInfosIsSet = true;
}
bool AnalyticsEventNotif::abnormalInfosIsSet() const {
  return m_AbnormalInfosIsSet;
}
void AnalyticsEventNotif::unsetAbnormalInfos() {
  m_AbnormalInfosIsSet = false;
}
std::vector<CongestInfo> AnalyticsEventNotif::getCongestInfos() const {
  return m_CongestInfos;
}
void AnalyticsEventNotif::setCongestInfos(
    std::vector<CongestInfo> const& value) {
  m_CongestInfos      = value;
  m_CongestInfosIsSet = true;
}
bool AnalyticsEventNotif::congestInfosIsSet() const {
  return m_CongestInfosIsSet;
}
void AnalyticsEventNotif::unsetCongestInfos() {
  m_CongestInfosIsSet = false;
}
std::vector<NetworkPerfExposure> AnalyticsEventNotif::getNwPerfInfos() const {
  return m_NwPerfInfos;
}
void AnalyticsEventNotif::setNwPerfInfos(
    std::vector<NetworkPerfExposure> const& value) {
  m_NwPerfInfos      = value;
  m_NwPerfInfosIsSet = true;
}
bool AnalyticsEventNotif::nwPerfInfosIsSet() const {
  return m_NwPerfInfosIsSet;
}
void AnalyticsEventNotif::unsetNwPerfInfos() {
  m_NwPerfInfosIsSet = false;
}
std::vector<QosSustainabilityExposure> AnalyticsEventNotif::getQosSustainInfos()
    const {
  return m_QosSustainInfos;
}
void AnalyticsEventNotif::setQosSustainInfos(
    std::vector<QosSustainabilityExposure> const& value) {
  m_QosSustainInfos      = value;
  m_QosSustainInfosIsSet = true;
}
bool AnalyticsEventNotif::qosSustainInfosIsSet() const {
  return m_QosSustainInfosIsSet;
}
void AnalyticsEventNotif::unsetQosSustainInfos() {
  m_QosSustainInfosIsSet = false;
}

}  // namespace oai::nef::model