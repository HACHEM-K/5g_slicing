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

#ifndef _UPLINK_RAN_STATUS_TRANSFER_H_
#define _UPLINK_RAN_STATUS_TRANSFER_H_

#include "NgapUeMessage.hpp"
#include "RanStatusTransferTransparentContainer.hpp"

extern "C" {
#include "Ngap_UplinkRANStatusTransfer.h"
}

namespace oai::ngap {
class UplinkRanStatusTransfer : public NgapUeMessage {
 public:
  UplinkRanStatusTransfer();
  virtual ~UplinkRanStatusTransfer();

  void initialize();

  void setAmfUeNgapId(const uint64_t& id) override;
  void setRanUeNgapId(const uint32_t& id) override;
  bool decode(Ngap_NGAP_PDU_t* ngapMsgPdu) override;

  void getRanStatusTransferTransparentContainer(
      RanStatusTransferTransparentContainer& ranContainer) const;
  void setRanStatusTransferTransparentContainer(
      const RanStatusTransferTransparentContainer& ranContainer);

 private:
  Ngap_UplinkRANStatusTransfer_t* m_UplinkRanStatusTransferIes;
  // AMF_UE_NGAP_ID (Mandatory)
  // RAN_UE_NGAP_ID (Mandatory)
  RanStatusTransferTransparentContainer
      m_RanStatusTransferTransparentContainer;  // Mandatory
};
}  // namespace oai::ngap

#endif
