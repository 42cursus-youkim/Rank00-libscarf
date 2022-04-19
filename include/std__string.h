#ifndef STD__STRING_H
# define STD__STRING_H

# include "std__error.h"
# include "std__types.h"
# include "std__types__error.h"

//@func
/*
** < alloc.c > */

t_string			str__new(t_const_string from);
t_string			str__new_size(t_uint size);
void				str__delete(t_string *this_ptr);
/*
** < append.c > */

void				str__append(t_string *this_ptr, t_const_string src);
/*
** < cmp.c > */

int					str__ncmp(t_const_string s1, t_const_string s2, int n);
bool				str__is_equal(t_const_string s1, t_const_string s2);
/*
** < convert.c > */

t_string			str__new_from_int(int num);
t_int_res			str__to_int(t_const_string str);
/*
** < find.c > */

t_int_or_neg_as_err	str__find(t_const_string this, t_const_string other);
t_int_or_neg_as_err	str__find_from(t_const_string this, t_const_string other,
						t_i64 from);
/*
** < find_of.c > */

t_int_or_neg_as_err	str__find_first_of(t_const_string this,
						t_const_string charset);
t_int_or_neg_as_err	str__find_first_not_of(t_const_string this,
						t_const_string charset);
/*
** < index.c > */

t_u8				str__at(t_const_string this, const int index);
bool				str__is_in(t_const_string this, char c);
/*
** < slice.c > */

t_string			str__new_substr(t_const_string str, t_uint start,
						t_int_or_neg_as_flag len);
/*
** < split.c > */

t_int_or_neg_as_err	str__count_of(t_const_string str, t_const_string other);
t_string			*str__new_split(t_const_string str, t_const_string delim);
/*
** < util.c > */

t_int_or_neg_as_err	str__len(t_const_string this);
bool				str__is_empty(t_const_string this);
#endif
