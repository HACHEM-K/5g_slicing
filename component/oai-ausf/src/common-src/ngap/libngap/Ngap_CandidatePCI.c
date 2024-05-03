/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "asn.1/Information Element Definitions.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fno-include-deps -findirect-choice
 * -no-gen-example -gen-APER -gen-UPER -no-gen-JER -gen-BER -D src`
 */

#include "Ngap_CandidatePCI.h"

#include "Ngap_ProtocolExtensionContainer.h"
static int memb_Ngap_candidatePCI_constraint_1(
    const asn_TYPE_descriptor_t* td, const void* sptr,
    asn_app_constraint_failed_f* ctfailcb, void* app_key) {
  long value;

  if (!sptr) {
    ASN__CTFAIL(
        app_key, td, sptr, "%s: value not given (%s:%d)", td->name, __FILE__,
        __LINE__);
    return -1;
  }

  value = *(const long*) sptr;

  if ((value >= 0L && value <= 1007L)) {
    /* Constraint check succeeded */
    return 0;
  } else {
    ASN__CTFAIL(
        app_key, td, sptr, "%s: constraint failed (%s:%d)", td->name, __FILE__,
        __LINE__);
    return -1;
  }
}

static int memb_Ngap_candidateNRARFCN_constraint_1(
    const asn_TYPE_descriptor_t* td, const void* sptr,
    asn_app_constraint_failed_f* ctfailcb, void* app_key) {
  long value;

  if (!sptr) {
    ASN__CTFAIL(
        app_key, td, sptr, "%s: value not given (%s:%d)", td->name, __FILE__,
        __LINE__);
    return -1;
  }

  value = *(const long*) sptr;

  if ((value >= 0L && value <= 3279165L)) {
    /* Constraint check succeeded */
    return 0;
  } else {
    ASN__CTFAIL(
        app_key, td, sptr, "%s: constraint failed (%s:%d)", td->name, __FILE__,
        __LINE__);
    return -1;
  }
}

#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_memb_Ngap_candidatePCI_constr_2
    CC_NOTUSED = {{0, 0}, -1};
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_Ngap_candidatePCI_constr_2
    CC_NOTUSED = {
        {APC_CONSTRAINED | APC_EXTENSIBLE, 10, 10, 0, 1007} /* (0..1007,...) */,
        {APC_UNCONSTRAINED, -1, -1, 0, 0},
        0,
        0 /* No PER value map */
};
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_memb_Ngap_candidateNRARFCN_constr_3
    CC_NOTUSED = {{4, 1} /* (0..3279165) */, -1};
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_Ngap_candidateNRARFCN_constr_3
    CC_NOTUSED = {
        {APC_CONSTRAINED, 22, -1, 0, 3279165} /* (0..3279165) */,
        {APC_UNCONSTRAINED, -1, -1, 0, 0},
        0,
        0 /* No PER value map */
};
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
asn_TYPE_member_t asn_MBR_Ngap_CandidatePCI_1[] = {
    {ATF_NOFLAGS,
     0,
     offsetof(struct Ngap_CandidatePCI, candidatePCI),
     (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
     -1, /* IMPLICIT tag at current level */
     &asn_DEF_NativeInteger,
     0,
     {
#if !defined(ASN_DISABLE_OER_SUPPORT)
         &asn_OER_memb_Ngap_candidatePCI_constr_2,
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
         &asn_PER_memb_Ngap_candidatePCI_constr_2,
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
         memb_Ngap_candidatePCI_constraint_1},
     0,
     0, /* No default value */
     "candidatePCI"},
    {ATF_NOFLAGS,
     0,
     offsetof(struct Ngap_CandidatePCI, candidateNRARFCN),
     (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
     -1, /* IMPLICIT tag at current level */
     &asn_DEF_NativeInteger,
     0,
     {
#if !defined(ASN_DISABLE_OER_SUPPORT)
         &asn_OER_memb_Ngap_candidateNRARFCN_constr_3,
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
         &asn_PER_memb_Ngap_candidateNRARFCN_constr_3,
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
         memb_Ngap_candidateNRARFCN_constraint_1},
     0,
     0, /* No default value */
     "candidateNRARFCN"},
    {ATF_POINTER,
     1,
     offsetof(struct Ngap_CandidatePCI, iE_Extensions),
     (ASN_TAG_CLASS_CONTEXT | (2 << 2)),
     -1, /* IMPLICIT tag at current level */
     &asn_DEF_Ngap_ProtocolExtensionContainer_9666P27,
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
static const int asn_MAP_Ngap_CandidatePCI_oms_1[]            = {2};
static const ber_tlv_tag_t asn_DEF_Ngap_CandidatePCI_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))};
static const asn_TYPE_tag2member_t asn_MAP_Ngap_CandidatePCI_tag2el_1[] = {
    {(ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0}, /* candidatePCI */
    {(ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0}, /* candidateNRARFCN */
    {(ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0}  /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_Ngap_CandidatePCI_specs_1 = {
    sizeof(struct Ngap_CandidatePCI),
    offsetof(struct Ngap_CandidatePCI, _asn_ctx),
    asn_MAP_Ngap_CandidatePCI_tag2el_1,
    3,                               /* Count of tags in the map */
    asn_MAP_Ngap_CandidatePCI_oms_1, /* Optional members */
    1,
    0, /* Root/Additions */
    3, /* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Ngap_CandidatePCI = {
    "CandidatePCI",
    "CandidatePCI",
    &asn_OP_SEQUENCE,
    asn_DEF_Ngap_CandidatePCI_tags_1,
    sizeof(asn_DEF_Ngap_CandidatePCI_tags_1) /
        sizeof(asn_DEF_Ngap_CandidatePCI_tags_1[0]), /* 1 */
    asn_DEF_Ngap_CandidatePCI_tags_1,                /* Same as above */
    sizeof(asn_DEF_Ngap_CandidatePCI_tags_1) /
        sizeof(asn_DEF_Ngap_CandidatePCI_tags_1[0]), /* 1 */
    {
#if !defined(ASN_DISABLE_OER_SUPPORT)
        0,
#endif /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
        0,
#endif /* !defined(ASN_DISABLE_UPER_SUPPORT) ||                                \
          !defined(ASN_DISABLE_APER_SUPPORT) */
        SEQUENCE_constraint},
    asn_MBR_Ngap_CandidatePCI_1,
    3,                                 /* Elements count */
    &asn_SPC_Ngap_CandidatePCI_specs_1 /* Additional specs */
};
