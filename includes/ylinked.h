/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylinked.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:22:56 by youkim            #+#    #+#             */
/*   Updated: 2021/12/07 18:28:47 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YLINKED_H
# define YLINKED_H

//	===== Linked List =====
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//	===== Deque =====
typedef struct s_dequenode
{
	int					num;
	struct s_dequenode	*upper;
	struct s_dequenode	*lower;
}	t_dequenode;

/*	head: uppermost
	tail: lowermost
*/
typedef struct s_deque
{
	int			size;
	t_dequenode	*head;
	t_dequenode	*tail;
}	t_deque;

//	@func
/*
** < alloc_ydeque.c > */

t_dequenode	*new_ydequenode(int num);
t_deque		*new_ydeque(int size, int nums[]);
void		del_ydeque(t_deque *deque);
void		ydeque_visualize(t_deque *deque);
/*
** < func_ydeque.c > */

void		ydeque_push(t_deque *deque, t_dequenode *new);
void		ydeque_push_back(t_deque *deque, t_dequenode *new);
t_dequenode	*ydeque_pop(t_deque *deque);
t_dequenode	*ydeque_pop_back(t_deque *deque);
/*
** < func_ylist.c > */

int			ylistlen(t_list *lst);
t_list		*ylistindex(t_list *lst, int index);
/*
** < new_ylist.c > */

t_list		*new_ylist(void *content);
#endif