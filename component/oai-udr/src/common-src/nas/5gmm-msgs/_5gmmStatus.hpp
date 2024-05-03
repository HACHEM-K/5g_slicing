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

#ifndef __5GMM_STATUS_H_
#define __5GMM_STATUS_H_

#include "NasIeHeader.hpp"

namespace oai::nas {

class _5gmmStatus : public NasMmPlainHeader {
 public:
  _5gmmStatus();
  ~_5gmmStatus();

  int Encode(uint8_t* buf, int len);
  int Decode(uint8_t* buf, int len);

  void SetHeader(uint8_t security_header_type);

  void Set5gmmCause(uint8_t value);
  uint8_t Get5gmmCause() const;

 private:
  _5gmmCause ie_5gmm_cause_;  // Mandatory
};

}  // namespace oai::nas

#endif
