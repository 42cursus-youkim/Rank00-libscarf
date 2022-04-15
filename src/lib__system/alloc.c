#include "lib__system.h"

//	returns ptr
void	*lib_memset(void *b, char c, int space)
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
void	*lib_bzero(void *ptr, int n)
{
	return (lib_memset(ptr, '\0', n));
}

void	*lib_calloc(size_t size, size_t count)
{
	char			*ptr;
	const size_t	allocated_space = size * (count + 1);

	ptr = malloc(allocated_space);
	if (!ptr)
	{
		error_syscall("lib__calloc");
		exit(EXIT_FAILURE);
	}
	return (lib_bzero(ptr, allocated_space));
}
