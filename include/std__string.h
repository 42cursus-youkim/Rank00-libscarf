#ifndef STD__STRING_H
# define STD__STRING_H

# include "std__error.h"
# include "std__types.h"
# include "std__types__error.h"

//@func
/*
** < alloc.c > */

t_string			str__new(t_string_ref from);
t_string			str__new_size(t_uint size);
void				str__delete(t_string *this_ptr);
/*
** < append.c > */

void				str__append(t_string *this_ptr, t_string_ref src);
/*
** < cmp.c > */

int					str__ncmp(t_string_ref s1, t_string_ref s2, int n);
bool				str__is_equal(t_string_ref s1, t_string_ref s2);
/*
** < convert.c > */

t_string			str__new_from_int(int num);
t_int_res			str__to_int(t_string_ref str);
/*
** < find.c > */

t_int_or_neg_as_err	str__find(t_string_ref this, t_string_ref other);
t_int_or_neg_as_err	str__find_from(t_string_ref this, t_string_ref other,
						t_i64 from);
/*
** < find_of.c > */

t_int_or_neg_as_err	str__find_first_of(t_string_ref this,
						t_string_ref charset);
t_int_or_neg_as_err	str__find_first_not_of(t_string_ref this,
						t_string_ref charset);
/*
** < index.c > */

t_u8				str__at(t_string_ref this, const int index);
bool				str__is_in(t_string_ref this, char c);
/*
** < slice.c > */

t_string			str__new_substr(t_string_ref str, t_uint start,
						t_int_or_neg_as_flag len);
/*
** < split.c > */

t_int_or_neg_as_err	str__count_of(t_string_ref str, t_string_ref other);
t_string			*str__new_split(t_string_ref str, t_string_ref delim);
/*
** < util.c > */

t_int_or_neg_as_err	str__len(t_string_ref this);
bool				str__is_empty(t_string_ref this);
#endif
