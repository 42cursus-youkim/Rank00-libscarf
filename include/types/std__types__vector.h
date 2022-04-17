#ifndef STD__TYPES__VECTOR_H
# define STD__TYPES__VECTOR_H

# include "std__types.h"

typedef struct s_lnode
{
	void			*data;
	struct s_list	*next;
}	t_lnode;

typedef struct s_vector
{
	void			**items;
	size_t			capacity;
	size_t			size;
	t_destructor	destructor;
}	t_vector;

#endif
