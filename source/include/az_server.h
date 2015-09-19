#ifndef __AZ_SERVER_H
#define __AZ_SERVER_H

#include "az_common.h"

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_SERV_NUMBER 100
#define IP_LEN 20


enum server_port {
    PORT1 = 9000,
    PORT2,
    PORT3,
    PORT4
}server_port_e;

#define SERVER_CONFIG_FILE "source/server/server_config.xml"

typedef struct server_resiliency_info {
    struct server_resiliency_info *next;
    int s_id;
    int starting_port;
    int num_serv;
    char serv_ips[IP_LEN];
    int load_factor;
}server_resiliency_info_t;

#endif
