/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "asn.1/Information Element Definitions.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fno-include-deps -findirect-choice
 * -no-gen-example -gen-APER -gen-UPER -no-gen-JER -gen-BER -D src`
 */

#include "Ngap_SecurityIndication.h"

#include "Ngap_ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_Ngap_SecurityIndication_1[] = {
    {ATF_NOFLAGS,
     0,
     offsetof(struct Ngap_SecurityIndication, integrityProtectionIndication),
     (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
     -1, /* IMPLICIT tag at current level */
     &asn_DEF_Ngap_IntegrityProtectionIndication,
     0,
     {
#if !defined(ASN_DISABLE_OER_SUPPORT)
         0,
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
         0,
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
         0},
     0,
     0, /* No default value */
     "integrityProtectionIndication"},
    {ATF_NOFLAGS,
     0,
     offsetof(
         struct Ngap_SecurityIndication, confidentialityProtectionIndication),
     (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
     -1, /* IMPLICIT tag at current level */
     &asn_DEF_Ngap_ConfidentialityProtectionIndication,
     0,
     {
#if !defined(ASN_DISABLE_OER_SUPPORT)
         0,
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
         0,
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
         0},
     0,
     0, /* No default value */
     "confidentialityProtectionIndication"},
    {ATF_POINTER,
     2,
     offsetof(
         struct Ngap_SecurityIndication, maximumIntegrityProtectedDataRate_UL),
     (ASN_TAG_CLASS_CONTEXT | (2 << 2)),
     -1, /* IMPLICIT tag at current level */
     &asn_DEF_Ngap_MaximumIntegrityProtectedDataRate,
     0,
     {
#if !defined(ASN_DISABLE_OER_SUPPORT)
         0,
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
         0,
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
         0},
     0,
     0, /* No default value */
     "maximumIntegrityProtectedDataRate-UL"},
    {ATF_POINTER,
     1,
     offsetof(struct Ngap_SecurityIndication, iE_Extensions),
     (ASN_TAG_CLASS_CONTEXT | (3 << 2)),
     -1, /* IMPLICIT tag at current level */
     &asn_DEF_Ngap_ProtocolExtensionContainer_9666P229,
     0,
     {
#if !defined(ASN_DISABLE_OER_SUPPORT)
         0,
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
         0,
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
         0},
     0,
     0, /* No default value */
     "iE-Extensions"},
};
static const int asn_MAP_Ngap_SecurityIndication_oms_1[]            = {2, 3};
static const ber_tlv_tag_t asn_DEF_Ngap_SecurityIndication_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))};
static const asn_TYPE_tag2member_t asn_MAP_Ngap_SecurityIndication_tag2el_1[] =
    {
        {(ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0,
         0}, /* integrityProtectionIndication */
        {(ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0,
         0}, /* confidentialityProtectionIndication */
        {(ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0,
         0}, /* maximumIntegrityProtectedDataRate-UL */
        {(ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0} /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_Ngap_SecurityIndication_specs_1 = {
    sizeof(struct Ngap_SecurityIndication),
    offsetof(struct Ngap_SecurityIndication, _asn_ctx),
    asn_MAP_Ngap_SecurityIndication_tag2el_1,
    4,                                     /* Count of tags in the map */
    asn_MAP_Ngap_SecurityIndication_oms_1, /* Optional members */
    2,
    0, /* Root/Additions */
    4, /* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Ngap_SecurityIndication = {
    "SecurityIndication",
    "SecurityIndication",
    &asn_OP_SEQUENCE,
    asn_DEF_Ngap_SecurityIndication_tags_1,
    sizeof(asn_DEF_Ngap_SecurityIndication_tags_1) /
        sizeof(asn_DEF_Ngap_SecurityIndication_tags_1[0]), /* 1 */
    asn_DEF_Ngap_SecurityIndication_tags_1,                /* Same as above */
    sizeof(asn_DEF_Ngap_SecurityIndication_tags_1) /
        sizeof(asn_DEF_Ngap_SecurityIndication_tags_1[0]), /* 1 */
    {
#if !defined(ASN_DISABLE_OER_SUPPORT)
        0,
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
        0,
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
        SEQUENCE_constraint},
    asn_MBR_Ngap_SecurityIndication_1,
    4,                                       /* Elements count */
    &asn_SPC_Ngap_SecurityIndication_specs_1 /* Additional specs */
};
