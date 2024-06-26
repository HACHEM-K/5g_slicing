/**
 * NSSF NSSAI Availability
 * NSSF NSSAI Availability Service. © 2021, 3GPP Organizational Partners (ARIB,
 * ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.4
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

/*
 * SubscriptionIDDocumentApiImpl.h
 *
 *
 */

#ifndef SUBSCRIPTION_ID_DOCUMENT_API_IMPL_H_
#define SUBSCRIPTION_ID_DOCUMENT_API_IMPL_H_

#include <memory>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include <SubscriptionIDDocumentApi.h>

#include <pistache/optional.h>

#include "NssfEventSubscriptionCreatedData.h"
#include "PatchItem.h"
#include "ProblemDetails.h"
#include "RedirectResponse.h"
#include "nssf_app.hpp"

#include <string>
#include <vector>

namespace oai {
namespace nssf_server {
namespace api {

class SubscriptionIDDocumentApiImpl
    : public oai::nssf_server::api::SubscriptionIDDocumentApi {
 public:
  SubscriptionIDDocumentApiImpl(
      std::shared_ptr<Pistache::Rest::Router>, nssf::nssf_app* nssf_app_inst,
      std::string address);
  ~SubscriptionIDDocumentApiImpl() {}

  void n_ssai_availability_sub_modify_patch(
      const std::string& subscriptionId,
      const std::vector<oai::model::common::PatchItem>& patchItem,
      const Pistache::Optional<Pistache::Http::Header::Raw>& contentEncoding,
      Pistache::Http::ResponseWriter& response);
  void n_ssai_availability_unsubscribe(
      const std::string& subscriptionId,
      Pistache::Http::ResponseWriter& response);

 private:
  nssf::nssf_app* m_nssf_app;
  std::string m_address;
};

}  // namespace api
}  // namespace nssf_server
}  // namespace oai

#endif
