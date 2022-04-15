#include "lib__test.h"
#include "lib__string.h"
#include <stdio.h>

void	test__string__cmp(void)
{
	test__header("string::cmp");
	test__assert(str__cmp("abc", "abc", 3) == 0);
	test__assert(str__cmp("abc", "abcd", 3) == 0);
	test__assert(str__cmp("abc", "abb", 3) == 1);
	test__assert(str__cmp("abb", "abc", 3) == -1);
	test__assert(str__cmp("abcd", "abc", 4) == 'd');
}

void	test__string__len(void)
{
	test__header("str::len");
	test__assert(str__len("abc") == 3);
	test__assert(str__len("") == 0);
	test__assert(str__len(NULL) == -1);
}

void	test__string__is_equal(void)
{
	test__header("str::is_equal");
	test__assert(str__is_equal("hello world", "hello world"));
	test__assert(!str__is_equal("hello world", "hello world!"));
	test__assert(!str__is_equal("hello world", "bye world"));
	test__assert(!str__is_equal("hello world", NULL));
}

int	main(void)
{
	test__string__cmp();
	test__string__len();
	test__string__is_equal();
	return (0);
}
