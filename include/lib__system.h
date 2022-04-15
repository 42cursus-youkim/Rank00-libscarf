#ifndef LIB__SYSTEM_H
# define LIB__SYSTEM_H

# include "lib__types__num.h"
# include "lib__types__string.h"

//@func
/*
** < alloc.c > */

void	*lib__memset(void *b, char c, int space);
void	*lib__bzero(void *ptr, int n);
void	*lib__calloc(size_t size, size_t count);
/*
** < dalloc.c > */

void	lib__dealloc(void *ptr);
/*
** < write.c > */

int		lib__write(int fd, const t_string str);
int		lib__writes(int fd, t_string arr[]);
#endif