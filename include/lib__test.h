#ifndef LIB__TEST_H
# define LIB__TEST_H

# include "lib__types__string.h"
# include "lib__types__num.h"

//@func
/*
** < assert.c > */

void	test__header(const t_string text);
void	test__subject(const t_string text);
void	test__assert(bool expr);
#endif