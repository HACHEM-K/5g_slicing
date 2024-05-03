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
 * NonUEN2MessagesCollectionDocumentApi.h
 *
 *
 */

#ifndef NonUEN2MessagesCollectionDocumentApi_H_
#define NonUEN2MessagesCollectionDocumentApi_H_

#include <pistache/http.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>
#include <pistache/router.h>

#include "N2InformationTransferError.h"
#include "N2InformationTransferReqData.h"
#include "N2InformationTransferRspData.h"
#include "ProblemDetails.h"
#include "amf_sbi_helper.hpp"
#include "mime_parser.hpp"

namespace oai {
namespace amf {
namespace api {

using namespace oai::amf::model;

class NonUEN2MessagesCollectionDocumentApi {
 public:
  NonUEN2MessagesCollectionDocumentApi(std::shared_ptr<Pistache::Rest::Router>);
  virtual ~NonUEN2MessagesCollectionDocumentApi() {}
  void init();

  const std::string base = amf_sbi_helper::AmfCommunicationServiceBase;

 private:
  void setupRoutes();

  void non_ue_n2_message_transfer_handler(
      const Pistache::Rest::Request& request,
      Pistache::Http::ResponseWriter response);
  void non_uen2_messages_collection_document_api_default_handler(
      const Pistache::Rest::Request& request,
      Pistache::Http::ResponseWriter response);

  std::shared_ptr<Pistache::Rest::Router> router;

  /// <summary>
  /// Namf_Communication Non UE N2 Message Transfer service Operation
  /// </summary>
  /// <remarks>
  ///
  /// </remarks>
  /// <param name="n2InformationTransferReqData"></param>
  virtual void non_ue_n2_message_transfer(
      std::unordered_map<std::string, mime_part>& parts,
      Pistache::Http::ResponseWriter& response) = 0;
};

}  // namespace api
}  // namespace amf
}  // namespace oai

#endif /* NonUEN2MessagesCollectionDocumentApi_H_ */
