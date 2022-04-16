#ifndef STD__SYSTEM_H
# define STD__SYSTEM_H

# include "std__types.h"

//@func
/*
** < alloc.c > */

void	*std__memset(void *b, char c, int space);
void	*std__bzero(void *ptr, int n);
void	*std__calloc(size_t size, size_t count);
/*
** < dalloc.c > */

void	std__dealloc(void *ptr);
/*
** < write.c > */

int		std__write(int fd, const t_string str);
int		std__writes(int fd, t_string arr[]);
#endif