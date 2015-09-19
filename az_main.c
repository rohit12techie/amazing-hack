/***************************************************************************
 * File : az_main.c
 * Description : This file contains all startup of program where other application
 * can be chosen based on desire given option
 */

#include "az_common.h"
#define _GNU_SOURCE
#include <getopt.h>

int main(int argc, char *argv[])
{
    int opt;
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


    while(1)
    {
            sleep(1000);
    }
}
