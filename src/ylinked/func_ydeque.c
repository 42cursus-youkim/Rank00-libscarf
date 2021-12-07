/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ydeque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:00:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/07 19:11:33 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	push new node to uppermost
void	ydeque_push(t_deque *deque, t_dequenode *new)
{
	if (!new)
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

//	pop uppermost node and returns pointer to it
void	ydeque_pop(t_deque *deque)
{
	t_dequenode	*curs;

	if (deque->size == 0)
		yerror("ydeque_pop", "deque is empty");
	curs = deque->head;
	deque->head = curs->upper;
	deque->head->lower = NULL;
	deque->size--;
	free(curs);
}
