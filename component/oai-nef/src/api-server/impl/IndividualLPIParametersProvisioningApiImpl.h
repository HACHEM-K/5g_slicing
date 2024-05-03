/**
 * 3gpp-lpi-pp
 * API for Location Privacy Indication Parameters Provisioning. © 2021, 3GPP
 * Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights
 * reserved.
 *
 * The version of the OpenAPI document: 1.0.1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

/*
 * IndividualLPIParametersProvisioningApiImpl.h
 *
 *
 */

#ifndef INDIVIDUAL_LPI_PARAMETERS_PROVISIONING_API_IMPL_H_
#define INDIVIDUAL_LPI_PARAMETERS_PROVISIONING_API_IMPL_H_

#include <IndividualLPIParametersProvisioningApi.h>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include <memory>
#include <optional>
#include <string>

#include "LpiParametersProvision.h"
#include "ProblemDetails.h"

namespace oai::nef::api {

using namespace oai::nef::model;

class IndividualLPIParametersProvisioningApiImpl
    : public oai::nef::api::IndividualLPIParametersProvisioningApi {
 public:
  explicit IndividualLPIParametersProvisioningApiImpl(
      const std::shared_ptr<Pistache::Rest::Router>& rtr);
  ~IndividualLPIParametersProvisioningApiImpl() override = default;

  void af_id_provisioned_lpis_provisioned_lpi_id_delete(
      const std::string& afId, const std::string& provisionedLpiId,
      Pistache::Http::ResponseWriter& response);
  void af_id_provisioned_lpis_provisioned_lpi_id_get(
      const std::string& afId, const std::string& provisionedLpiId,
      Pistache::Http::ResponseWriter& response);
  void af_id_provisioned_lpis_provisioned_lpi_id_put(
      const std::string& afId, const std::string& provisionedLpiId,
      const LpiParametersProvision& lpiParametersProvision,
      Pistache::Http::ResponseWriter& response);
};

}  // namespace oai::nef::api

#endif