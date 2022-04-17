#include "std__string.h"
#include "std__system.h"

t_int_or_neg_as_err	str__count_of(t_string_ref str, t_string_ref delim)
{
	int			i;
	int			count;
	const int	delim_len = str__len(delim);
	const int	str_len = str__len(str);

	if (str == NULL or delim == NULL)
		return (ERR);
	if (delim_len == ERR or str_len == ERR)
		return (ERR);
	count = 0;
	i = -1;
	while (++i < str_len)
	{
		if (str__find(str + i, delim) == i)
			count++;
	}
	return (count);
}

t_string	*str__split(t_string_ref str, t_string_ref delim)
{
	t_string	*arr;
	t_uint		i;
	t_uint		j;
	t_uint		k;

	if (not str or not delim)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	arr = std__allocate(str__count_of(str, delim) + 2, sizeof(t_string));
	while (str[i])
	{
		if (str__is_in(delim, str[i]))
		{
			arr[k++] = str__new_substr(str, j, i - j);
			j = i + 1;
		}
		i++;
	}
	arr[k++] = str__new_substr(str, j, i - j);
	arr[k] = NULL;
	return (arr);
}
