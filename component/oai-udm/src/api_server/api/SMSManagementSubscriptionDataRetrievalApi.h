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
 * SMSManagementSubscriptionDataRetrievalApi.h
 *
 *
 */

#ifndef SMSManagementSubscriptionDataRetrievalApi_H_
#define SMSManagementSubscriptionDataRetrievalApi_H_

#include <pistache/http.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>
#include <pistache/router.h>

#include <string>

#include "PlmnId.h"
#include "ProblemDetails.h"
#include "SmsManagementSubscriptionData.h"

namespace oai {
namespace udm {
namespace api {

class SMSManagementSubscriptionDataRetrievalApi {
 public:
  SMSManagementSubscriptionDataRetrievalApi(
      std::shared_ptr<Pistache::Rest::Router>);
  virtual ~SMSManagementSubscriptionDataRetrievalApi() {}
  void init();

 private:
  void setupRoutes();

  void get_sms_mngt_data_handler(
      const Pistache::Rest::Request& request,
      Pistache::Http::ResponseWriter response);
  void sms_management_subscription_data_retrieval_api_default_handler(
      const Pistache::Rest::Request& request,
      Pistache::Http::ResponseWriter response);

  std::shared_ptr<Pistache::Rest::Router> router;

  /// <summary>
  /// retrieve a UE&#39;s SMS Management Subscription Data
  /// </summary>
  /// <remarks>
  ///
  /// </remarks>
  /// <param name="supi">Identifier of the UE</param>
  /// <param name="supportedFeatures">Supported Features (optional, default to
  /// &quot;&quot;)</param> <param name="plmnId"> (optional, default to
  /// PlmnId())</param> <param name="ifNoneMatch">Validator for conditional
  /// requests, as described in RFC 7232, 3.2 (optional, default to
  /// &quot;&quot;)</param> <param name="ifModifiedSince">Validator for
  /// conditional requests, as described in RFC 7232, 3.3 (optional, default to
  /// &quot;&quot;)</param>
  virtual void get_sms_mngt_data(
      const std::string& supi,
      const Pistache::Optional<std::string>& supportedFeatures,
      const Pistache::Optional<oai::model::common::PlmnId>& plmnId,
      const Pistache::Optional<Pistache::Http::Header::Raw>& ifNoneMatch,
      const Pistache::Optional<Pistache::Http::Header::Raw>& ifModifiedSince,
      Pistache::Http::ResponseWriter& response) = 0;
};

}  // namespace api
}  // namespace udm
}  // namespace oai

#endif /* SMSManagementSubscriptionDataRetrievalApi_H_ */