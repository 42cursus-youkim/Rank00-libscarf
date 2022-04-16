#include <stddef.h>
#include <math.h>

int	math__max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	math__min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
