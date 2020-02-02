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
