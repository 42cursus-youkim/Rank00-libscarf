#include <limits.h>
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

// t_int_res	str__to_int(t_string_ref str)
// {
// 	int			i;
// 	int			sign;
// 	t_i64		num;
// 	t_int_res	result;

// 	num = 0;
// 	sign = 1;
// 	result.err = ERR;
// 	if (!str)
// 		return (result);
// 	i = str__find_first_not_of(str, " \t\n\v\f\r");
// 	if (i == ERR)
// 		return ((t_int_res){ERR, UNSET});
// 	if (str__is_in("-+", str[i]) and str[i++] == '-')
// 		sign = -1;
// 	while (is_digit(str[i]))
// 	{
// 		num = num * 10 + (str[i++] - '0');
// 		if (num > INT_MAX or num < INT_MIN)
// 			return (result);
// 	}
// 	if (str[i])

// 	return result;
// }
