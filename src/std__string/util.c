#include "std__string.h"

/**
 * @brief length of a string.
 *
 * @param this the string to get the length of.
 * @return ERR (-1) if the string is NULL, the length of the string otherwise.
 */
t_non_neg_int_or_err	str__len(t_string_ref this)
{
	int	i;

	if (!this)
		return (ERR);
	i = 0;
	while (this[i])
		i++;
	return (i);
}
