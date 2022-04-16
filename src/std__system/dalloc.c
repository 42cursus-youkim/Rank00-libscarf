#include <stdlib.h>

// free pointer and set it to NULL
void	std__dealloc(void *ptr)
{
	free(ptr);
	ptr = NULL;
}
