#ifndef LIB__STRING_H
# define LIB__STRING_H

# include "lib__error.h"
# include "lib__types.h"

//@func
/*
** < alloc.c > */

t_string	str__new(const t_string from);
void		str__del(t_string this);
/*
** < cmp.c > */

int			str__cmp(const t_string s1, const t_string s2, int n);
bool		str__is_equal(const t_string s1, const t_string s2);
/*
** < index.c > */

char		str__at(const t_string this, const t_uint index);
/*
** < util.c > */

int			str__len(const t_string this);
#endif