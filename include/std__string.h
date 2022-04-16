#ifndef STD__STRING_H
# define STD__STRING_H

# include "std__error.h"
# include "std__types.h"

//@func
/*
** < alloc.c > */

t_string				str__new(t_string_ref from);
void					str__delete(t_string this);
/*
** < append.c > */

void					str__append(t_string *this_ptr, t_string_ref src);
/*
** < cmp.c > */

int						str__ncmp(t_string_ref s1, t_string_ref s2, int n);
bool					str__is_equal(t_string_ref s1, t_string_ref s2);
/*
** < convert.c > */

t_string				str__new_from_int(int num);
/*
** < find.c > */

t_non_neg_int_or_err	str__find_first_of(t_string_ref this,
							t_string_ref charset);
t_non_neg_int_or_err	str__find(t_string_ref this, t_string_ref other);
/*
** < index.c > */

t_u8					str__at(t_string_ref this, const t_uint index);
bool					str__is_in(t_string_ref this, char c);
/*
** < util.c > */

t_non_neg_int_or_err	str__len(t_string_ref this);
#endif