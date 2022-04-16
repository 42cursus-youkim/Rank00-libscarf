#ifndef STD__VECTOR_H
# define STD__VECTOR_H

typedef struct s_vec
{
	float	x;
	float	y;
}	t_vec;

//@func
/*
** < math.c > */

t_vec	vec__add(t_vec *v1, t_vec *v2);
#endif