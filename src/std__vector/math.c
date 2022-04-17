#include "std__vector.h"
#include <math.h>

t_vec	vec__add(t_vec* v1, t_vec* v2)
{
  return (t_vec){
      v1->x + v2->x,
      v1->y + v2->y,
  };
}

t_vec	vec__addx(t_vec* v1, double x)
{
	return (t_vec){
			v1->x + x,
			v1->y,
	};
}

t_vec vec__addy(t_vec* v1, double y)
{
	return (t_vec){
			v1->x,
			v1->y + y,
	};
}

t_vec	vec__rotate(t_vec* vec, double angle)
{
	return (t_vec){
		.x = vec->x * cos(angle) - vec->y * sin(angle),
		.y = vec->x * sin(angle) + vec->y * cos(angle),
	};
}
