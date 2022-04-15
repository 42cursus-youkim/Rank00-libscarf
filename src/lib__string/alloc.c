#include "lib__string.h"
#include "lib__system.h"

//	creates a new string, identical to src to heap and returns it.
t_string	str__new(const t_string src)
{
	int			i;
	t_string	new;

	i = str_len(src);
	new = lib_calloc(sizeof(char), i);
	while (--i >= 0)
		new[i] = src[i];
	return (new);
}

//	creates a string of length 0 in the heap and returns it.
t_string	str__empty(void)
{
	return (str__new(""));
}

//	deletes a string from the heap.
void	str__del(t_string self)
{
	free(self);
	self = NULL;
}
