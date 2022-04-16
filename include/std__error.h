#ifndef STD__ERROR_H
# define STD__ERROR_H

# include "std__types.h"

//@func
/*
** < panic.c > */

void	std__panic__syscall(t_string_ref category);
void	std__panic(t_string_ref what);
void	std__panic__index(t_string what, int index);
#endif