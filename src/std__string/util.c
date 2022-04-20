#include "std__string.h"
#include <stdlib.h>

/**
 * @brief length of a string.
 *
 * @param this the string to get the length of.
 * @return ERR (-1) if the string is NULL, the length of the string otherwise.
 */
t_int_or_neg_as_err	str__len(t_const_string this)
{
	int	i;

	if (!this)
		return (ERR);
	i = 0;
	while (this[i])
		i++;
	return (i);
}

/**
 * @brief NULL is also considered empty.
 */
bool	str__is_empty(t_const_string this)
{
	return (not this or str__len(this) == 0);
}

/**
 * @brief free this and replace with address of other. for temporary objects.
 *
 * @param other address to replace.
 */
void	str__replace(t_string *this, t_string other)
{
	free(*this);
	*this = other;
}

/**
 * @brief free this, move other -> this, make other's address NULL
 */
void	str__move(t_string *this, t_string *other)
{
	str__replace(this, *other);
	*other = NULL;
}

void	str__merge(t_string *this, t_string *other)
{
	str__append(this, *other);
	str__delete(other);
}
