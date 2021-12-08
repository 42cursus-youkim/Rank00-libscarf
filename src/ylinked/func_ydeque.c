/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ydeque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:00:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/08 13:28:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	push new node to uppermost
void	ydeque_push(t_deque *deque, t_dequenode *new)
{
	if (new == NULL)
		yerror("ydeque_push", "node trying to push does not exsist");
	if (deque->head == NULL)
	{
		deque->head = new;
		deque->tail = new;
	}
	else
	{
		new->upper = deque->tail;
		new->lower = deque->head;
		deque->head->upper = new;
		deque->head = new;
		deque->tail->lower = new;
	}
	deque->size++;
}

//	pop uppermost node, returns pointer to it
t_dequenode	*ydeque_pop(t_deque *deque)
{
	t_dequenode	*curs;

	if (deque->size == 0)
		yerror("ydeque_pop", "deque is empty");
	curs = deque->head;
	deque->head = curs->lower;
	curs->lower = NULL;
	curs->upper = NULL;
	deque->head->upper = deque->tail;
	deque->tail->lower = deque->head;
	deque->size--;
	return (curs);
}
