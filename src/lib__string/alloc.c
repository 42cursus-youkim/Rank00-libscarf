#include <stdlib.h>
#include "lib__string.h"
#include "lib__system.h"

//	creates a new string, identical to src to heap and returns it.
t_string	str__new(const t_string src)
{
	t_i32		i;
	const t_i32	len = str__len(src);
	t_string	new;

	new = lib__calloc(sizeof(char), len);
	i = -1;
	while (++i < len)
		new[i] = src[i];
	return (new);
}

//	creates a string of length 0 in the heap and returns it.
t_string	str__new_empty(void)
{
	return (str__new(""));
}

//	deletes a string from the heap.
void	str__del(t_string this)
{
	free(this);
	this = NULL;
}
