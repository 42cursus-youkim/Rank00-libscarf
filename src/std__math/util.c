#include "std__types.h"

int	math__digits(int num)
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
