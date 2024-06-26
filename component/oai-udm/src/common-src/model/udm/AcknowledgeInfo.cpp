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
 * Nudm_SDM
 * Nudm Subscriber Data Management Service. � 2019, 3GPP Organizational Partners
 * (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 2.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "AcknowledgeInfo.h"

namespace oai::model::udm {

AcknowledgeInfo::AcknowledgeInfo() {
  m_SorMacIue          = "";
  m_SorMacIueIsSet     = false;
  m_UpuMacIue          = "";
  m_UpuMacIueIsSet     = false;
  m_SecuredPacket      = "";
  m_SecuredPacketIsSet = false;
  m_ProvisioningTime   = "";
}

AcknowledgeInfo::~AcknowledgeInfo() {}

void AcknowledgeInfo::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const AcknowledgeInfo& o) {
  j = nlohmann::json();
  if (o.sorMacIueIsSet()) j["sorMacIue"] = o.m_SorMacIue;
  if (o.upuMacIueIsSet()) j["upuMacIue"] = o.m_UpuMacIue;
  if (o.securedPacketIsSet()) j["securedPacket"] = o.m_SecuredPacket;
  j["provisioningTime"] = o.m_ProvisioningTime;
}

void from_json(const nlohmann::json& j, AcknowledgeInfo& o) {
  if (j.find("sorMacIue") != j.end()) {
    j.at("sorMacIue").get_to(o.m_SorMacIue);
    o.m_SorMacIueIsSet = true;
  }
  if (j.find("upuMacIue") != j.end()) {
    j.at("upuMacIue").get_to(o.m_UpuMacIue);
    o.m_UpuMacIueIsSet = true;
  }
  if (j.find("securedPacket") != j.end()) {
    j.at("securedPacket").get_to(o.m_SecuredPacket);
    o.m_SecuredPacketIsSet = true;
  }
  j.at("provisioningTime").get_to(o.m_ProvisioningTime);
}

std::string AcknowledgeInfo::getSorMacIue() const {
  return m_SorMacIue;
}
void AcknowledgeInfo::setSorMacIue(std::string const& value) {
  m_SorMacIue      = value;
  m_SorMacIueIsSet = true;
}
bool AcknowledgeInfo::sorMacIueIsSet() const {
  return m_SorMacIueIsSet;
}
void AcknowledgeInfo::unsetSorMacIue() {
  m_SorMacIueIsSet = false;
}
std::string AcknowledgeInfo::getUpuMacIue() const {
  return m_UpuMacIue;
}
void AcknowledgeInfo::setUpuMacIue(std::string const& value) {
  m_UpuMacIue      = value;
  m_UpuMacIueIsSet = true;
}
bool AcknowledgeInfo::upuMacIueIsSet() const {
  return m_UpuMacIueIsSet;
}
void AcknowledgeInfo::unsetUpuMacIue() {
  m_UpuMacIueIsSet = false;
}
std::string AcknowledgeInfo::getSecuredPacket() const {
  return m_SecuredPacket;
}
void AcknowledgeInfo::setSecuredPacket(std::string const& value) {
  m_SecuredPacket      = value;
  m_SecuredPacketIsSet = true;
}
bool AcknowledgeInfo::securedPacketIsSet() const {
  return m_SecuredPacketIsSet;
}
void AcknowledgeInfo::unsetSecuredPacket() {
  m_SecuredPacketIsSet = false;
}
std::string AcknowledgeInfo::getProvisioningTime() const {
  return m_ProvisioningTime;
}
void AcknowledgeInfo::setProvisioningTime(std::string const& value) {
  m_ProvisioningTime = value;
}

}  // namespace oai::model::udm
