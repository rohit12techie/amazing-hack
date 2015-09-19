/**************
 * Description : This file contains all server APIs
 */
#include "az_server.h"
#include "az_common.h"
#include "az_utility.h"

void get_server_config(server_resiliency_info_t *this)
{
    xmlDoc *doc = NULL;
    xmlNode *rootnode = NULL, *cur = NULL, *cur1 = NULL;
    char temp[ARRAY_INDEX_FIVE];
    int get_val;
    struct stat st;
    int i = 0;
    memset(&st, 0, sizeof(struct stat));

    if (0 !=stat (SERVER_CONFIG_FILE, &st))
    {
        printf("Error:Unable to find Server config file :%s\n",
                                                SERVER_CONFIG_FILE);
        return FAILURE;
    }
    if (NULL == (doc = xmlReadFile (SERVER_CONFIG_FILE, NULL, 0)))
    {
        printf ("error: could not parse file %s\n", SERVER_CONFIG_FILE);
        return FAILURE;
    }
    rootnode = xmlDocGetRootElement (doc);
    for (cur = rootnode->xmlChildrenNode; cur; cur = cur->next)
    {
        if (!xmlStrcmp (cur->name, (const xmlChar *) "SERVER-INFO"))
        {
            for (cur1 = cur->xmlChildrenNode; cur1; cur1 = cur1->next)
            {
                if (!xmlStrcmp (cur1->name, (const xmlChar *)
                                                      "NUMBER-OF-SERVER"))
                {
                    READ_INT32_VALUE_FRM_XML(cur1,"NUMBER-OF-SERVER",
                            this->num_serv,get_val);
                }
                if (!xmlStrcmp (cur1->name, (const xmlChar *)"IP-LIST"))
                {
                    for (cur2 = cur1->xmlChildrenNode; cur2; cur2 = cur2->next)
                    {
                            READ_STR_VALUE_FRM_XML(cur1, "IP-ADD-1",
                                                            this->serv_ips[i++],
                                                            IP_LEN)
                            READ_STR_VALUE_FRM_XML(cur1, "IP-ADD-2",
                                                            this->serv_ips[i++],
                                                            IP_LEN)
                            READ_STR_VALUE_FRM_XML(cur1, "IP-ADD-3",
                                                            this->serv_ips[i++],
                                                            IP_LEN)
                            READ_STR_VALUE_FRM_XML(cur1, "IP-ADD-4",
                                                            this->serv_ips[i++],
                                                            IP_LEN)
                    }

                }
            }
        }
    }
}


void init_server()
{
    int idx = 0;
    printf("Number of Server Active server:");
    scanf("%d",&num_serv);
    server_resiliency_info_t serv_ctx;


    memset(&serv_ctx,0,sizeof(server_resiliency_info_t));
    get_server_config (&serv_ctx);

    serv_ctx.starting_port = PORT1;

    struct sockaddr_in az_serv[MAX_SERV_NUMBER];

    for (idx = 0; idx < serv_ctx ; idx++)
    {
        az_serv[i].sin_family = AF_INET;
        strcpy(az_serv[i].sin_addr.s_addr,serv_ctx.serv_ips[i]);
        az_serv[i].sin_port = serv_ctx.starting_port++;

    }




}


