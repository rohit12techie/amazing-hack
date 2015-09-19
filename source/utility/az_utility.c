#include "az_common.h"
#include "az_utility.h"

extern server_resiliency_info_t *global_ctx;

room_balance_sheet_t *
find_member_details_by_name(char *name)
{
    room_balance_sheet_t *node = NULL;
    node = (room_balance_sheet_t *)mctx->list->first;

    if ( NULL == node)
    {
        printf("No Item found in list\n");
        return NULL;

    }
    while(node)
    {
        if(!strcmp(node->name,name))
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

list_element_t * add_node_into_list (generic_list_t *list,void *node)
{
    list_element_t *cur = NULL;
    list_element_t *elem = NULL;

    elem = node;
    cur = list->first;

    if (NULL == cur)
    {
        list->first = elem;

    } else {
        elem->next = cur;
        list->first = elem;
    }
    list->num_node++;
    return (elem);
}

void display_list_element(generic_list_t *list)
{
    room_balance_sheet_t *temp = NULL;
    if ( NULL == list)
    {
        printf("List is Empty\n");
        return;
    }

    printf("Number of Element in List:%d\n",list->num_node);

    temp  = (room_balance_sheet_t *)list->first;
    while(temp)
    {
        printf("Name:%s\t",temp->name);
        temp = temp->next;
    }
}


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
copy_int8_from_xml_2_local (xmlNode * node, char * out)
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
copy_int16_from_xml_2_local (xmlNode * node, short int * out)
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
copy_int32_from_xml_2_local (xmlNode * node, int * out)
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
copy_byte_from_xml_2_local (xmlNode * node, unsigned char * out)
{
    xmlChar *val;
    val = xmlGetProp (node, (xmlChar *) "val");

    if (NULL == (char *) val)
    {
        printf ("[%s] get prop failed\n", node->name);
        return FAILURE;
    }
    *out = (unsigned char) atoi ((char *) val);

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
