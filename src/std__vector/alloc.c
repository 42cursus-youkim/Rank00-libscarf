#include <stdio.h>
#include <stdlib.h>
#include "std__system.h"
#include "std__vector.h"
#include "std__color.h"
#include "std__error.h"

void	vector__init(t_std__vector *v, t_destructor destructor)
{
	v->capacity = VECTOR__INIT_CAPACITY;
	v->size = 0;
	v->items = std__allocate(v->capacity, sizeof(t_std__vector_item));
	v->destructor = destructor;
}

void	vector__init_from(t_std__vector *v, t_destructor destructor,
		t_std__vector_item initializer_list[])
{
	t_i64	i;

	vector__init(v, destructor);
	i = -1;
	while (initializer_list[++i])
		vector__push_back(v, initializer_list[i]);
}

void	vector__impl__delete_items(
	t_destructor destructor, t_std__vector_item *items, t_u32 size)
{
	t_u32	i;

	i = -1;
	while (++i < size)
		if (items[i])
			destructor(items[i]);
	free(items);
}

void	vector__impl__resize(t_std__vector *v, t_u32 new_capacity)
{
	t_std__vector_item	*new_items;

	if (VECTOR__DEBUG)
		printf(HCYN "[vector__resize]" YEL "%u -> %u\n" END,
			v->capacity, new_capacity);
	new_items = std__allocate(new_capacity, sizeof(t_std__vector_item));
	std__memcpy(new_items, v->items, v->size * sizeof(t_std__vector_item));
	vector__impl__delete_items(v->destructor, v->items, v->capacity);
	v->items = new_items;
	v->capacity = new_capacity;
}

void	vector__deinit(t_std__vector *v)
{
	vector__impl__delete_items(v->destructor, v->items, v->size);
}
