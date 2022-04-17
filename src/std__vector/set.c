#include "std__vector.h"
#include "std__error.h"

void	vector__set(t_std__vector *v, size_t index, t_std__vector_item item)
{
	if (index >= v->size)
		std__panic__index("vector__set", index, v->size);

	v->items[index] = item;
}
