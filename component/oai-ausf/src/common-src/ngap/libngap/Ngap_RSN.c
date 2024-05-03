/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "asn.1/Information Element Definitions.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fno-include-deps -findirect-choice
 * -no-gen-example -gen-APER -gen-UPER -no-gen-JER -gen-BER -D src`
 */

#include "Ngap_RSN.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_Ngap_RSN_constr_1 CC_NOTUSED = {
    {0, 0},
    -1};
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_Ngap_RSN_constr_1 CC_NOTUSED = {
    {APC_CONSTRAINED | APC_EXTENSIBLE, 1, 1, 0, 1} /* (0..1,...) */,
    {APC_UNCONSTRAINED, -1, -1, 0, 0},
    0,
    0 /* No PER value map */
};
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_Ngap_RSN_value2enum_1[] = {
    {0, 2, "v1"},
    {1, 2, "v2"}
    /* This list is extensible */
};
static const unsigned int asn_MAP_Ngap_RSN_enum2value_1[] = {
    0, /* v1(0) */
    1  /* v2(1) */
       /* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_Ngap_RSN_specs_1 = {
    asn_MAP_Ngap_RSN_value2enum_1, /* "tag" => N; sorted by tag */
    asn_MAP_Ngap_RSN_enum2value_1, /* N => "tag"; sorted by N */
    2,                             /* Number of elements in the maps */
    3,                             /* Extensions before this member */
    1,                             /* Strict enumeration */
    0,                             /* Native long size */
    0};
static const ber_tlv_tag_t asn_DEF_Ngap_RSN_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (10 << 2))};
asn_TYPE_descriptor_t asn_DEF_Ngap_RSN = {
    "RSN",
    "RSN",
    &asn_OP_NativeEnumerated,
    asn_DEF_Ngap_RSN_tags_1,
    sizeof(asn_DEF_Ngap_RSN_tags_1) /
        sizeof(asn_DEF_Ngap_RSN_tags_1[0]), /* 1 */
    asn_DEF_Ngap_RSN_tags_1,                /* Same as above */
    sizeof(asn_DEF_Ngap_RSN_tags_1) /
        sizeof(asn_DEF_Ngap_RSN_tags_1[0]), /* 1 */
    {
#if !defined(ASN_DISABLE_OER_SUPPORT)
        &asn_OER_type_Ngap_RSN_constr_1,
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
        &asn_PER_type_Ngap_RSN_constr_1,
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
        NativeEnumerated_constraint},
    0,
    0,                        /* Defined elsewhere */
    &asn_SPC_Ngap_RSN_specs_1 /* Additional specs */
};
