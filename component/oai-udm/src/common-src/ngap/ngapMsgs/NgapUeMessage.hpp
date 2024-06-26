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

#ifndef _NGAP_UE_MESSAGE_H_
#define _NGAP_UE_MESSAGE_H_

#include "AmfUeNgapId.hpp"
#include "NgapMessage.hpp"
#include "RanUeNgapId.hpp"

extern "C" {
#include "Ngap_ProtocolIE-Field.h"
}

namespace oai::ngap {

class NgapUeMessage : public NgapMessage {
 public:
  NgapUeMessage(NgapUeMessage const&) = delete;
  NgapUeMessage();
  virtual ~NgapUeMessage();

  virtual void setAmfUeNgapId(const unsigned long& id) = 0;
  unsigned long getAmfUeNgapId() const;

  virtual void setRanUeNgapId(const uint32_t& id) = 0;
  uint32_t getRanUeNgapId() const;

 protected:
  AmfUeNgapId m_AmfUeNgapId;
  RanUeNgapId m_RanUeNgapId;
};

}  // namespace oai::ngap
#endif
