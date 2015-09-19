#ifndef __AZ_COMMON_H
#define __AZ_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SUCCESS 0
#define FAILURE 1


typedef struct option_ {
    char item[100];
    int flag;
    char *ptr;
    char ch;
}option_t;


#endif
