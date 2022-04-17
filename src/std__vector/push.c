#include "std__vector.h"

void	vector__push_back(t_std__vector *v, t_std__vector_item item)
{
	if (v->size == v->capacity)
		vector__impl__resize(v, v->capacity * VECTOR__DEFAULT_GROW_FACTOR);
	v->items[v->size] = item;
	v->size++;
}
