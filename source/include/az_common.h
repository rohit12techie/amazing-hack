#ifndef __AZ_COMMON_H
#define __AZ_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define SUCCESS 0
#define FAILURE 1
#define STATUS int

typedef struct option_ {
    char item[100];
    int flag;
    char *ptr;
    char ch;
}option_t;

typedef struct generic_list_
{
    int num_node;
    list_element_t *first;

}generic_list_t;

typedef struct global_ctx {
    generic_list_t *serv_list;
    generic_list_t *user_list;
    generic_list_t *highest_pq;
    generic_list_t *high_pq;
    generic_list_t *normal_pq;
    generic_list_t *low_pq;
    generic_list_t *lowest_pq;
}global_ctx_t;


typedef struct user_context
{
     int item_id;
     long merchant_id;
     long merchantplace_id;
     int priority;
     char data_type;
     void *payload;
}user_context_t;
#endif
