/**
 * NSSF NSSAI Availability
 * NSSF NSSAI Availability Service. © 2021, 3GPP Organizational Partners (ARIB,
 * ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.4
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "NssfEventSubscriptionCreatedData.h"
#include "Helpers.h"

#include <sstream>

namespace oai {
namespace nssf_server {
namespace model {

NssfEventSubscriptionCreatedData::NssfEventSubscriptionCreatedData() {
  m_SubscriptionId                       = "";
  m_Expiry                               = "";
  m_ExpiryIsSet                          = false;
  m_AuthorizedNssaiAvailabilityDataIsSet = false;
  m_SupportedFeatures                    = "";
  m_SupportedFeaturesIsSet               = false;
}

void NssfEventSubscriptionCreatedData::validate() const {
  std::stringstream msg;
  // if (!validate(msg))
  // {
  //     throw oai::nssf_server::helpers::ValidationException(msg.str());
  // }
}

bool NssfEventSubscriptionCreatedData::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool NssfEventSubscriptionCreatedData::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "NssfEventSubscriptionCreatedData" : pathPrefix;

  if (authorizedNssaiAvailabilityDataIsSet()) {
    const std::vector<AuthorizedNssaiAvailabilityData>& value =
        m_AuthorizedNssaiAvailabilityData;
    const std::string currentValuePath =
        _pathPrefix + ".authorizedNssaiAvailabilityData";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const AuthorizedNssaiAvailabilityData& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(
                msg, currentValuePath + ".authorizedNssaiAvailabilityData") &&
            success;

        i++;
      }
    }
  }

  if (supportedFeaturesIsSet()) {
    const std::string& value           = m_SupportedFeatures;
    const std::string currentValuePath = _pathPrefix + ".supportedFeatures";
  }

  return success;
}

bool NssfEventSubscriptionCreatedData::operator==(
    const NssfEventSubscriptionCreatedData& rhs) const {
  return

      (getSubscriptionId() == rhs.getSubscriptionId()) &&

      ((!expiryIsSet() && !rhs.expiryIsSet()) ||
       (expiryIsSet() && rhs.expiryIsSet() &&
        getExpiry() == rhs.getExpiry())) &&

      ((!authorizedNssaiAvailabilityDataIsSet() &&
        !rhs.authorizedNssaiAvailabilityDataIsSet()) ||
       (authorizedNssaiAvailabilityDataIsSet() &&
        rhs.authorizedNssaiAvailabilityDataIsSet() &&
        getAuthorizedNssaiAvailabilityData() ==
            rhs.getAuthorizedNssaiAvailabilityData())) &&

      ((!supportedFeaturesIsSet() && !rhs.supportedFeaturesIsSet()) ||
       (supportedFeaturesIsSet() && rhs.supportedFeaturesIsSet() &&
        getSupportedFeatures() == rhs.getSupportedFeatures()))

          ;
}

bool NssfEventSubscriptionCreatedData::operator!=(
    const NssfEventSubscriptionCreatedData& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const NssfEventSubscriptionCreatedData& o) {
  j                   = nlohmann::json();
  j["subscriptionId"] = o.m_SubscriptionId;
  if (o.expiryIsSet()) j["expiry"] = o.m_Expiry;
  if (o.authorizedNssaiAvailabilityDataIsSet() ||
      !o.m_AuthorizedNssaiAvailabilityData.empty())
    j["authorizedNssaiAvailabilityData"] = o.m_AuthorizedNssaiAvailabilityData;
  if (o.supportedFeaturesIsSet())
    j["supportedFeatures"] = o.m_SupportedFeatures;
}

void from_json(const nlohmann::json& j, NssfEventSubscriptionCreatedData& o) {
  j.at("subscriptionId").get_to(o.m_SubscriptionId);
  if (j.find("expiry") != j.end()) {
    j.at("expiry").get_to(o.m_Expiry);
    o.m_ExpiryIsSet = true;
  }
  if (j.find("authorizedNssaiAvailabilityData") != j.end()) {
    j.at("authorizedNssaiAvailabilityData")
        .get_to(o.m_AuthorizedNssaiAvailabilityData);
    o.m_AuthorizedNssaiAvailabilityDataIsSet = true;
  }
  if (j.find("supportedFeatures") != j.end()) {
    j.at("supportedFeatures").get_to(o.m_SupportedFeatures);
    o.m_SupportedFeaturesIsSet = true;
  }
}

std::string NssfEventSubscriptionCreatedData::getSubscriptionId() const {
  return m_SubscriptionId;
}
void NssfEventSubscriptionCreatedData::setSubscriptionId(
    std::string const& value) {
  m_SubscriptionId = value;
}
std::string NssfEventSubscriptionCreatedData::getExpiry() const {
  return m_Expiry;
}
void NssfEventSubscriptionCreatedData::setExpiry(std::string const& value) {
  m_Expiry      = value;
  m_ExpiryIsSet = true;
}
bool NssfEventSubscriptionCreatedData::expiryIsSet() const {
  return m_ExpiryIsSet;
}
void NssfEventSubscriptionCreatedData::unsetExpiry() {
  m_ExpiryIsSet = false;
}
std::vector<AuthorizedNssaiAvailabilityData>
NssfEventSubscriptionCreatedData::getAuthorizedNssaiAvailabilityData() const {
  return m_AuthorizedNssaiAvailabilityData;
}
void NssfEventSubscriptionCreatedData::setAuthorizedNssaiAvailabilityData(
    std::vector<AuthorizedNssaiAvailabilityData> const& value) {
  m_AuthorizedNssaiAvailabilityData      = value;
  m_AuthorizedNssaiAvailabilityDataIsSet = true;
}
bool NssfEventSubscriptionCreatedData::authorizedNssaiAvailabilityDataIsSet()
    const {
  return m_AuthorizedNssaiAvailabilityDataIsSet;
}
void NssfEventSubscriptionCreatedData::unsetAuthorizedNssaiAvailabilityData() {
  m_AuthorizedNssaiAvailabilityDataIsSet = false;
}
std::string NssfEventSubscriptionCreatedData::getSupportedFeatures() const {
  return m_SupportedFeatures;
}
void NssfEventSubscriptionCreatedData::setSupportedFeatures(
    std::string const& value) {
  m_SupportedFeatures      = value;
  m_SupportedFeaturesIsSet = true;
}
bool NssfEventSubscriptionCreatedData::supportedFeaturesIsSet() const {
  return m_SupportedFeaturesIsSet;
}
void NssfEventSubscriptionCreatedData::unsetSupportedFeatures() {
  m_SupportedFeaturesIsSet = false;
}

}  // namespace model
}  // namespace nssf_server
}  // namespace oai