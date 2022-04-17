#ifndef STD__VECTOR_H
# define STD__VECTOR_H

typedef struct s_vec {
  double x;
  double y;
} t_vec;

typedef struct s_ivec {
  int x;
  int y;
} t_ivec;

//@func
/*
** < math.c > */

t_vec	vec__add(t_vec* v1, t_vec* v2);
t_vec	vec__addx(t_vec* v1, double x);
t_vec	vec__addy(t_vec* v1, double y);
t_vec	vec__rotate(t_vec* vec, double angle);
#endif
