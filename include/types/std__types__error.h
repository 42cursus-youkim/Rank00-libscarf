#ifndef STD__TYPES__ERROR_H
# define STD__TYPES__ERROR_H

typedef int	t_non_neg_int_or_err;

typedef enum e_res
{
	OK,
	ERR = -1,
	UNSET = -2,
}	t_res;

typedef struct s_int_res
{
	t_res	err;
	int		num;
}	t_int_res;

#endif
