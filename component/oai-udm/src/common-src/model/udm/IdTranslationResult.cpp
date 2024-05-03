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

#include "IdTranslationResult.h"

namespace oai::model::udm {

IdTranslationResult::IdTranslationResult() {
  m_SupportedFeatures      = "";
  m_SupportedFeaturesIsSet = false;
  m_Supi                   = "";
  m_Gpsi                   = "";
  m_GpsiIsSet              = false;
}

IdTranslationResult::~IdTranslationResult() {}

void IdTranslationResult::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const IdTranslationResult& o) {
  j = nlohmann::json();
  if (o.supportedFeaturesIsSet())
    j["supportedFeatures"] = o.m_SupportedFeatures;
  j["supi"] = o.m_Supi;
  if (o.gpsiIsSet()) j["gpsi"] = o.m_Gpsi;
}

void from_json(const nlohmann::json& j, IdTranslationResult& o) {
  if (j.find("supportedFeatures") != j.end()) {
    j.at("supportedFeatures").get_to(o.m_SupportedFeatures);
    o.m_SupportedFeaturesIsSet = true;
  }
  j.at("supi").get_to(o.m_Supi);
  if (j.find("gpsi") != j.end()) {
    j.at("gpsi").get_to(o.m_Gpsi);
    o.m_GpsiIsSet = true;
  }
}

std::string IdTranslationResult::getSupportedFeatures() const {
  return m_SupportedFeatures;
}
void IdTranslationResult::setSupportedFeatures(std::string const& value) {
  m_SupportedFeatures      = value;
  m_SupportedFeaturesIsSet = true;
}
bool IdTranslationResult::supportedFeaturesIsSet() const {
  return m_SupportedFeaturesIsSet;
}
void IdTranslationResult::unsetSupportedFeatures() {
  m_SupportedFeaturesIsSet = false;
}
std::string IdTranslationResult::getSupi() const {
  return m_Supi;
}
void IdTranslationResult::setSupi(std::string const& value) {
  m_Supi = value;
}
std::string IdTranslationResult::getGpsi() const {
  return m_Gpsi;
}
void IdTranslationResult::setGpsi(std::string const& value) {
  m_Gpsi      = value;
  m_GpsiIsSet = true;
}
bool IdTranslationResult::gpsiIsSet() const {
  return m_GpsiIsSet;
}
void IdTranslationResult::unsetGpsi() {
  m_GpsiIsSet = false;
}

}  // namespace oai::model::udm