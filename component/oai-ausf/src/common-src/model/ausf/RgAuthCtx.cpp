/**
 * AUSF API
 * AUSF UE Authentication Service. © 2020, 3GPP Organizational Partners (ARIB,
 * ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this
 *file except in compliance with the License. You may obtain a copy of the
 *License at
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

#include "RgAuthCtx.h"

namespace oai::model::ausf {

RgAuthCtx::RgAuthCtx() {
  m_Supi         = "";
  m_SupiIsSet    = false;
  m_AuthInd      = false;
  m_AuthIndIsSet = false;
}

RgAuthCtx::~RgAuthCtx() {}

void RgAuthCtx::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const RgAuthCtx& o) {
  j               = nlohmann::json();
  j["authResult"] = o.m_AuthResult;
  if (o.supiIsSet()) j["supi"] = o.m_Supi;
  if (o.authIndIsSet()) j["authInd"] = o.m_AuthInd;
}

void from_json(const nlohmann::json& j, RgAuthCtx& o) {
  j.at("authResult").get_to(o.m_AuthResult);
  if (j.find("supi") != j.end()) {
    j.at("supi").get_to(o.m_Supi);
    o.m_SupiIsSet = true;
  }
  if (j.find("authInd") != j.end()) {
    j.at("authInd").get_to(o.m_AuthInd);
    o.m_AuthIndIsSet = true;
  }
}

AuthResult RgAuthCtx::getAuthResult() const {
  return m_AuthResult;
}
void RgAuthCtx::setAuthResult(AuthResult const& value) {
  m_AuthResult = value;
}
std::string RgAuthCtx::getSupi() const {
  return m_Supi;
}
void RgAuthCtx::setSupi(std::string const& value) {
  m_Supi      = value;
  m_SupiIsSet = true;
}
bool RgAuthCtx::supiIsSet() const {
  return m_SupiIsSet;
}
void RgAuthCtx::unsetSupi() {
  m_SupiIsSet = false;
}
bool RgAuthCtx::isAuthInd() const {
  return m_AuthInd;
}
void RgAuthCtx::setAuthInd(bool const value) {
  m_AuthInd      = value;
  m_AuthIndIsSet = true;
}
bool RgAuthCtx::authIndIsSet() const {
  return m_AuthIndIsSet;
}
void RgAuthCtx::unsetAuthInd() {
  m_AuthIndIsSet = false;
}

}  // namespace oai::model::ausf
