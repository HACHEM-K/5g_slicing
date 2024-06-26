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
/*
 * IdTranslationResult.h
 *
 *
 */

#ifndef IdTranslationResult_H_
#define IdTranslationResult_H_

#include <nlohmann/json.hpp>
#include <string>

namespace oai::model::udm {

/// <summary>
///
/// </summary>
class IdTranslationResult {
 public:
  IdTranslationResult();
  virtual ~IdTranslationResult();

  void validate();

  /////////////////////////////////////////////
  /// IdTranslationResult members

  /// <summary>
  ///
  /// </summary>
  std::string getSupportedFeatures() const;
  void setSupportedFeatures(std::string const& value);
  bool supportedFeaturesIsSet() const;
  void unsetSupportedFeatures();
  /// <summary>
  ///
  /// </summary>
  std::string getSupi() const;
  void setSupi(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getGpsi() const;
  void setGpsi(std::string const& value);
  bool gpsiIsSet() const;
  void unsetGpsi();

  friend void to_json(nlohmann::json& j, const IdTranslationResult& o);
  friend void from_json(const nlohmann::json& j, IdTranslationResult& o);

 protected:
  std::string m_SupportedFeatures;
  bool m_SupportedFeaturesIsSet;
  std::string m_Supi;

  std::string m_Gpsi;
  bool m_GpsiIsSet;
};

}  // namespace oai::model::udm

#endif /* IdTranslationResult_H_ */
