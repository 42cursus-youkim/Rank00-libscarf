#include "lib__error.h"
#include "lib__string.h"

void	test__string__cmp(void)
{
	lib__assert(str__cmp("abc", "abc", 3) == 0, "equal strings");
	lib__assert(str__cmp("abc", "abcd", 3) == 0, "partial match");
	lib__assert(str__cmp("abc", "abb", 3) == 1, "partial mismatch 1");
	lib__assert(str__cmp("abb", "abc", 3) == -1, "partial mismatch 2");
}

int	main(void)
{
	test__string__cmp();
	return (0);
}
