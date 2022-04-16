#include <stddef.h>
#include <math.h>

inline int	math__max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

inline int	math__min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
