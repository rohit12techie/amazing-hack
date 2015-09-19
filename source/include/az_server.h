#ifndef __AZ_SERVER_H
#define __AZ_SERVER_H

#include "az_common.h"

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 100
#define SERVER_CONFIG_FILE "source/server/server_config.xml"

typedef struct server_resiliency_info {
    struct server_resiliency_info *next;
    int s_id;
    int starting_port;
    int num_serv;
    char serv_ips[IP_LEN];
    int load_factor;
}server_resiliency_info_t;

typedef server_information
{
    char ip_add[16];
    long load_factor;
    int client_id;
    int mq_id;
}server_info_t;


#endif


