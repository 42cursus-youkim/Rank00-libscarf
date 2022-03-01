#include "lib_system.h"

int	ft_write(int fd, const t_string str)
{
	return (write(fd, str, str_len(str)));
}

//	write multiple strings
int	ft_writes(int fd, t_string arr[])
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (arr[++i])
		res += ft_write(fd, arr[i]);
	return (res);
}
