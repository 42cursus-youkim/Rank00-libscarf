#ifndef STD__VECTOR_H
# define STD__VECTOR_H

# include "std__types__vector.h"

//@func
/*
** < alloc.c > */

void	vector__init(t_std__vector *v, t_destructor destructor);
void	vector__init_from(t_std__vector *v,
			t_destructor destructor,t_std__vector_item initializer_list[]);
void	vector__impl__delete_items(t_destructor destructor,
			t_std__vector_item *items, t_u32 size);
void	vector__impl__resize(t_std__vector *v, t_u32 new_capacity);
void	vector__deinit(t_std__vector *v);
/*
** < push.c > */

void	vector__push_back(t_std__vector *v, t_std__vector_item item);
/*
** < set.c > */

void	vector__set(t_std__vector *v, size_t index, t_std__vector_item item);
/*
** < util.c > */

int		vector__size(t_std__vector *v);
#endif
