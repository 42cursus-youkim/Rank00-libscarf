#include <stdlib.h>
#include "lib__system.h"
#include "lib__error.h"

//	returns ptr
void	*lib__memset(void *b, char c, int space)
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
void	*lib__bzero(void *ptr, int n)
{
	return (lib__memset(ptr, '\0', n));
}

void	*lib__calloc(size_t size, size_t count)
{
	char			*ptr;
	const size_t	allocated_space = size * (count + 1);

	ptr = malloc(allocated_space);
	if (!ptr)
	{
		lib__error__syscall("lib__calloc");
		exit(EXIT_FAILURE);
	}
	return (lib__bzero(ptr, allocated_space));
}
