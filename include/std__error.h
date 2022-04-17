#ifndef STD__ERROR_H
# define STD__ERROR_H

# include "std__types.h"

//@func
/*
** < panic.c > */

void	std__panic_write_internal(t_string_ref arr[]);
void	std__panic__syscall(t_string_ref category);
void	std__panic(t_string_ref what);
void	std__panic__null(t_string_ref where);
/*
** < panic__index.c > */

void	std__panic__index__string(t_string_ref where, t_string_ref what,
			int index, int size);
void	std__panic__index(t_string_ref where, int attemped_index, int size);
#endif
