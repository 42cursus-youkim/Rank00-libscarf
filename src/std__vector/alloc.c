#include <stdio.h>
#include <stdlib.h>
#include "std__system.h"
#include "std__vector.h"
#include "std__color.h"
#include "std__error.h"

void	vector__init(t_std__vector *v)
{
	v->capacity = VECTOR__INIT_CAPACITY;
	v->size = 0;
	v->items = std__allocate(v->capacity, sizeof(t_std__vector_item));
}

void	vector__impl__resize(t_std__vector *v, t_u32 new_capacity)
{
	t_std__vector_item	*new_items;

	if (VECTOR__DEBUG)
		printf(HCYN "[vector__resize]" YEL "%u -> %u\n" END,
			v->capacity, new_capacity);
	new_items = std__allocate(new_capacity, sizeof(t_std__vector_item));
	std__memcpy(new_items, v->items, v->size * sizeof(t_std__vector_item));
	free(v->items);
	v->items = new_items;
	v->capacity = new_capacity;
}

void	vector__impl__delete_items(t_std__vector *v)
{
	t_i64	i;

	if (v->destructor)
	{
		i = -1;
		while (++i < v->size)
			v->destructor(v->items[i]);
	}
	free(v->items);
	v->items = NULL;
}

#include <assert.h>
void	vector__delete(t_std__vector *v)
{
	vector__impl__delete_items(v);
	assert(v->items == NULL);
}
