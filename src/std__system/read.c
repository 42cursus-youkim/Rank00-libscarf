#include <unistd.h>
#include "std__system.h"
#include "std__string.h"


#include <stdlib.h>
#include <stdio.h>
#include "std__color.h"
/**
 * @brief same as read but last byte is NULL terminated.
 *
 * @param fd file descriptor to read from
 * @param buffer buffer to read into. Must be at least size+1 bytes long.
 * @param size number of bytes to read.
 * @return int
 */
int	std__read(t_fd fd, char *buffer, t_uint size)
{
	int	len;

	len = read(fd, buffer, size);
	if (len > 0)
		buffer[len] = '\0';
	return (len);
}

static int	str__append_from_read(t_string *this, t_fd fd)
{
	int		len;
	char	buffer[BUFFER_SIZE + 1];

	len = std__read(fd, buffer, BUFFER_SIZE);
	if (len == ERR)
		std__panic__syscall("read");
	else if (len > 0)
		str__append(this, buffer);
	return (len);
}

bool	read__is_eof(int len)
{
	return (len == 0);
}

char	*std__new_readfile__line(int fd)
{
	int				at;
	int				len;
	t_string		line;
	t_string		tmp;
	static t_string	storage = NULL;
	static bool		done = false;

	if (done)
		return (NULL);
	if (not storage)
		storage = str__new_size(0);
	while (true)
	{
		at = str__find(storage, "\n");
		if (at == ERR)
		{
			len = str__append_from_read(&storage, fd);
			if (len == ERR)
				std__panic__syscall("read");
			else if (read__is_eof(len))
			{
				if (storage)
					str__delete(&storage);
				done = true;
				return (NULL);
			}
		}
		else
		{
			line = str__new_substr(storage, 0, at + 1);
			tmp = str__new_substr(storage, at + 1, -1);
			str__replace(&storage, tmp);
			return (line);
		}
	}
}
