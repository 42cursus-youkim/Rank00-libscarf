#ifndef LIB_SYSTEM_H
# define LIB_SYSTEM_H

# include <stdlib.h>
# include "lib_string.h"

//@func
/*
** < alloc.c > */

void	*ft_memset(void *b, char c, int space);
void	*ft_bzero(void *ptr, int n);
void	*ft_calloc(size_t size, size_t count);
/*
** < write.c > */

int		ft_write(int fd, const t_string str);
int		ft_writes(int fd, t_string arr[]);
#endif