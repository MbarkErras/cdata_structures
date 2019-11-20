#include <stdlib.h>

typedef struct		s_node
{
	void		*content;
	struct s_node	*parent;
}			t_node;

t_node	*make_set(void *content)
{
	t_node *set;

	set = (t_node *)malloc(sizeof(t_node));
	set->content = content;
	set->parent = set;
}

t_node	*find_set(t_node *node)
{
	if (node->parent == node)
		return (node);
	return (find_set(node->parent));
}

void	union_sets(t_node *a, t_node *b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b)
		a->parent = b;
}
