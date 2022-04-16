#include <stdlib.h>
#include "std__system.h"
#include "std__error.h"

/**
 * @brief allocate memory with all data set to 0. always succeeds (or panic).
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

	ptr = malloc(allocated_space);
	if (!ptr)
		std__panic__syscall("std__alloc");
	return (std__bzero(ptr, allocated_space));
}

/**
 * @brief allocate memory that is NULL-terminated. always succeeds (or panic).
 *
 * iterating over the allocated memory like [++arr] is undefined behavior.
 * use index or std__calloc() to iterate over the allocated memory.
 *
 * @param count count of elements to allocate. count + 1 will be allocated,
 * 				and will be NULL-terminated.
 * 				use std__calloc() to initialize every byte to 0.
 * @param size size of each element. use sizeof() to get size of a type.
 * @return pointer to memory that is NULL-terminated.
 */
void	*std__allocate(size_t count, size_t size)
{
	void			*ptr;
	const size_t	allocated_space = size * (count + 1);

	ptr = malloc(allocated_space);
	if (!ptr)
		std__panic__syscall("std__alloc");
	std__bzero(ptr + size * count, size);
	return (ptr);
}

/** @brief free pointer and set it to NULL */
void	std__dealloc(void **ptr_ptr)
{
	free(*ptr_ptr);
	*ptr_ptr = NULL;
}
