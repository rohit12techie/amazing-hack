/***************************************************************************
 * File : az_main.c
 * Description : This file contains all startup of program where other application
 * can be chosen based on desire given option
 */

#include "az_common.h"
#define _GNU_SOURCE
#include <getopt.h>

global_ctx_t *ctx;
server_resiliency_info_t *global_ctx;
void get_help()
{
    printf("*********************************************\n");
    printf("1.Init Server\n");
    printf("2.Init Client\n");
    printf("3.SLA Support\n");
    printf("Choose Option :");

    return;

}
int init_global_ctx()
{


    generic_list_t *temp1 = NULL,*temp2 = NULL, *temp3 = NULL, *temp4 = NULL, *temp5;
    room_balance_sheet_t *dummy_node = NULL;
/*
 * Initializing main context
 */
    ctxt  = (main_context_t *)malloc(sizeof(main_context_t));
    if ( NULL == ctxt)
    {
        printf("[%d][%s]Fatal Error : Failed to allocate memory\n",__LINE__,__FUNCTION__);
        exit(1);
    }
    memset(ctxt,0,sizeof(main_context_t));

/*
 * Initializing Generic Linked list(single linked list)
 */
    ctxt->list = (generic_list_t *)malloc(sizeof(generic_list_t));
    if ( NULL == ctxt->list)
    {
        printf("[%d][%s]Fatal Error : Failed to allocate memory\n",__LINE__,__FUNCTION__);
        exit(1);
    }
    memset(ctxt->list,0,sizeof(generic_list_t));
    ctxt->list->num_node = 0;
    ctxt->list->first = NULL;
}
int main(int argc, char *argv[])
{
    int opt;
#if 0
    option_t longopts[] = {
    {"initialize", 0, NULL, 'i'},
    {"file", 1, NULL, 'f'},
    {"list", 0, NULL, 'l'},
    {"restart", 0, NULL, 'r'},
    {0,0,0,0}};

    while((opt = getopt(argc, argv, ":if:lr")) != -1) {
        switch(opt) {
        case 'i':
        case 'l':
        case 'r':
        printf("option: %c\n", opt);
        break;
        case 'f':
        printf("filename: %s\n", optarg);
        break;
        case ':':
        printf("option needs a value\n");
        break;
        case '?':
        printf("unknown option: %c\n", optopt);
        break;
        }
    }
    for(; optind < argc; optind++)
        printf("argument: %s\n", argv[optind]);

#endif
    do {
            get_help();
            scanf("%d",opt);
            switch(opt)
            {
            case 1:
                init_server();
                break;
            case 2:
              //  init_sla_support();
                break;
            case 3:
              //  init_client();
                break;
            default:
                printf("Oops you might pressed '%d' ", opt );

            }

    }while(opt != 0);

    while(1)
    {
            sleep(1000);
    }
}
