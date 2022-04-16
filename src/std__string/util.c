#include "std__string.h"

/**
 * @brief length of a string.
 *
 * @param this the string to get the length of.
 * @return ERR (-1) if the string is NULL, the length of the string otherwise.
 */
t_int_or_neg_as_err	str__len(t_string_ref this)
{
	int	i;

	if (!this)
		return (ERR);
	i = 0;
	while (this[i])
		i++;
	return (i);
}

bool	str__is_empty(t_string_ref this)
{
	return (str__len(this) == 0);
}
