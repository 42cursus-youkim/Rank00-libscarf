#include "std__string.h"

/** @brief Compare two strings. use str__is_equal() instead.
 *  @return n1 - n2 of first non-matching char || 0 (leached end) */
int	str__ncmp(t_string_ref s1, t_string_ref s2, int n)
{
	int		i;
	t_u8	n1;
	t_u8	n2;

	i = -1;
	while (++i < n)
	{
		n1 = (t_u8)s1[i];
		n2 = (t_u8)s2[i];
		if (n1 != n2)
			return (n1 - n2);
		if (!n1 || !n2)
			break ;
	}
	return (0);
}

/** @return true if value of s1 and s2 are same. */
bool	str__is_equal(t_string_ref s1, t_string_ref s2)
{
	const int	s1_len = str__len(s1);
	const int	s2_len = str__len(s2);

	return (s1_len == s2_len && str__ncmp(s1, s2, s1_len) == 0);
}
