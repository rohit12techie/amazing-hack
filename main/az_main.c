/***************************************************************************
 * File : az_main.c
 * Description : This file contains all startup of program where other application
 * can be chosen based on desire given option
 */

#include "az_all_defines.h"


int main(int argc, char *argv[])
{
    int opt;
    while((opt = getopt(argc, argv, “:if:lr”)) != -1) {
    switch(opt) {
    case ‘i’:
    case ‘l’:
    case ‘r’:
    printf(“option: %c\n”, opt);
    break;
    case ‘f’:
    printf(“filename: %s\n”, optarg);
    break;
    case ‘:’:
    printf(“option needs a value\n”);
    break;
    case ‘?’:
    printf(“unknown option: %c\n”, optopt);
    break;
    }
}
