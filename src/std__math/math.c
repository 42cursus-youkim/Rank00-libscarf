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

int	math__digit_len(int num)
{
	int	result;

	result = 0;
	while (num)
	{
		num /= 10;
		result++;
	}
	return (result);
}
