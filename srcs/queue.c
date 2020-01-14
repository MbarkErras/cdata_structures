#include "queue.h"

void    queue_enqueue(t_dstruct_list *queue, t_dstruct_node *node)
{
    stack_push(queue, node);
}

void    queue_dequeue(t_dstruct_list *queue, void (* node_deconstructor)(void *))
{
    t_dstruct_node *deqeued;

#ifndef DSTRUCT_PROTECT
    if (!queue || !queue->tail || !node_deconstructor)
        return ;
#endif
    deqeued = queue->head;
    queue->head = queue->head->next;
    if (queue->head)
        queue->head->prev = NULL;
    else
        queue->tail = NULL;
    node_deconstructor(deqeued->content);
    free(deqeued);
    queue->size--;
}