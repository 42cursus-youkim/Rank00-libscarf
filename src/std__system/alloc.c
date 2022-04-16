#include <stdlib.h>
#include "std__system.h"
#include "std__error.h"

/** @brief dynamic memory allocation. always succeeds.
 *	@return pointer to allocated memory. it is NEVER NULL. */
void	*std__calloc(size_t count, size_t size)
{
	char			*ptr;
	const size_t	allocated_space = size * (count + 1);

	ptr = malloc(allocated_space);
	if (!ptr)
		std__panic__syscall("std__calloc");
	return (std__bzero(ptr, allocated_space));
}

/** @brief free pointer and set it to NULL */
void	std__dealloc(void *ptr)
{
	free(ptr);
	ptr = NULL;
}
