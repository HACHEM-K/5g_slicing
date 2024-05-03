/**
 * Nudsf_DataRepository
 * Nudsf Data Repository Service.   © 2022, 3GPP Organizational Partners (ARIB,
 * ATIS, CCSA, ETSI, TSDSI, TTA, TTC).   All rights reserved.
 *
 * The version of the OpenAPI document: 1.2.0-alpha.1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * TagType.h
 *
 * Defines the Tag Type
 */

#ifndef TagType_H_
#define TagType_H_

#include <string>
#include "KeyType.h"
#include <nlohmann/json.hpp>

namespace oai::model::udsf {

/// <summary>
/// Defines the Tag Type
/// </summary>
class TagType {
 public:
  TagType();
  virtual ~TagType() = default;

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

  bool operator==(const TagType& rhs) const;
  bool operator!=(const TagType& rhs) const;

  /////////////////////////////////////////////
  /// TagType members

  /// <summary>
  ///
  /// </summary>
  std::string getTagName() const;
  void setTagName(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  oai::model::udsf::KeyType getKeyType() const;
  void setKeyType(oai::model::udsf::KeyType const& value);
  /// <summary>
  ///
  /// </summary>
  bool isSort() const;
  void setSort(bool const value);
  bool sortIsSet() const;
  void unsetSort();
  /// <summary>
  ///
  /// </summary>
  bool isPresence() const;
  void setPresence(bool const value);
  bool presenceIsSet() const;
  void unsetPresence();

  friend void to_json(nlohmann::json& j, const TagType& o);
  friend void from_json(const nlohmann::json& j, TagType& o);

 protected:
  std::string m_TagName;

  oai::model::udsf::KeyType m_KeyType;

  bool m_Sort;
  bool m_SortIsSet;
  bool m_Presence;
  bool m_PresenceIsSet;
};

}  // namespace oai::model::udsf

#endif /* TagType_H_ */
