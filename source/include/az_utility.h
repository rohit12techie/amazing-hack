#ifndef __AZ_UTILITY_H
#define __AZ_UTILITY_H
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define EIGHT 8
#define NINE 9
#define TEN 10
#define EIGHTYSEVEN 87
#define HUNDRED 100
#define TWOFIFTYFIVE 255
#define FIVEONESIX 516
#define MAX_IMSI_IMEI_IMSIV_LEN             16
#define MAX_M_TMSI_CELLID_TEID_LEN          8
#define MAX_PLMN_ID_LEN                     6
#define MAX_KNAS_INT_ENC_LEN                32
#define MAX_KENB_KASME_PLMNSECKEY_LEN       64
#define MAX_URRP_MME_R_IP_LEN               20
#define MAX_EPS_BR_ID_AND_FLAG_LEN          22
#define MAX_LAI_LEN                         10
#define MAX_TAC_LEN                         4
#define MAX_BITRATE_G_BITRATE_LEN           10
#define MAX_CHARGE_ID_LEN                   8
#define MAX_AV_RAND_AUTN_LEN                32
#define MAX_AV_XRES_LEN                     16
#define MAX_AV_KASME_LEN                    64
#define MAX_UE_RADIO_CAP_LEN                96
#define MAX_ALG_CIP_R_INT_LEN               4


#define READ_STR_VALUE_FRM_XML(curr, string, value, len)\
        else if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_str_from_xml_2_local (curr, (SAI_CHAR *)(value), len))\
                {\
                    return FAILURE;\
                }\
            }\
        }

#define READ_INT8_VALUE_FRM_XML(curr, string, value, get_val)\
        else if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int8_from_xml_2_local (curr, (SAI_INT8 *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (SAI_UINT8)get_val;\
            }\
        }

#define READ_INT8_VALUE_FRM_XML_IF(curr, string, value, get_val)\
        if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int8_from_xml_2_local (curr, (SAI_INT8 *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (SAI_UINT8)get_val;\
            }\
        }

#define READ_INT16_VALUE_FRM_XML(curr, string, value, get_val)\
        else if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int16_from_xml_2_local (curr, (SAI_INT16 *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (SAI_UINT16)get_val;\
            }\
        }

#define READ_INT16_VALUE_FRM_XML_IF(curr, string, value, get_val)\
        if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int16_from_xml_2_local (curr, (SAI_INT16 *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (SAI_UINT16)get_val;\
            }\
        }

#define READ_INT32_VALUE_FRM_XML(curr, string, value, get_val)\
        else if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int32_from_xml_2_local (curr, (SAI_INT32 *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (SAI_UINT32)get_val;\
            }\
        }

#define READ_INT32_VALUE_FRM_XML_IF(curr, string, value, get_val)\
        if (!xmlStrcmp (curr->name,(const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int32_from_xml_2_local (curr, (SAI_INT32 *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (SAI_UINT32)get_val;\
            }\
        }

#define READ_INT64_VALUE_FRM_XML(curr, string, value, get_val)\
        else if (!xmlStrcmp (curr->name,(const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int64_from_xml_2_local (curr, (SAI_UINT64 *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = get_val;\
            }\
        }
#define READ_INT64_VALUE_FRM_XML_IF(curr, string, value, get_val)\
        if (!xmlStrcmp (curr->name,(const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int64_from_xml_2_local (curr, (SAI_UINT64 *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = get_val;\
            }\
        }

#define READ_INT8_VALUE_AND_CONVERT_TO_UCHAR(curr, string, value, get_val)\
        else if (!xmlStrcmp (curr->name,(const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int8_from_xml_2_local (curr, (SAI_INT8 *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (SAI_UCHAR)get_val;\
            }\
        }

#define READ_INT8_VALUE_AND_CONVERT_TO_UCHAR_IF(curr, string, value, get_val)\
        if (!xmlStrcmp (curr->name,(const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int8_from_xml_2_local (curr, (SAI_INT8 *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (SAI_UCHAR)get_val;\
            }\
        }

#define READ_BUFFER_TO_DATA(curr, string, data, buffer, len)\
        else if (!xmlStrcmp (curr->name,(const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                memset (buffer, SAI_ZERO, 100);\
                if (FAILURE ==\
                    copy_str_from_xml_2_local (curr, (SAI_CHAR *)buffer, len))\
                {\
                    return FAILURE;\
                }\
                if(SUCCESS!=convert_str_to_val (buffer, (SAI_CHAR *)data))\
                {\
                    return FAILURE;\
                }\
            }\
        }

#define READ_BUFFER_TO_IPV4_IF(curr, string, ipv4_addr)\
        if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        {\
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_str_to_ipv4_fmt(curr, (SAI_UINT8 *)ipv4_addr))\
                {\
                    return FAILURE;\
                }\
            }\
        }

#define READ_BUFFER_TO_IPV4(curr, string, ipv4_addr)\
        else if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        {\
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_str_to_ipv4_fmt(curr, (SAI_UINT8 *)ipv4_addr))\
                {\
                    return FAILURE;\
                }\
            }\
        }

#define READ_BUFFER_TO_IPV6_IF(curr, string, ipv6_addr)\
        if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        {\
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_str_to_ipv6_fmt(curr, (SAI_UINT8 *)ipv6_addr))\
                {\
                    return FAILURE;\
                }\
            }\
        }

#define READ_BUFFER_TO_IPV6(curr, string, ipv6_addr)\
        else if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        {\
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_str_to_ipv6_fmt(curr, (SAI_UINT8 *)ipv6_addr))\
                {\
                    return FAILURE;\
                }\
            }\
        }

#define READ_BYTE_VALUE_FRM_XML(curr, string, value)\
        else if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        {\
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                copy_byte_from_xml_2_local (curr, (SAI_BYTE *)&value);\
            }\
        }


#endif
