#include "lib_string.h"

int	str_len(const t_string str)
{
	int	i;

	if (!str)
		return (ERR);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
