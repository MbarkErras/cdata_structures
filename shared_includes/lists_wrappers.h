#ifndef DATA_TYPES_H
# define DATA_TYPES_H

# include "libs_includes.h"

typedef struct  s_dstruct_node
{
    void                    *content;
    struct s_dstruct_node   *next;
    struct s_dstruct_node   *prev;
}               t_dstruct_node;

typedef struct  s_dstruct_list
{
    t_dstruct_node  *head;
    t_dstruct_node  *tail;
    size_t          size;

}               t_dstruct_list;

#endif