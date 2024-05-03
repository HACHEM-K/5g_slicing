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

#include "AccessAndMobilityDataApi.h"

#include "Helpers.h"
#include "udr_config.hpp"

extern oai::udr::config::udr_config udr_cfg;

namespace oai::udr::api {

using namespace oai::model::common::helpers;
using namespace oai::udr::model;

AccessAndMobilityDataApi::AccessAndMobilityDataApi(
    std::shared_ptr<Pistache::Rest::Router> rtr) {
  router = rtr;
}

void AccessAndMobilityDataApi::init() {
  setupRoutes();
}

void AccessAndMobilityDataApi::setupRoutes() {
  using namespace Pistache::Rest;

  Routes::Put(
      *router,
      base + udr_cfg.nudr.api_version +
          "/exposure-data/:ueId/access-and-mobility-data",
      Routes::bind(
          &AccessAndMobilityDataApi::
              create_or_replace_access_and_mobility_data_handler,
          this));
  Routes::Delete(
      *router,
      base + udr_cfg.nudr.api_version +
          "/exposure-data/:ueId/access-and-mobility-data",
      Routes::bind(
          &AccessAndMobilityDataApi::delete_access_and_mobility_data_handler,
          this));
  Routes::Get(
      *router,
      base + udr_cfg.nudr.api_version +
          "/exposure-data/:ueId/access-and-mobility-data",
      Routes::bind(
          &AccessAndMobilityDataApi::query_access_and_mobility_data_handler,
          this));
  Routes::Patch(
      *router,
      base + udr_cfg.nudr.api_version +
          "/exposure-data/:ueId/access-and-mobility-data",
      Routes::bind(
          &AccessAndMobilityDataApi::update_access_and_mobility_data_handler,
          this));

  // Default handler, called when a route is not found
  router->addCustomHandler(Routes::bind(
      &AccessAndMobilityDataApi::access_and_mobility_data_api_default_handler,
      this));
}

void AccessAndMobilityDataApi::
    create_or_replace_access_and_mobility_data_handler(
        const Pistache::Rest::Request& request,
        Pistache::Http::ResponseWriter response) {
  if (!request.hasParam(":ueId")) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request);
    return;
  }

  // Getting the path params
  auto ueId = request.param(":ueId").as<std::string>();

  // Getting the body param

  AccessAndMobilityData accessAndMobilityData;

  try {
    nlohmann::json::parse(request.body()).get_to(accessAndMobilityData);
    this->create_or_replace_access_and_mobility_data(
        ueId, accessAndMobilityData, response);
  } catch (nlohmann::detail::exception& e) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (Pistache::Http::HttpError& e) {
    response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
    return;
  } catch (std::exception& e) {
    // send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }
}
void AccessAndMobilityDataApi::delete_access_and_mobility_data_handler(
    const Pistache::Rest::Request& request,
    Pistache::Http::ResponseWriter response) {
  if (!request.hasParam(":ueId")) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request);
    return;
  }
  // Getting the path params
  auto ueId = request.param(":ueId").as<std::string>();

  try {
    this->delete_access_and_mobility_data(ueId, response);
  } catch (nlohmann::detail::exception& e) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (Pistache::Http::HttpError& e) {
    response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
    return;
  } catch (std::exception& e) {
    // send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }
}
void AccessAndMobilityDataApi::query_access_and_mobility_data_handler(
    const Pistache::Rest::Request& request,
    Pistache::Http::ResponseWriter response) {
  if (!request.hasParam(":ueId")) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request);
    return;
  }
  // Getting the path params
  auto ueId = request.param(":ueId").as<std::string>();

  // Getting the query params
  auto suppFeatQuery = request.query().get("supp-feat");
  Pistache::Optional<std::string> suppFeat;
  if (!suppFeatQuery.isEmpty()) {
    std::string valueQuery_instance;
    if (fromStringValue(suppFeatQuery.get(), valueQuery_instance)) {
      suppFeat = Pistache::Some(valueQuery_instance);
    }
  }

  try {
    this->query_access_and_mobility_data(ueId, suppFeat, response);
  } catch (nlohmann::detail::exception& e) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (Pistache::Http::HttpError& e) {
    response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
    return;
  } catch (std::exception& e) {
    // send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }
}
void AccessAndMobilityDataApi::update_access_and_mobility_data_handler(
    const Pistache::Rest::Request& request,
    Pistache::Http::ResponseWriter response) {
  if (!request.hasParam(":ueId")) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request);
    return;
  }
  // Getting the path params
  auto ueId = request.param(":ueId").as<std::string>();

  // Getting the body param

  AccessAndMobilityData accessAndMobilityData;

  try {
    nlohmann::json::parse(request.body()).get_to(accessAndMobilityData);
    this->update_access_and_mobility_data(
        ueId, accessAndMobilityData, response);
  } catch (nlohmann::detail::exception& e) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (Pistache::Http::HttpError& e) {
    response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
    return;
  } catch (std::exception& e) {
    // send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }
}

void AccessAndMobilityDataApi::access_and_mobility_data_api_default_handler(
    const Pistache::Rest::Request&, Pistache::Http::ResponseWriter response) {
  response.send(
      Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

}  // namespace oai::udr::api
