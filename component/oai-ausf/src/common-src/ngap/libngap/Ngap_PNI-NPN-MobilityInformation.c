/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "asn.1/Information Element Definitions.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fno-include-deps -findirect-choice
 * -no-gen-example -gen-APER -gen-UPER -no-gen-JER -gen-BER -D src`
 */

#include "Ngap_PNI-NPN-MobilityInformation.h"

#include "Ngap_ProtocolExtensionContainer.h"
asn_TYPE_member_t asn_MBR_Ngap_PNI_NPN_MobilityInformation_1[] = {
    {ATF_NOFLAGS,
     0,
     offsetof(struct Ngap_PNI_NPN_MobilityInformation, allowed_PNI_NPI_List),
     (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
     -1, /* IMPLICIT tag at current level */
     &asn_DEF_Ngap_Allowed_PNI_NPN_List,
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
     "allowed-PNI-NPI-List"},
    {ATF_POINTER,
     1,
     offsetof(struct Ngap_PNI_NPN_MobilityInformation, iE_Extensions),
     (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
     -1, /* IMPLICIT tag at current level */
     &asn_DEF_Ngap_ProtocolExtensionContainer_9666P199,
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
static const int asn_MAP_Ngap_PNI_NPN_MobilityInformation_oms_1[] = {1};
static const ber_tlv_tag_t asn_DEF_Ngap_PNI_NPN_MobilityInformation_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))};
static const asn_TYPE_tag2member_t
    asn_MAP_Ngap_PNI_NPN_MobilityInformation_tag2el_1[] = {
        {(ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0,
         0},                                          /* allowed-PNI-NPI-List */
        {(ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0} /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_Ngap_PNI_NPN_MobilityInformation_specs_1 = {
    sizeof(struct Ngap_PNI_NPN_MobilityInformation),
    offsetof(struct Ngap_PNI_NPN_MobilityInformation, _asn_ctx),
    asn_MAP_Ngap_PNI_NPN_MobilityInformation_tag2el_1,
    2, /* Count of tags in the map */
    asn_MAP_Ngap_PNI_NPN_MobilityInformation_oms_1, /* Optional members */
    1,
    0, /* Root/Additions */
    2, /* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Ngap_PNI_NPN_MobilityInformation = {
    "PNI-NPN-MobilityInformation",
    "PNI-NPN-MobilityInformation",
    &asn_OP_SEQUENCE,
    asn_DEF_Ngap_PNI_NPN_MobilityInformation_tags_1,
    sizeof(asn_DEF_Ngap_PNI_NPN_MobilityInformation_tags_1) /
        sizeof(asn_DEF_Ngap_PNI_NPN_MobilityInformation_tags_1[0]), /* 1 */
    asn_DEF_Ngap_PNI_NPN_MobilityInformation_tags_1, /* Same as above */
    sizeof(asn_DEF_Ngap_PNI_NPN_MobilityInformation_tags_1) /
        sizeof(asn_DEF_Ngap_PNI_NPN_MobilityInformation_tags_1[0]), /* 1 */
    {
#if !defined(ASN_DISABLE_OER_SUPPORT)
        0,
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
        0,
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
        SEQUENCE_constraint},
    asn_MBR_Ngap_PNI_NPN_MobilityInformation_1,
    2,                                                /* Elements count */
    &asn_SPC_Ngap_PNI_NPN_MobilityInformation_specs_1 /* Additional specs */
};
