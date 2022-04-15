#ifndef LIB__STRING_H
# define LIB__STRING_H

# include <stdlib.h>
# include <stdbool.h>
# include "lib__error.h"
# include "lib__types__num.h"
# include "lib__types__string.h"

//@func
/*
** < alloc.c > */

t_string	str__new(const t_string src);
t_string	str__empty(void);
void		str__del(t_string self);
/*
** < cmp.c > */

int			str__cmp(const t_string s1, const t_string s2, const size_t n);
bool		str__is_equal(const t_string s1, const t_string s2);
/*
** < util.c > */

int			str__len(const t_string this);
#endif