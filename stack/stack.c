#include "stack.h"

void    stack_push(t_dstruct_list *stack, t_dstruct_node *node)
{
#ifndef DSTRUCT_PROTECT
    if (!stack || !node)
        return ;
#endif
    if (!stack->head)
        stack->head = node;
    else
    {
        node->next = NULL;
        node->next->prev = stack->tail;
        stack->tail->next = node;
        stack->tail = node;
    }
    stack->size++;
}

void    stack_pop(t_dstruct_list *stack, void (* node_deconstructor)(void *))
{
    t_dstruct_node *popped;

#ifndef DSTRUCT_PROTECT
    if (!stack || !stack->tail)
        return ;
#endif
    popped = stack->tail;
    stack->tail = stack->tail->prev;
    if (stack->tail)
        stack->tail->next = NULL;
    else
        stack->head = NULL;
    node_deconstructor(popped);
    stack->size--;
}