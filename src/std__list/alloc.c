#include "std__types__list.h"
#include "std__system.h"

/**
 * @brief Allocate a new list node. meant to be a internal function.
 */
t_lnode	*std__list__new_node(void *data)
{
	t_lnode	*node;

	node = std__allocate(1, sizeof(t_lnode));
	node->next = NULL;
	node->data = data;
	return (node);
}

/**
 * @brief
 *
 * @param data
 * @return t_list*
 */
t_list	*std__list__new(void *data, t_destructor destructor)
{
	t_list	*list;

	list = std__allocate(1, sizeof(t_list));
	list->head = std__list__new_node(data);
	list->size = 0;
	return (list);
}

void	std__list__delete(t_list *list)
{
	t_list	*curs;

	curs = list;
	while (curs)
	{
		list = list->next;
		std__(curs);
		curs = list;
	}
}
