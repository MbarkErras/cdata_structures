#include "lists_wrappers.h"
void	list_delete_node(t_dstruct_list *list, t_dstruct_node *node,
			void (*node_deconstructor)(void *))
{
	t_dstruct_node *e;

	if (!list || !node)
		return ;
	e = list->head;
	while (e)
	{
		if (e == node)
		{
			if (e->next)
				e->next->prev = e->prev;
			else
				list->tail = e->prev;
			if (e->prev)
				e->prev->next = e->next;
			else
				list->head = e->next;
			if (node_deconstructor)
			{
				node_deconstructor(e->content);
				free(e);
			}
			list->size--;
			return ;
		}
		e = e->next;
	}
}
