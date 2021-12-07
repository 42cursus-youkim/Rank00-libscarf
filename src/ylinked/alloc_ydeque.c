/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_ydeque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:47:10 by youkim            #+#    #+#             */
/*   Updated: 2021/12/07 19:10:09 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dequenode	*new_ydequenode(int num)
{
	t_dequenode	*node;

	node = ymalloc(sizeof(t_dequenode));
	node->num = num;
	node->lower = NULL;
	node->upper = NULL;
	return (node);
}

/*	create new double-linked list with head and tail.
	first argument goes to head(top)!
	TODO: tail
*/
t_deque	*new_ydeque(int size, int nums[])
{
	t_deque	*deque;

	if (size < 1)
		yerror("new_ydeque", "size is less than 1");
	deque = ymalloc(sizeof(t_deque));
	deque->size = 0;
	while (--size >= 0)
		ydeque_push(deque, new_ydequenode(nums[size]));
	return (deque);
}

void	del_ydequenode(t_dequenode *node)
{
	printf("freed node with num: %d\n", node->num);
	node->lower = NULL;
	node->upper = NULL;
	free(node);
}

// void	del_ydeque(t_deque *deque)
// {
// 	t_dequenode	*curs;

// 	if (!deque)
// 		yerror("del_ydeque", "deque is NULL");
// 	curs = deque->head;
// 	while (curs->head != NULL)
// 	{
// 		curs = deque->head;
// 	}
// 	free(deque);
// }

void	ydeque_visualize(t_deque *deque)
{
	int			i;
	t_dequenode	*curs;

	if (!deque)
		yerror("ydeque_print", "deque is NULL");
	printf("deque size: %d\n", deque->size);
	i = 0;
	curs = deque->head;
	while (curs->lower)
	{
		printf("%d: %d\n", i++, curs->num);
		curs = curs->lower;
	}
	printf("%d: %d\n", i, curs->num);
}
