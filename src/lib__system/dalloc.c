#include <stdlib.h>

void	lib__dealloc(void *ptr)
{
	free(ptr);
	ptr = NULL;
}
