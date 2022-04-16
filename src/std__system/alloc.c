#include <stdlib.h>
#include "std__system.h"
#include "std__error.h"

/**
 * @brief dynamic memory allocation. with all data set to 0. always succeeds.
 *
 * @param count count of elements to allocate. count + 1 will be allocated,
 * 				with its last byte NULL-terminated.
 * @param size size of each element. use sizeof() to get size of a type.
 * @return pointer to allocated memory. it is NEVER NULL.
 */
void	*std__calloc(size_t count, size_t size)
{
	char			*ptr;
	const size_t	allocated_space = size * (count + 1);

	ptr = std__malloc(count, size);
	return (std__bzero(ptr, allocated_space));
}

/**
 * @brief dynamic memory allocation. always succeeds.
 *
 * @param count count of elements to allocate. count + 1 will be allocated,
 * 				with its last byte NULL-terminated.
 * @param size size of each element. use sizeof() to get size of a type.
 * @return void*
 */
void	*std__malloc(size_t count, size_t size)
{
	void			*ptr;
	const size_t	allocated_space = size * (count + 1);

	ptr = malloc(allocated_space);
	if (!ptr)
		std__panic__syscall("std__malloc");
	return (ptr);
}

/** @brief free pointer and set it to NULL */
void	std__dealloc(void **ptr_ptr)
{
	free(*ptr_ptr);
	*ptr_ptr = NULL;
}
