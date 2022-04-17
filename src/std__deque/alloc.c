#include <stdlib.h>
#include "std__types__deque.h"
#include "std__system.h"

/**
 * @brief Allocate a new deque node. meant to be a internal function.
 */
t_dnode	*std__deque__new_node(void *data)
{
	t_dnode	*node;

	node = std__allocate(1, sizeof(t_dnode));
	node->next = NULL;
	node->data = data;
	return (node);
}

/**
 * @brief
 *
 * @param data
 * @return t_deque*
 */
t_deque	*std__deque__new(void *data, t_destructor destructor)
{
	t_deque	*deque;

	deque = std__allocate(1, sizeof(t_deque));
	deque->head = std__deque__new_node(data);
	deque->size = 0;
	deque->destructor = destructor;
	return (deque);
}

void	std__dnode__delete(t_dnode **node_ptr, t_destructor destructor)
{
	if (destructor)
		destructor((*node_ptr)->data);
	free((*node_ptr));
	*node_ptr = NULL;
}

void	std__deque__delete(t_deque *deque)
{
	t_dnode	*curs;

	curs = deque->head;
	while (curs)
	{
		curs = curs->next;
		
	}
}
