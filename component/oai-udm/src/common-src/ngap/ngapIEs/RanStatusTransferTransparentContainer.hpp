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

#ifndef _RAN_STATUS_TRANSFER_TRANSPARENT_CONTAINER_H_
#define _RAN_STATUS_TRANSFER_TRANSPARENT_CONTAINER_H_

#include "DrbsSubjectToStatusTransferList.hpp"

extern "C" {
#include "Ngap_RANStatusTransfer-TransparentContainer.h"
}

namespace oai::ngap {

class RanStatusTransferTransparentContainer {
 public:
  RanStatusTransferTransparentContainer();
  virtual ~RanStatusTransferTransparentContainer();

  void getDrbSubjectList(DrbSubjectToStatusTransferList& drblist) const;
  void setDrbSubjectList(const DrbSubjectToStatusTransferList& drblist);

  bool encode(
      Ngap_RANStatusTransfer_TransparentContainer_t& ranStatusTransfer) const;
  bool decode(
      const Ngap_RANStatusTransfer_TransparentContainer_t& ranStatusTransfer);

 private:
  DrbSubjectToStatusTransferList m_DrbList;  // Mandatory
};

}  // namespace oai::ngap
#endif
