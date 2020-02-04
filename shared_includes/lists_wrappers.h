#ifndef DATA_TYPES_H
# define DATA_TYPES_H

# include "libs_includes.h"
# include "utilities_macros.h"

typedef struct  s_dstruct_node
{
    void                    *content;
    size_t                  content_size;
    struct s_dstruct_node   *next;
    struct s_dstruct_node   *prev;
}               t_dstruct_node;

typedef struct  s_dstruct_list
{
    t_dstruct_node  *head;
    t_dstruct_node  *tail;
    size_t          size;

}               t_dstruct_list;

t_dstruct_list  t_dstruct_list_init(void);
t_dstruct_node  *t_dstruct_create_node(void *content, size_t content_size);

/*
** UTILITIES
*/

size_t          list_counter(t_dstruct_list list, int (*filter)(void *));
t_dstruct_node *list_find_node(t_dstruct_list list, int (*filter)(void *, void *), void *argument);

/*
** LIST_DELETE
*/

void    list_delete_node(t_dstruct_list *list, t_dstruct_node *node,
		void (*node_deconstructor)(void *));

#endif
