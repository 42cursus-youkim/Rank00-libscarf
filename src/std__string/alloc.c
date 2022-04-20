#include "std__string.h"
#include "std__system.h"
#include <stdlib.h>

/**
 * @brief create a new string from a given string.
 *
 * @param from
 * @return t_string
 */
t_string	str__new(t_const_string from)
{
	t_i32		i;
	t_string	new;
	const t_i32	len = str__len(from);

	new = str__new_size(len);
	i = -1;
	while (++i < len)
		new[i] = from[i];
	return (new);
}

/**
 * @brief create a uninitialized string of given length.
 *
 * @param size
 * @return t_string
 */
t_string	str__new_size(t_uint size)
{
	t_string	new;

	new = std__calloc(size, sizeof(char));
	return (new);
}

/**
 * @brief create a new string by moving other. other is freed.
 *
 * @param this
 * @param other
 */
t_string	str__new_move(t_string *other)
{
	t_string	new;

	new = str__new(*other);
	str__delete(other);
	return (new);
}

/**
 * @brief deletes a string and set it to NULL.
 *
 * @param this the string to delete.
 */
void	str__delete(t_string *this_ptr)
{
	std__dealloc((void **)this_ptr);
}
