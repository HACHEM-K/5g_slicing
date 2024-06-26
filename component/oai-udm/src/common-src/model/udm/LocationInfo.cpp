/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the
 * License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */
/**
 * Nudm_UECM
 * Nudm Context Management Service. � 2020, 3GPP Organizational Partners (ARIB,
 * ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.2
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "LocationInfo.h"

namespace oai::model::udm {

LocationInfo::LocationInfo() {
  m_Supi                   = "";
  m_SupiIsSet              = false;
  m_Gpsi                   = "";
  m_GpsiIsSet              = false;
  m_SupportedFeatures      = "";
  m_SupportedFeaturesIsSet = false;
}

LocationInfo::~LocationInfo() {}

void LocationInfo::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const LocationInfo& o) {
  j = nlohmann::json();
  if (o.supiIsSet()) j["supi"] = o.m_Supi;
  if (o.gpsiIsSet()) j["gpsi"] = o.m_Gpsi;
  j["registrationLocationInfoList"] = o.m_RegistrationLocationInfoList;
  if (o.supportedFeaturesIsSet())
    j["supportedFeatures"] = o.m_SupportedFeatures;
}

void from_json(const nlohmann::json& j, LocationInfo& o) {
  if (j.find("supi") != j.end()) {
    j.at("supi").get_to(o.m_Supi);
    o.m_SupiIsSet = true;
  }
  if (j.find("gpsi") != j.end()) {
    j.at("gpsi").get_to(o.m_Gpsi);
    o.m_GpsiIsSet = true;
  }
  j.at("registrationLocationInfoList").get_to(o.m_RegistrationLocationInfoList);
  if (j.find("supportedFeatures") != j.end()) {
    j.at("supportedFeatures").get_to(o.m_SupportedFeatures);
    o.m_SupportedFeaturesIsSet = true;
  }
}

std::string LocationInfo::getSupi() const {
  return m_Supi;
}
void LocationInfo::setSupi(std::string const& value) {
  m_Supi      = value;
  m_SupiIsSet = true;
}
bool LocationInfo::supiIsSet() const {
  return m_SupiIsSet;
}
void LocationInfo::unsetSupi() {
  m_SupiIsSet = false;
}
std::string LocationInfo::getGpsi() const {
  return m_Gpsi;
}
void LocationInfo::setGpsi(std::string const& value) {
  m_Gpsi      = value;
  m_GpsiIsSet = true;
}
bool LocationInfo::gpsiIsSet() const {
  return m_GpsiIsSet;
}
void LocationInfo::unsetGpsi() {
  m_GpsiIsSet = false;
}
std::vector<RegistrationLocationInfo>&
LocationInfo::getRegistrationLocationInfoList() {
  return m_RegistrationLocationInfoList;
}
void LocationInfo::setRegistrationLocationInfoList(
    std::vector<RegistrationLocationInfo> const& value) {
  m_RegistrationLocationInfoList = value;
}
std::string LocationInfo::getSupportedFeatures() const {
  return m_SupportedFeatures;
}
void LocationInfo::setSupportedFeatures(std::string const& value) {
  m_SupportedFeatures      = value;
  m_SupportedFeaturesIsSet = true;
}
bool LocationInfo::supportedFeaturesIsSet() const {
  return m_SupportedFeaturesIsSet;
}
void LocationInfo::unsetSupportedFeatures() {
  m_SupportedFeaturesIsSet = false;
}

}  // namespace oai::model::udm
