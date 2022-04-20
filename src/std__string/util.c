#include "std__string.h"
#include <stdlib.h>

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
