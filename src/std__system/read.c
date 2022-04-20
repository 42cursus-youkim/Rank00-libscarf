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

	// std__bzero(buffer, size + 1);
	len = read(fd, buffer, size);
	if (len > 0)
		buffer[len] = '\0';
	return (len);
}

int	where_newline(char *backup)
{
	int i;

	i = -1;
	while (backup[++i])
		if (backup[i] == '\n')
			return (i);
	return (-1);
}

int	pop_line(char **backup, char **line, int cut_where)
{
	char	*temp;

	(*backup)[cut_where] = '\0';
	*line = ft_strdup(*backup);
	if (!ft_strlen(*backup + cut_where + 1))
	{
		free(*backup);
		*backup = 0;
	}
	else
	{
		temp = ft_strdup(*backup + cut_where + 1);
		free(*backup);
		*backup = temp;
	}
	return (1);
}

char	*result(char **backup, char **line)
{
	int	cut_where;

	if (*backup && (cut_where = where_newline(*backup)) >= 0)
		return (pop_line(backup, line, cut_where));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			len;
	int			cut_where;
	char		buffer[BUFFER_SIZE + 1];
	static char	*backup[OPEN_MAX];

	if ((fd < 0 || OPEN_MAX <= fd) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while (true)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len <= 0)
			break ;
		str__append(&backup[fd], buffer);
		cut_where = where_newline(backup[fd]);
		if (cut_where >= 0)
			return (pop_line(&backup[fd], line, cut_where));
	}
	if (len < 0)
		return (-1);
	return (result(&backup[fd], line));
}
