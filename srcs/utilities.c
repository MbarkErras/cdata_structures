#include "lists_wrappers.h"

size_t	list_counter(t_dstruct_list list, int (*filter)(void *))
{
	size_t	count;

	count = 0;
	while (list.head)
	{
		count += filter(list.head->content);
		list.head = list.head->next;
	}
	return (count);
}

t_dstruct_node *list_find_node(t_dstruct_list list, int (*filter)(void *, void *), void *argument)
{
	while (list.head)
	{
		if (filter(list.head->content, argument))
			return (list.head);
		list.head = list.head->next;
	}
	return (NULL);
}
