#include <stdlib.h>
#include "std__string.h"
#include "std__system.h"

/**
 * @brief create a new string from a given string.
 *
 * @param from
 * @return t_string
 */
t_string	str__new(t_string_ref from)
{
	t_i32		i;
	t_string	new;
	const t_i32	len = str__len(from);

	new = std__calloc(len, sizeof(char));
	i = -1;
	while (++i < len)
		new[i] = from[i];
	return (new);
}

/**
 * @brief deletes a string and set it to NULL.
 *
 * @param this the string to delete.
 */
void	str__delete(t_string this)
{
	free(this);
	this = NULL;
}
