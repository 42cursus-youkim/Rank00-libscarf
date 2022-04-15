#ifndef LIB__ERROR_H
# define LIB__ERROR_H

# include "lib__types.h"

//@func
/*
** < error.c > */

void	lib__oppanic__syscall(t_string category);
void	lib__panic(t_string what);
#endif