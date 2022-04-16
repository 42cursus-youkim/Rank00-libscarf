#ifndef STD__MATH_H
# define STD__MATH_H

# include <stdbool.h>

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
int		math__digit_len(int num);
#endif