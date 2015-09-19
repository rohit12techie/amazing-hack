#ifndef __AZ_COMMON_H
#define __AZ_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SUCCESS 0
#define FAILURE 1
#define STATUS int

typedef struct option_ {
    char item[100];
    int flag;
    char *ptr;
    char ch;
}option_t;


#endif

typedef struct user_context
{
     int item_id;
     long merchant_id;
     long merchantplace_id;
     int priority;
     char data_type;
     void *payload;
}user_context_t;
