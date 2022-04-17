#ifndef STD__TYPES__DEQUE_H
# define STD__TYPES__DEQUE_H

typedef struct s_dnode
{
	void			*data;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}	t_dnode;

typedef struct t_deque
{
	t_dnode			*head;
	t_dnode			*tail;
	size_t			size;
	t_destructor	destructor;
}	t_deque;

#endif
