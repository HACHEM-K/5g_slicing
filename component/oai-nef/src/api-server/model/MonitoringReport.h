/**
 * Nnef_EventExposure
 * NEF Event Exposure Service. © 2021, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.0.5
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * MonitoringReport.h
 *
 *
 */

#ifndef MonitoringReport_H_
#define MonitoringReport_H_

#include <nlohmann/json.hpp>
#include <string>

#include "EventType.h"
#include "ReachabilityForSmsReport.h"
#include "ReachabilityReport.h"
#include "Report.h"

namespace oai::nef::model {

/// <summary>
///
/// </summary>
class MonitoringReport {
 public:
  MonitoringReport();
  virtual ~MonitoringReport() = default;

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

  bool operator==(const MonitoringReport& rhs) const;
  bool operator!=(const MonitoringReport& rhs) const;

  /////////////////////////////////////////////
  /// MonitoringReport members

  /// <summary>
  ///
  /// </summary>
  int32_t getReferenceId() const;
  void setReferenceId(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  EventType getEventType() const;
  void setEventType(EventType const& value);
  /// <summary>
  ///
  /// </summary>
  Report getReport() const;
  void setReport(Report const& value);
  bool reportIsSet() const;
  void unsetReport();
  /// <summary>
  ///
  /// </summary>
  ReachabilityForSmsReport getReachabilityForSmsReport() const;
  void setReachabilityForSmsReport(ReachabilityForSmsReport const& value);
  bool reachabilityForSmsReportIsSet() const;
  void unsetReachabilityForSmsReport();
  /// <summary>
  ///
  /// </summary>
  std::string getGpsi() const;
  void setGpsi(std::string const& value);
  bool gpsiIsSet() const;
  void unsetGpsi();
  /// <summary>
  ///
  /// </summary>
  std::string getTimeStamp() const;
  void setTimeStamp(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  ReachabilityReport getReachabilityReport() const;
  void setReachabilityReport(ReachabilityReport const& value);
  bool reachabilityReportIsSet() const;
  void unsetReachabilityReport();

  friend void to_json(nlohmann::json& j, const MonitoringReport& o);
  friend void from_json(const nlohmann::json& j, MonitoringReport& o);

 protected:
  int32_t m_ReferenceId;

  EventType m_EventType;

  Report m_Report;
  bool m_ReportIsSet;
  ReachabilityForSmsReport m_ReachabilityForSmsReport;
  bool m_ReachabilityForSmsReportIsSet;
  std::string m_Gpsi;
  bool m_GpsiIsSet;
  std::string m_TimeStamp;

  ReachabilityReport m_ReachabilityReport;
  bool m_ReachabilityReportIsSet;
};

}  // namespace oai::nef::model

#endif /* MonitoringReport_H_ */
