/***************************************************************************
 * File : az_main.c
 * Description : This file contains all startup of program where other application
 * can be chosen based on desire given option
 */

#include "az_common.h"
#define _GNU_SOURCE
#include <getopt.h>

void get_help()
{
    printf("*********************************************\n");
    printf("1.Init Server\n");
    printf("2.Init Client\n");
    printf("3.SLA Support\n");
    printf("Choose Option :");

}

int main(int argc, char *argv[])
{
    int opt;
    struct option longopts[] = {
    {"initialize", 0, NULL, 'i'},
    {"help", 0, NULL, 'h'},
    {"list", 0, NULL, 'l'},
    {"restart", 0, NULL, 'r'},
    {0,0,0,0}};
#if 0
    while((opt = getopt(argc, argv, ":if:lr:h")) != -1) {
        switch(opt) {
            case 'i':
            case 'h':
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
                switch(opt)
                {
                case 1:
                    init_server();
                    break;
                case 2:
                    init_sla_support();
                    break;
                case 3:
                    init_client();
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

