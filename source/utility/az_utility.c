#include "az_common.h"



STATUS
copy_str_from_xml_2_local (xmlNode * node, char *buffer, unsigned char len)
{
    xmlChar *val;
    unsigned char slen;

    val = xmlGetProp (node, (xmlChar *) "val");
    if (NULL == (char *) val || NULL == buffer || 0 == len)
    {
        printf ("[%s] get prop failed\n", node->name);
        return FAILURE;
    }

    slen = strlen ((const char *)val);
    if (slen > len)
    {
        printf ("[%s] value is corrupted\n", node->name);
    }

    strncpy (buffer, (const char *) val, len);
    return SUCCESS;
}


STATUS
copy_int8_from_xml_2_local (xmlNode * node, SAI_INT8 * out)
{
    xmlChar *val;
    val = xmlGetProp (node, (xmlChar *) "val");

    if (NULL == (char *) val)
    {
        printf ("[%s] get prop failed\n", node->name);
        return FAILURE;
    }
    *out = atoi ((char *) val);

    return SUCCESS;
}


STATUS
copy_int16_from_xml_2_local (xmlNode * node, SAI_INT16 * out)
{
    xmlChar *val;
    val = xmlGetProp (node, (xmlChar *) "val");

    if (NULL == (char *) val)
    {
        printf ("[%s] get prop failed\n", node->name);
        return FAILURE;
    }
    *out = atoi ((char *) val);

    return SUCCESS;
}

STATUS
copy_int32_from_xml_2_local (xmlNode * node, SAI_INT32 * out)
{
    xmlChar *val;
    val = xmlGetProp (node, (xmlChar *) "val");

    if (NULL == (char *) val)
    {
        printf ("[%s] get prop failed\n", node->name);
        return FAILURE;
    }
    *out = atoi ((char *) val);

    return SUCCESS;
}

STATUS
copy_int64_from_xml_2_local (xmlNode * node, long int * out)
{
    xmlChar *val;
    val = xmlGetProp (node, (xmlChar *) "val");

    if (NULL == (char *) val)
    {
        printf ("[%s] get prop failed\n", node->name);
        return FAILURE;
    }
    *out = atoll ((char *) val);

    return SUCCESS;
}


STATUS
copy_byte_from_xml_2_local (xmlNode * node, SAI_BYTE * out)
{
    xmlChar *val;
    val = xmlGetProp (node, (xmlChar *) "val");

    if (NULL == (char *) val)
    {
        printf ("[%s] get prop failed\n", node->name);
        return FAILURE;
    }
    *out = (SAI_BYTE) atoi ((char *) val);

    return SUCCESS;
}

STATUS
copy_str_to_ipv4_fmt (xmlNode * node, unsigned char out[4])
{
    xmlChar *val;
    unsigned char len;

    val = xmlGetProp (node, (xmlChar *) "val");
    len = strlen ((const char *)val);
    char buffer[len+1];

    if (FAILURE ==
        copy_str_from_xml_2_local (node, buffer, len))
    {
        printf ("[%s] get prop failed\n", node->name);
        return FAILURE;
    }
    sscanf (buffer, "%d.%d.%d.%d",
            (int *) & out[ARRAY_INDEX_ZERO],
            (int *) & out[ARRAY_INDEX_ONE],
            (int *) & out[ARRAY_INDEX_TWO],
            (int *) & out[ARRAY_INDEX_THREE] );

    return SUCCESS;
}

STATUS
copy_str_to_ipv6_fmt (xmlNode * node, unsigned char out[16])
{
    xmlChar *val;
    unsigned char len;

    val = xmlGetProp (node, (xmlChar *) "val");
    len = strlen ((const char *)val);
    char buffer[len+1];
    memset (buffer, 0, len+1);

    if (FAILURE ==
        copy_str_from_xml_2_local (node, buffer, len))
    {
        printf ("[%s] get prop failed\n", node->name);
        return FAILURE;
    }
    sscanf (buffer, "%d.%d.%d.%d.%d.%d.%d.%d.%d.%d.%d.%d.%d.%d.%d.%d",
            (int *) & out[ARRAY_INDEX_ZERO],
            (int *) & out[ARRAY_INDEX_ONE],
            (int *) & out[ARRAY_INDEX_TWO],
            (int *) & out[ARRAY_INDEX_THREE],
            (int *) & out[ARRAY_INDEX_FOUR],
            (int *) & out[ARRAY_INDEX_FIVE],
            (int *) & out[ARRAY_INDEX_SIX],
            (int *) & out[ARRAY_INDEX_SEVEN],
            (int *) & out[ARRAY_INDEX_EIGHT],
            (int *) & out[ARRAY_INDEX_NINE],
            (int *) & out[ARRAY_INDEX_TEN],
            (int *) & out[ARRAY_INDEX_ELEVEN],
            (int *) & out[ARRAY_INDEX_TWELVE],
            (int *) & out[ARRAY_INDEX_THIRTEEN],
            (int *) & out[ARRAY_INDEX_FOURTEEN],
            (int *) & out[ARRAY_INDEX_FIFTEEN] );

    return SUCCESS;
}

/************************ End Of File xml_utils.c *****************************/
