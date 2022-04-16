#include <stdio.h>
#include "std__error.h"
#include "std__string.h"

/** @brief	python-like indexing. crash if the index is out of bounds.
 *  @param	this	the string to index.
 *  @param	index	the index to index. can be negative.
 *  @return	the character at the index.
*/
t_u8	str__at(t_string_ref this, const int index)
{
	if (index >= 0)
	{
		if (index >= str__len(this))
			std__panic__index("str__at", this, index);
		return (this[index]);
	}
	else
	{
		if (-index > str__len(this))
			std__panic__index("str__at", this, index);
		return (this[str__len(this) + index]);
	}
}

bool	str__is_in(t_string_ref this, char c)
{
	t_uint	i;

	i = -1;
	while (this[++i])
		if (this[i] == c)
			return (true);
	return (false);
}

