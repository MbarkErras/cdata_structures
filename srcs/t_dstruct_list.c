#include "lists_wrappers.h"

t_dstruct_list  t_dstruct_list_init(void)
{
    t_dstruct_list  list;

    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    return (list);
}