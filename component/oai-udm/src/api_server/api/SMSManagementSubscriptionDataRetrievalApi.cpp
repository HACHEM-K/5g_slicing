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

#include "SMSManagementSubscriptionDataRetrievalApi.h"

#include "Helpers.h"
#include "udm_sbi_helper.hpp"
#include "udm_config.hpp"

extern oai::udm::config::udm_config udm_cfg;

namespace oai {
namespace udm {
namespace api {

using namespace oai::model::common::helpers;
using namespace oai::model::common;
using namespace oai::udm::config;

SMSManagementSubscriptionDataRetrievalApi::
    SMSManagementSubscriptionDataRetrievalApi(
        std::shared_ptr<Pistache::Rest::Router> rtr) {
  router = rtr;
}

void SMSManagementSubscriptionDataRetrievalApi::init() {
  setupRoutes();
}

void SMSManagementSubscriptionDataRetrievalApi::setupRoutes() {
  using namespace Pistache::Rest;

  Routes::Get(
      *router,
      udm_sbi_helper::SubscriberDataManagementServiceBase +
          udm_sbi_helper::UdmSdmPathSupiSmsMngtData,
      Routes::bind(
          &SMSManagementSubscriptionDataRetrievalApi::get_sms_mngt_data_handler,
          this));

  // Default handler, called when a route is not found
  router->addCustomHandler(Routes::bind(
      &SMSManagementSubscriptionDataRetrievalApi::
          sms_management_subscription_data_retrieval_api_default_handler,
      this));
}

void SMSManagementSubscriptionDataRetrievalApi::get_sms_mngt_data_handler(
    const Pistache::Rest::Request& request,
    Pistache::Http::ResponseWriter response) {
  // Getting the path params
  auto supi = request.param(":supi").as<std::string>();

  // Getting the query params
  auto supportedFeaturesQuery = request.query().get("supported-features");
  Pistache::Optional<std::string> supportedFeatures;
  if (!supportedFeaturesQuery.isEmpty()) {
    std::string value;
    if (fromStringValue(supportedFeaturesQuery.get(), value)) {
      supportedFeatures = Pistache::Some(value);
    }
  }
  auto plmnIdQuery = request.query().get("plmn-id");
  Pistache::Optional<PlmnId> plmnId;
  /*   if(!plmnIdQuery.isEmpty()){
         PlmnId value;
         if(fromStringValue(plmnIdQuery.get(), value)){
             plmnId = Pistache::Some(value);
         }
     }
    */
  // Getting the header params
  auto ifNoneMatch     = request.headers().tryGetRaw("If-None-Match");
  auto ifModifiedSince = request.headers().tryGetRaw("If-Modified-Since");

  try {
    this->get_sms_mngt_data(
        supi, supportedFeatures, plmnId, ifNoneMatch, ifModifiedSince,
        response);
  } catch (nlohmann::detail::exception& e) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (std::exception& e) {
    // send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }
}

void SMSManagementSubscriptionDataRetrievalApi::
    sms_management_subscription_data_retrieval_api_default_handler(
        const Pistache::Rest::Request&,
        Pistache::Http::ResponseWriter response) {
  response.send(
      Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

}  // namespace api
}  // namespace udm
}  // namespace oai
