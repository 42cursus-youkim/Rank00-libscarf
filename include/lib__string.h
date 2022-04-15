#ifndef LIB__STRING_H
# define LIB__STRING_H

# include <stdlib.h>
# include "lib__error.h"

typedef char *	t_string;

//@func
/*
** < new.c > */

t_string	str_new(const t_string src);
/*
** < util.c > */

int			str_len(const t_string str);
#endif
