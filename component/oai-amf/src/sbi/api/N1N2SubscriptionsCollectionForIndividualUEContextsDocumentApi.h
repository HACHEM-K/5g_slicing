/**
 * Namf_Communication
 * AMF Communication Service © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * N1N2SubscriptionsCollectionForIndividualUEContextsDocumentApi.h
 *
 *
 */

#ifndef N1N2SubscriptionsCollectionForIndividualUEContextsDocumentApi_H_
#define N1N2SubscriptionsCollectionForIndividualUEContextsDocumentApi_H_

#include <pistache/http.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>
#include <pistache/router.h>

#include "ProblemDetails.h"
#include "UeN1N2InfoSubscriptionCreateData.h"
#include "UeN1N2InfoSubscriptionCreatedData.h"
#include "amf.hpp"
#include "amf_sbi_helper.hpp"

namespace oai {
namespace amf {
namespace api {

using namespace oai::amf::model;

class N1N2SubscriptionsCollectionForIndividualUEContextsDocumentApi {
 public:
  N1N2SubscriptionsCollectionForIndividualUEContextsDocumentApi(
      std::shared_ptr<Pistache::Rest::Router>);
  virtual ~N1N2SubscriptionsCollectionForIndividualUEContextsDocumentApi() {}
  void init();

  const std::string base = amf_sbi_helper::AmfCommunicationServiceBase;

 private:
  void setupRoutes();

  void n1_n2_message_subscribe_handler(
      const Pistache::Rest::Request& request,
      Pistache::Http::ResponseWriter response);
  void
  n1_n2_subscriptions_collection_for_individual_ue_contexts_document_api_default_handler(
      const Pistache::Rest::Request& request,
      Pistache::Http::ResponseWriter response);

  std::shared_ptr<Pistache::Rest::Router> router;

  /// <summary>
  /// Namf_Communication N1N2 Message Subscribe (UE Specific) service Operation
  /// </summary>
  /// <remarks>
  ///
  /// </remarks>
  /// <param name="ueContextId">UE Context Identifier</param>
  /// <param name="ueN1N2InfoSubscriptionCreateData"></param>
  virtual void n1_n2_message_subscribe(
      const std::string& ueContextId,
      const UeN1N2InfoSubscriptionCreateData& ueN1N2InfoSubscriptionCreateData,
      Pistache::Http::ResponseWriter& response) = 0;
};

}  // namespace api
}  // namespace amf
}  // namespace oai

#endif /* N1N2SubscriptionsCollectionForIndividualUEContextsDocumentApi_H_ */
