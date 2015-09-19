#ifndef __AZ_UTILITY_H
#define __AZ_UTILITY_H


#include "az_common.h"
#include <libxml/parser.h>
#include <libxml/tree.h>

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

#define IPV4_MAX_LEN                               4
#define IPV6_MAX_LEN                               16
#define ARRAY_INDEX_ZERO                                          0
#define ARRAY_INDEX_ONE                                           1
#define ARRAY_INDEX_TWO                                           2
#define ARRAY_INDEX_THREE                                         3
#define ARRAY_INDEX_FOUR                                          4
#define ARRAY_INDEX_FIVE                                          5
#define ARRAY_INDEX_SIX                                           6
#define ARRAY_INDEX_SEVEN                                         7
#define ARRAY_INDEX_EIGHT                                         8
#define ARRAY_INDEX_NINE                                          9
#define ARRAY_INDEX_TEN                                           10
#define ARRAY_INDEX_ELEVEN                                        11
#define ARRAY_INDEX_TWELVE                                        12
#define ARRAY_INDEX_THIRTEEN                                      13
#define ARRAY_INDEX_FOURTEEN                                      14
#define ARRAY_INDEX_FIFTEEN                                       15
#define ARRAY_INDEX_SIXTEEN                                       16


#define READ_STR_VALUE_FRM_XML(curr, string, value, len)\
        else if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_str_from_xml_2_local (curr, (char *)(value), len))\
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
                    copy_int8_from_xml_2_local (curr, (char *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (unsigned char)get_val;\
            }\
        }

#define READ_INT8_VALUE_FRM_XML_IF(curr, string, value, get_val)\
        if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int8_from_xml_2_local (curr, (char *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (unsigned char)get_val;\
            }\
        }

#define READ_INT16_VALUE_FRM_XML(curr, string, value, get_val)\
        else if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int16_from_xml_2_local (curr, (short int *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (unsigned short)get_val;\
            }\
        }

#define READ_INT16_VALUE_FRM_XML_IF(curr, string, value, get_val)\
        if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int16_from_xml_2_local (curr, (short int *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (unsigned short)get_val;\
            }\
        }

#define READ_INT32_VALUE_FRM_XML(curr, string, value, get_val)\
        else if (!xmlStrcmp (curr->name, (const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int32_from_xml_2_local (curr, (int *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (unsigned int)get_val;\
            }\
        }

#define READ_INT32_VALUE_FRM_XML_IF(curr, string, value, get_val)\
        if (!xmlStrcmp (curr->name,(const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int32_from_xml_2_local (curr, (int *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (unsigned int)get_val;\
            }\
        }

#define READ_INT64_VALUE_FRM_XML(curr, string, value, get_val)\
        else if (!xmlStrcmp (curr->name,(const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int64_from_xml_2_local (curr, (long int *)&get_val))\
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
                    copy_int64_from_xml_2_local (curr, (long int *)&get_val))\
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
                    copy_int8_from_xml_2_local (curr, (char *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (unsigned char)get_val;\
            }\
        }

#define READ_INT8_VALUE_AND_CONVERT_TO_UCHAR_IF(curr, string, value, get_val)\
        if (!xmlStrcmp (curr->name,(const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                if (FAILURE ==\
                    copy_int8_from_xml_2_local (curr, (char *)&get_val))\
                {\
                    return FAILURE;\
                }\
                value = (unsigned char)get_val;\
            }\
        }

#define READ_BUFFER_TO_DATA(curr, string, data, buffer, len)\
        else if (!xmlStrcmp (curr->name,(const xmlChar *) (string)))\
        { \
            if (XML_ELEMENT_NODE == curr->type)\
            {\
                memset (buffer, 0, 100);\
                if (FAILURE ==\
                    copy_str_from_xml_2_local (curr, (char *)buffer, len))\
                {\
                    return FAILURE;\
                }\
                if(SUCCESS!=convert_str_to_val (buffer, (char *)data))\
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
                    copy_str_to_ipv4_fmt(curr, (unsigned char *)ipv4_addr))\
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
                    copy_str_to_ipv4_fmt(curr, (unsigned char *)ipv4_addr))\
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
                    copy_str_to_ipv6_fmt(curr, (unsigned char *)ipv6_addr))\
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
                    copy_str_to_ipv6_fmt(curr, (unsigned char *)ipv6_addr))\
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
                copy_byte_from_xml_2_local (curr, (8 *)&value);\
            }\
        }


#endif



