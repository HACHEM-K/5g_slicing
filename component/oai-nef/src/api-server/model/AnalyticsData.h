/**
 * 3gpp-analyticsexposure
 * API for Analytics Exposure. © 2021, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.0.3
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * AnalyticsData.h
 *
 *
 */

#ifndef AnalyticsData_H_
#define AnalyticsData_H_

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "AbnormalExposure.h"
#include "CongestInfo.h"
#include "NetworkPerfExposure.h"
#include "QosSustainabilityExposure.h"
#include "UeCommunication.h"
#include "UeMobilityExposure.h"

namespace oai::nef::model {

/// <summary>
///
/// </summary>
class AnalyticsData {
 public:
  AnalyticsData();
  virtual ~AnalyticsData() = default;

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

  bool operator==(const AnalyticsData& rhs) const;
  bool operator!=(const AnalyticsData& rhs) const;

  /////////////////////////////////////////////
  /// AnalyticsData members

  /// <summary>
  ///
  /// </summary>
  std::string getExpiry() const;
  void setExpiry(std::string const& value);
  bool expiryIsSet() const;
  void unsetExpiry();
  /// <summary>
  ///
  /// </summary>
  std::vector<UeMobilityExposure> getUeMobilityInfos() const;
  void setUeMobilityInfos(std::vector<UeMobilityExposure> const& value);
  bool ueMobilityInfosIsSet() const;
  void unsetUeMobilityInfos();
  /// <summary>
  ///
  /// </summary>
  std::vector<UeCommunication> getUeCommInfos() const;
  void setUeCommInfos(std::vector<UeCommunication> const& value);
  bool ueCommInfosIsSet() const;
  void unsetUeCommInfos();
  /// <summary>
  ///
  /// </summary>
  std::vector<NetworkPerfExposure> getNwPerfInfos() const;
  void setNwPerfInfos(std::vector<NetworkPerfExposure> const& value);
  bool nwPerfInfosIsSet() const;
  void unsetNwPerfInfos();
  /// <summary>
  ///
  /// </summary>
  std::vector<AbnormalExposure> getAbnormalInfos() const;
  void setAbnormalInfos(std::vector<AbnormalExposure> const& value);
  bool abnormalInfosIsSet() const;
  void unsetAbnormalInfos();
  /// <summary>
  ///
  /// </summary>
  std::vector<CongestInfo> getCongestInfos() const;
  void setCongestInfos(std::vector<CongestInfo> const& value);
  bool congestInfosIsSet() const;
  void unsetCongestInfos();
  /// <summary>
  ///
  /// </summary>
  std::vector<QosSustainabilityExposure> getQosSustainInfos() const;
  void setQosSustainInfos(std::vector<QosSustainabilityExposure> const& value);
  bool qosSustainInfosIsSet() const;
  void unsetQosSustainInfos();
  /// <summary>
  ///
  /// </summary>
  std::string getSuppFeat() const;
  void setSuppFeat(std::string const& value);

  friend void to_json(nlohmann::json& j, const AnalyticsData& o);
  friend void from_json(const nlohmann::json& j, AnalyticsData& o);

 protected:
  std::string m_Expiry;
  bool m_ExpiryIsSet;
  std::vector<UeMobilityExposure> m_UeMobilityInfos;
  bool m_UeMobilityInfosIsSet;
  std::vector<UeCommunication> m_UeCommInfos;
  bool m_UeCommInfosIsSet;
  std::vector<NetworkPerfExposure> m_NwPerfInfos;
  bool m_NwPerfInfosIsSet;
  std::vector<AbnormalExposure> m_AbnormalInfos;
  bool m_AbnormalInfosIsSet;
  std::vector<CongestInfo> m_CongestInfos;
  bool m_CongestInfosIsSet;
  std::vector<QosSustainabilityExposure> m_QosSustainInfos;
  bool m_QosSustainInfosIsSet;
  std::string m_SuppFeat;
};

}  // namespace oai::nef::model

#endif /* AnalyticsData_H_ */
