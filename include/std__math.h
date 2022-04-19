#ifndef STD__MATH_H
#define STD__MATH_H

#include <stdbool.h>
#include "std__types__math.h"

//@func
/*
** < check_char.c > */

bool	is_upper(char c);
bool	is_lower(char c);
bool	is_alpha(char c);
bool	is_alnum(char c);
bool	is_whitespace(char c);
/*
** < check_num.c > */

bool	is_digit(char c);
bool	is_overflow(int num, int sign);
/*
** < math.c > */

int		math__max(int a, int b);
int		math__min(int a, int b);
int		math__clamp(int n, t_irange range);
int		math__digit_len(int num);
int		math__normalize(int num, t_irange range, t_irange map_range);
/*
** < vector.c > */

t_vec	vec__add(t_vec *v1, t_vec *v2);
void	vec__add_assign(t_vec *v1, t_vec *v2);
t_vec	vec__rotate(t_vec *vec, double angle);
void	vec__rotate_assign(t_vec *vec, double angle);
bool	vec__ivec_eq(t_ivec *v1, t_ivec *v2);
#endif
