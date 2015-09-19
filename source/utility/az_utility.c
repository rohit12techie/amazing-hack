#include "az_common.h"


SAI_STATUS
copy_str_from_xml_2_local (xmlNode * node, char *buffer, SAI_UINT8 len)
{
    xmlChar *val;
    SAI_UINT8 slen;

    val = xmlGetProp (node, (xmlChar *) "val");
    if (NULL == (char *) val || NULL == buffer || SAI_ZERO == len)
    {
        SAI_DEBUG_L1 ("[%s] get prop failed\n", node->name);
        return SAI_FAILURE;
    }

    slen = strlen ((const char *)val);
    if (slen > len)
    {
        SAI_DEBUG_L1 ("[%s] value is corrupted\n", node->name);
    }

    strncpy (buffer, (const char *) val, len);
    return SAI_SUCCESS;
}

