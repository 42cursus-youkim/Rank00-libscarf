#ifndef LIB__ERROR_H
# define LIB__ERROR_H

# include <errno.h>
# include "color.h"

typedef enum e_res
{
	OK,
	ERR = -1,
}	t_res;

//@func
/*
** < error.c > */

t_res	error_syscall(char *category);
#endif
