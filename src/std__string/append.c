#include "std__string.h"
#include "std__system.h"
#include <stdio.h>

static int	std__strcpy(t_string this, t_const_string src)
{
	int	i;

	i = -1;
	while (src[++i])
		this[i] = src[i];
	this[i] = '\0';
	return (str__len(src));
}

/**
 * @brief append a string to another.
 *
 * @param this address to the string that would be modified.
 * @param to_add the constant string reference to add.
 */
int	str__append(t_string *this_ptr, t_const_string src)
{
	t_string	new;
	const int	org_len = str__len(*this_ptr);
	const int	src_len = str__len(src);
	const int	new_len = org_len + src_len;

	new = std__allocate(new_len, sizeof(char));
	std__strcpy(new, *this_ptr);
	std__strcpy(new + org_len, src);
	str__delete(this_ptr);
	*this_ptr = new;
	return (new_len);
}
