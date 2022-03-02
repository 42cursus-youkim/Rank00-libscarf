#include "lib_string.h"
#include "lib_system.h"

t_string	str_new(const t_string src)
{
	int			i;
	t_string	new;

	i = str_len(src);
	new = lib_calloc(sizeof(char), i);
	while (--i >= 0)
		new[i] = src[i];
	return (new);
}
