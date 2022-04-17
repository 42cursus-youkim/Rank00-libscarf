#include "std__string.h"

t_string	str__new_substr(
		t_string_ref str, t_uint start, t_int_or_neg_as_flag len)
{
	int			i;
	t_string	new;
	const int	str_len = str__len(str);

	if (start >= (t_uint)str_len)
		std__panic__index__string(
			"str__new_substr", "start >= str_len", start, str_len);
	if (len == NEG_AS_FLAG__UNLIMITED)
		return (str__new(str + start));
	if (str_len == ERR or not str)
		std__panic__null("str__new_substr");
	new = str__new_size(len);
	i = -1;
	while (++i < len)
		new[i] = str[start + i];
	return (new);
}
