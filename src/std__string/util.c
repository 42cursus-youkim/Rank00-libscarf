#include "std__string.h"
#include <stdlib.h>

/**
 * @brief NULL is also considered empty.
 */
bool	str__is_empty(t_const_string this)
{
	return (not this or str__len(this) == 0);
}
