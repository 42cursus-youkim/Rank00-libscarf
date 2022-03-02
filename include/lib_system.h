#ifndef LIB_SYSTEM_H
# define LIB_SYSTEM_H

# include <stdlib.h>
# include "lib_string.h"

//@func
/*
** < alloc.c > */

void	*lib_memset(void *b, char c, int space);
void	*lib_bzero(void *ptr, int n);
void	*lib_calloc(size_t size, size_t count);
/*
** < write.c > */

int		lib_write(int fd, const t_string str);
int		lib_writes(int fd, t_string arr[]);
#endif