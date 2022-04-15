#include <stdlib.h>
#include "lib__string.h"
#include "lib__system.h"

//	creates a new string, identical to src to heap and returns it.
t_string	str__new(const t_string from)
{
	t_i32		i;
	t_string	new;
	const t_i32	len = str__len(from);

	new = lib__calloc(sizeof(char), len);
	i = -1;
	while (++i < len)
		new[i] = from[i];
	return (new);
}

//	deletes a string from the heap.
void	str__del(t_string this)
{
	free(this);
	this = NULL;
}
