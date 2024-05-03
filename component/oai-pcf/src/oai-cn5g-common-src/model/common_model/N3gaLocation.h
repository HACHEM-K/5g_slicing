/**
 * Common Data Types
 * Common Data Types for Service Based Interfaces. © 2022, 3GPP Organizational
 * Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.2.7
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * N3gaLocation.h
 *
 *
 */

#ifndef N3gaLocation_H_
#define N3gaLocation_H_

#include "Tai.h"
#include "TransportProtocol.h"
#include <string>
#include "TnapId.h"
#include "Ipv6Addr.h"
#include "TwapId.h"
#include "LineType.h"
#include "HfcNodeId.h"
#include <nlohmann/json.hpp>

namespace oai::model::common {

/// <summary>
///
/// </summary>
class N3gaLocation {
 public:
  N3gaLocation();
  virtual ~N3gaLocation() = default;

  /// <summary>
  /// Validate the current data in the model. Throws a ValidationException on
  /// failure.
  /// </summary>
  void validate() const;

  /// <summary>
  /// Validate the current data in the model. Returns false on error and writes
  /// an error message into the given stringstream.
  /// </summary>
  bool validate(std::stringstream& msg) const;

  /// <summary>
  /// Helper overload for validate. Used when one model stores another model and
  /// calls it's validate. Not meant to be called outside that case.
  /// </summary>
  bool validate(std::stringstream& msg, const std::string& pathPrefix) const;

  bool operator==(const N3gaLocation& rhs) const;
  bool operator!=(const N3gaLocation& rhs) const;

  /////////////////////////////////////////////
  /// N3gaLocation members

  /// <summary>
  ///
  /// </summary>
  oai::model::common::Tai getN3gppTai() const;
  void setN3gppTai(oai::model::common::Tai const& value);
  bool n3gppTaiIsSet() const;
  void unsetN3gppTai();
  /// <summary>
  ///
  /// </summary>
  std::string getN3IwfId() const;
  void setN3IwfId(std::string const& value);
  bool n3IwfIdIsSet() const;
  void unsetN3IwfId();
  /// <summary>
  ///
  /// </summary>
  std::string getUeIpv4Addr() const;
  void setUeIpv4Addr(std::string const& value);
  bool ueIpv4AddrIsSet() const;
  void unsetUeIpv4Addr();
  /// <summary>
  ///
  /// </summary>
  oai::model::common::Ipv6Addr getUeIpv6Addr() const;
  void setUeIpv6Addr(oai::model::common::Ipv6Addr const& value);
  bool ueIpv6AddrIsSet() const;
  void unsetUeIpv6Addr();
  /// <summary>
  ///
  /// </summary>
  int32_t getPortNumber() const;
  void setPortNumber(int32_t const value);
  bool portNumberIsSet() const;
  void unsetPortNumber();
  /// <summary>
  ///
  /// </summary>
  oai::model::common::TnapId getTnapId() const;
  void setTnapId(oai::model::common::TnapId const& value);
  bool tnapIdIsSet() const;
  void unsetTnapId();
  /// <summary>
  ///
  /// </summary>
  oai::model::common::TransportProtocol getProtocol() const;
  void setProtocol(oai::model::common::TransportProtocol const& value);
  bool protocolIsSet() const;
  void unsetProtocol();
  /// <summary>
  ///
  /// </summary>
  oai::model::common::TwapId getTwapId() const;
  void setTwapId(oai::model::common::TwapId const& value);
  bool twapIdIsSet() const;
  void unsetTwapId();
  /// <summary>
  ///
  /// </summary>
  oai::model::common::HfcNodeId getHfcNodeId() const;
  void setHfcNodeId(oai::model::common::HfcNodeId const& value);
  bool hfcNodeIdIsSet() const;
  void unsetHfcNodeId();
  /// <summary>
  ///
  /// </summary>
  std::string getGli() const;
  void setGli(std::string const& value);
  bool gliIsSet() const;
  void unsetGli();
  /// <summary>
  ///
  /// </summary>
  oai::model::common::LineType getW5gbanLineType() const;
  void setW5gbanLineType(oai::model::common::LineType const& value);
  bool w5gbanLineTypeIsSet() const;
  void unsetW5gbanLineType();
  /// <summary>
  ///
  /// </summary>
  std::string getGci() const;
  void setGci(std::string const& value);
  bool gciIsSet() const;
  void unsetGci();

  friend void to_json(nlohmann::json& j, const N3gaLocation& o);
  friend void from_json(const nlohmann::json& j, N3gaLocation& o);

 protected:
  oai::model::common::Tai m_N3gppTai;
  bool m_N3gppTaiIsSet;
  std::string m_N3IwfId;
  bool m_N3IwfIdIsSet;
  std::string m_UeIpv4Addr;
  bool m_UeIpv4AddrIsSet;
  oai::model::common::Ipv6Addr m_UeIpv6Addr;
  bool m_UeIpv6AddrIsSet;
  int32_t m_PortNumber;
  bool m_PortNumberIsSet;
  oai::model::common::TnapId m_TnapId;
  bool m_TnapIdIsSet;
  oai::model::common::TransportProtocol m_Protocol;
  bool m_ProtocolIsSet;
  oai::model::common::TwapId m_TwapId;
  bool m_TwapIdIsSet;
  oai::model::common::HfcNodeId m_HfcNodeId;
  bool m_HfcNodeIdIsSet;
  std::string m_Gli;
  bool m_GliIsSet;
  oai::model::common::LineType m_W5gbanLineType;
  bool m_W5gbanLineTypeIsSet;
  std::string m_Gci;
  bool m_GciIsSet;
};

}  // namespace oai::model::common

#endif /* N3gaLocation_H_ */
