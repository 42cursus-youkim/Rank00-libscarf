#ifndef STD__TYPES__MATH_H
#define STD__TYPES__MATH_H

#include "std__types.h"

typedef struct s_vec {
  double x;
  double y;
} t_vec;

typedef struct s_ivec {
  int x;
  int y;
} t_ivec;

typedef struct s_irange {
  int start;
  int end;
} t_irange;

typedef struct s_sizevec {
  t_uint width;
  t_uint height;
} t_sizevec;
#endif
