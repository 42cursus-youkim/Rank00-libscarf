#include <unistd.h>
#include "lib__system.h"
#include "lib__string.h"

//	same to write() but without annoying length
int	lib__write(int fd, const t_string str)
{
	return (write(fd, str, str__len(str)));
}

//	write multiple strings
int	lib__writes(int fd, t_string arr[])
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (arr[++i])
		res += lib__write(fd, arr[i]);
	return (res);
}
