#include <unistd.h>
#include "std__system.h"
#include "std__string.h"

//	same to write() but without annoying length
int	std__write(int fd, t_string_ref str)
{
	return (write(fd, str, str__len(str)));
}

//	write multiple strings
int	std__writes(int fd, t_string_ref arr[])
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (arr[++i])
		res += std__write(fd, arr[i]);
	return (res);
}
