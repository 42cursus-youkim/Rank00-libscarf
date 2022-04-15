#include <stdlib.h>

// free pointer and set it to NULL
void	lib__dealloc(void *ptr)
{
	free(ptr);
	ptr = NULL;
}
