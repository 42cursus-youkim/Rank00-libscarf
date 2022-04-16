#include "std__string.h"

/**
 * @brief find the first occurence of any chars in a character set.
 * c implementation of string::find_first_of in c++.
 * more at https://www.cplusplus.com/reference/string/string/find_first_of/
 * @param this
 * @param charset the character set to search for. if abcd,
 * then the string will be searched for any of first occurance of a, b, c, d.
 * @return index of string if found, ERR (-1) if not found
 */
t_non_neg_int_or_err	str__find_first_of(
		t_string_ref this, t_string_ref charset)
{
	t_uint	i;

	if (not charset)
		return (ERR);
	i = -1;
	while (this[++i])
		if (str__is_in(charset, this[i]))
			return (i);
	return (ERR);
}

/**
 * @brief find the first occurence of any chars not in a character set.
 * c implementation of string::find_first_not_of in c++.
 * more at https://www.cplusplus.com/reference/string/string/find_first_not_of/
 * @param this
 * @param charset
 * @return index of string if found, ERR (-1) if not found
 */
t_non_neg_int_or_err	str__find_first_not_of(
		t_string_ref this, t_string_ref charset)
{
	t_uint	i;

	if (not charset)
		return (ERR);
	i = -1;
	while (this[++i])
		if (not str__is_in(charset, this[i]))
			return (i);
	return (ERR);
}
