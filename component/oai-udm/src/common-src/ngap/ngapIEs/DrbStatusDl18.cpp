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

#include "DrbStatusDl18.hpp"

namespace oai::ngap {

//------------------------------------------------------------------------------
DrbStatusDl18::DrbStatusDl18() {}

//------------------------------------------------------------------------------
DrbStatusDl18::~DrbStatusDl18() {}

//------------------------------------------------------------------------------
void DrbStatusDl18::get(CountValueForPdcpSn18& value) const {
  value = m_DlCountValue;
}

//------------------------------------------------------------------------------
void DrbStatusDl18::set(const CountValueForPdcpSn18& value) {
  m_DlCountValue = value;
}

//------------------------------------------------------------------------------
bool DrbStatusDl18::encode(Ngap_DRBStatusDL18_t& dl18) const {
  if (!m_DlCountValue.encode(dl18.dL_COUNTValue)) {
    Logger::ngap().error("Encode DRBStatusDL18 IE error");
    return false;
  }
  return true;
}

//------------------------------------------------------------------------------
bool DrbStatusDl18::decode(const Ngap_DRBStatusDL18_t& dl18) {
  if (!m_DlCountValue.decode(dl18.dL_COUNTValue)) {
    Logger::ngap().error("Decode DRBStatusDL18 IE error");
    return false;
  }
  return true;
}
}  // namespace oai::ngap
