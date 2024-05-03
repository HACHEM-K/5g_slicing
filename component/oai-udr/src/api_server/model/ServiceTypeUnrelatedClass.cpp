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
 * Nudr_DataRepository API OpenAPI file
 * Unified Data Repository Service. © 2020, 3GPP Organizational Partners (ARIB,
 * ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 2.1.2
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "ServiceTypeUnrelatedClass.h"

namespace oai::udr::model {

ServiceTypeUnrelatedClass::ServiceTypeUnrelatedClass() {
  m_ServiceType                    = 0;
  m_AllowedGeographicAreaIsSet     = false;
  m_PrivacyCheckRelatedActionIsSet = false;
  m_CodeWordIndIsSet               = false;
  m_ValidTimePeriodIsSet           = false;
  m_CodeWordListIsSet              = false;
}

ServiceTypeUnrelatedClass::~ServiceTypeUnrelatedClass() {}

void ServiceTypeUnrelatedClass::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const ServiceTypeUnrelatedClass& o) {
  j                = nlohmann::json();
  j["serviceType"] = o.m_ServiceType;
  if (o.allowedGeographicAreaIsSet() || !o.m_AllowedGeographicArea.empty())
    j["allowedGeographicArea"] = o.m_AllowedGeographicArea;
  if (o.privacyCheckRelatedActionIsSet())
    j["privacyCheckRelatedAction"] = o.m_PrivacyCheckRelatedAction;
  if (o.codeWordIndIsSet()) j["codeWordInd"] = o.m_CodeWordInd;
  if (o.validTimePeriodIsSet()) j["validTimePeriod"] = o.m_ValidTimePeriod;
  if (o.codeWordListIsSet() || !o.m_CodeWordList.empty())
    j["codeWordList"] = o.m_CodeWordList;
}

void from_json(const nlohmann::json& j, ServiceTypeUnrelatedClass& o) {
  j.at("serviceType").get_to(o.m_ServiceType);
  if (j.find("allowedGeographicArea") != j.end()) {
    j.at("allowedGeographicArea").get_to(o.m_AllowedGeographicArea);
    o.m_AllowedGeographicAreaIsSet = true;
  }
  if (j.find("privacyCheckRelatedAction") != j.end()) {
    j.at("privacyCheckRelatedAction").get_to(o.m_PrivacyCheckRelatedAction);
    o.m_PrivacyCheckRelatedActionIsSet = true;
  }
  if (j.find("codeWordInd") != j.end()) {
    j.at("codeWordInd").get_to(o.m_CodeWordInd);
    o.m_CodeWordIndIsSet = true;
  }
  if (j.find("validTimePeriod") != j.end()) {
    j.at("validTimePeriod").get_to(o.m_ValidTimePeriod);
    o.m_ValidTimePeriodIsSet = true;
  }
  if (j.find("codeWordList") != j.end()) {
    j.at("codeWordList").get_to(o.m_CodeWordList);
    o.m_CodeWordListIsSet = true;
  }
}

int32_t ServiceTypeUnrelatedClass::getServiceType() const {
  return m_ServiceType;
}
void ServiceTypeUnrelatedClass::setServiceType(int32_t const value) {
  m_ServiceType = value;
}
std::vector<GeographicArea>&
ServiceTypeUnrelatedClass::getAllowedGeographicArea() {
  return m_AllowedGeographicArea;
}
void ServiceTypeUnrelatedClass::setAllowedGeographicArea(
    std::vector<GeographicArea> const& value) {
  m_AllowedGeographicArea      = value;
  m_AllowedGeographicAreaIsSet = true;
}
bool ServiceTypeUnrelatedClass::allowedGeographicAreaIsSet() const {
  return m_AllowedGeographicAreaIsSet;
}
void ServiceTypeUnrelatedClass::unsetAllowedGeographicArea() {
  m_AllowedGeographicAreaIsSet = false;
}
PrivacyCheckRelatedAction
ServiceTypeUnrelatedClass::getPrivacyCheckRelatedAction() const {
  return m_PrivacyCheckRelatedAction;
}
void ServiceTypeUnrelatedClass::setPrivacyCheckRelatedAction(
    PrivacyCheckRelatedAction const& value) {
  m_PrivacyCheckRelatedAction      = value;
  m_PrivacyCheckRelatedActionIsSet = true;
}
bool ServiceTypeUnrelatedClass::privacyCheckRelatedActionIsSet() const {
  return m_PrivacyCheckRelatedActionIsSet;
}
void ServiceTypeUnrelatedClass::unsetPrivacyCheckRelatedAction() {
  m_PrivacyCheckRelatedActionIsSet = false;
}
CodeWordInd ServiceTypeUnrelatedClass::getCodeWordInd() const {
  return m_CodeWordInd;
}
void ServiceTypeUnrelatedClass::setCodeWordInd(CodeWordInd const& value) {
  m_CodeWordInd      = value;
  m_CodeWordIndIsSet = true;
}
bool ServiceTypeUnrelatedClass::codeWordIndIsSet() const {
  return m_CodeWordIndIsSet;
}
void ServiceTypeUnrelatedClass::unsetCodeWordInd() {
  m_CodeWordIndIsSet = false;
}
ValidTimePeriod ServiceTypeUnrelatedClass::getValidTimePeriod() const {
  return m_ValidTimePeriod;
}
void ServiceTypeUnrelatedClass::setValidTimePeriod(
    ValidTimePeriod const& value) {
  m_ValidTimePeriod      = value;
  m_ValidTimePeriodIsSet = true;
}
bool ServiceTypeUnrelatedClass::validTimePeriodIsSet() const {
  return m_ValidTimePeriodIsSet;
}
void ServiceTypeUnrelatedClass::unsetValidTimePeriod() {
  m_ValidTimePeriodIsSet = false;
}
std::vector<std::string>& ServiceTypeUnrelatedClass::getCodeWordList() {
  return m_CodeWordList;
}
void ServiceTypeUnrelatedClass::setCodeWordList(
    std::vector<std::string> const& value) {
  m_CodeWordList      = value;
  m_CodeWordListIsSet = true;
}
bool ServiceTypeUnrelatedClass::codeWordListIsSet() const {
  return m_CodeWordListIsSet;
}
void ServiceTypeUnrelatedClass::unsetCodeWordList() {
  m_CodeWordListIsSet = false;
}

}  // namespace oai::udr::model
