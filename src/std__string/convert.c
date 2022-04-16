#include "std__math.h"
#include "std__string.h"
#include "std__system.h"

t_string	str__new_from_int(int num)
{
	t_string	str;
	int			digit;

	if (num == 0)
		return (str__new("0"));
	digit = math__digit_len(num);
	if (num < 0)
		digit++;
	str = std__calloc(sizeof(char), digit);
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[--digit] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}

// t_int_res	str__to_int(t_string_ref str, int *n)
// {
// 	int		i;
// 	int		sign;
// 	t_i64	num;
// 	t_i64	temp;

// 	i = 0;
// 	num = 0;
// 	sign = 1;
// 	if (!str)
// 		return ((t_int_res){ERR, UNSET});
// 	while (ft_strchr_i("\t\n\v\f\r ", str[i]) >= 0)
// 		i++;
// 	if (ft_strchr_i("-+", str[i]) >= 0 && str[i++] == '-')
// 		sign = -1;
// 	while (is_digit(str[i]))
// 	{
// 		temp = num * 10 + (str[i++] - '0');
// 		if (overflow_saturation(temp, num, sign, n) == OK)
// 			return (OK);
// 		num = temp;
// 	}
// 	*n = sign * (int)num;
// 	if (str[i])
// 		return (ERR);
// 	return (OK);
// }
