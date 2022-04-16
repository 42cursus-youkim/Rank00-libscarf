#include <stdlib.h>
#include "std__system.h"
#include "std__error.h"

//	returns ptr
void	*std__memset(void *b, char c, int space)
{
	int		i;
	char	*ptr;

	ptr = (char *)b;
	i = 0;
	while (i < space)
		ptr[i++] = c;
	return ((void *)ptr);
}

//	returns ptr set to 0
void	*std__bzero(void *ptr, int n)
{
	return (std__memset(ptr, '\0', n));
}

void	*std__calloc(size_t size, size_t count)
{
	char			*ptr;
	const size_t	allocated_space = size * (count + 1);

	ptr = malloc(allocated_space);
	if (!ptr)
	{
		std__panic__syscall("std__calloc");
		exit(EXIT_FAILURE);
	}
	return (std__bzero(ptr, allocated_space));
}
