/**************
 * Description : This file contains all server APIs
 */
#include "az_server.h"
#include "az_common.h"
#include "az_utility.h"

void get_server_config()
{
    xmlDoc *doc = NULL;
    xmlNode *rootnode = NULL, *cur = NULL, *cur1 = NULL;
    char temp[ARRAY_INDEX_FIVE];
    int get_val;
    struct stat st;

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
}


void init_server()
{
    int num_serv = 0;
    printf("Number of Server Active server:");
    scanf("%d",&num_serv);
    struct sockaddr_in az_serv;


}


