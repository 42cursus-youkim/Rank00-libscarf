#include "std__vector.h"

t_vec	vec__add(t_vec *v1, t_vec *v2)
{
	const t_vec	res = {
		v1->x + v2->x,
		v1->y + v2->y,
	};

	// res.x = v1->x + v2->x;
	// res.y = v1->y + v2->y;
	return (res);
}
