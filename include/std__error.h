#ifndef STD__ERROR_H
# define STD__ERROR_H

# include "std__types.h"

//@func
/*
** < error.c > */

void	std__panic__syscall(t_string category);
void	std__panic(t_string what);
#endif