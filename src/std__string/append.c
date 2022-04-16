#include "std__string.h"
#include "std__system.h"

/**
 * @brief append a string to another.
 *
 * @param this address to the string that would be modified.
 * @param to_add the constant string reference to add.
 */
void	str__append(t_string *this_ptr, t_string_ref src)
{
	t_i32		i;
	t_string	new;
	const int	old_len = str__len(*this_ptr);
	const int	src_len = str__len(src);
	const int	new_len = old_len + src_len;

	new = std__allocate(new_len, sizeof(char));
	i = -1;
	while (++i < old_len)
		new[i] = (*this_ptr)[i];
	i = -1;
	while (++i < src_len)
		new[old_len + i] = src[i];
}
