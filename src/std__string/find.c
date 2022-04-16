#include "std__string.h"

/**
 * @brief find the first occurence of any chars in a character set.
 * c++ string find_first_of in c.
 * more at https://www.cplusplus.com/reference/string/string/find_first_of/
 * @param this
 * @param charset the character set to search for. if abcd,
 * then the string will be searched for any of first occurance of a, b, c, d.
 * @return index of string if found, ERR (-1) if not found
 */
t_non_neg_int_or_err	str__find_first_of(
		t_string_ref this, t_string_ref charset)
{
	t_uint				i;

	i = -1;
	while (this[++i])
		if (str__is_in(charset, this[i]))
			return (i);
	return (ERR);
}

/**
 * @brief find the first occurence of a string.
 * str__find("abcde", "de") would return 3.
 * @param this the string to search in.
 * @param other the sequence to search for.
 * @return index of string if found, ERR (-1) if not found
 */
t_non_neg_int_or_err	str__find(t_string_ref this, t_string_ref other)
{
	t_i64		i;
	const int	this_len = str__len(this);
	const int	other_len = str__len(other);

	if (other_len == ERR or other_len == 0)
		return (other_len);
	i = -1;
	while (++i <= this_len - other_len)
		if (str__ncmp(this + i, other, other_len) == 0)
			return (i);
	return (ERR);
}
