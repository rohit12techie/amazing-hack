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

#endif

typedef server_information
{
    char ip_add[16];
    long load_factor;
    int client_id;
    int mq_id;
}server_info_t;


