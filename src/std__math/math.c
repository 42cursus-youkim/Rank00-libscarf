#include "std__math.h"
#include <math.h>
#include <stddef.h>

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

int	math__normalize(int num, t_irange range, t_irange map_range)
{
	int	result;
	int	map_len;
	int	num_len;

	result = 0;
	map_len = math__max(range.end - range.start, 1);
	num_len = math__max(map_range.end - map_range.start, 1);
	result = (num - range.start) * num_len / map_len;
	return (result);
}
