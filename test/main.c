#include <stdio.h>
#include <assert.h>
#include "std__test.h"
#include "std__string.h"

void	test__string__cmp(void)
{
	test__header("string::cmp");
	TEST__ASSERT_EQ(str__cmp("abc", "abc", 3), 0);
	TEST__ASSERT_EQ(str__cmp("abc", "abcd", 3), 0);
	TEST__ASSERT_EQ(str__cmp("abc", "abb", 3), 1);
	TEST__ASSERT_EQ(str__cmp("abb", "abc", 3), -1);
	TEST__ASSERT_EQ(str__cmp("abcd", "abc", 4), 'd');
}

void	test__string__len(void)
{
	test__header("str::len");
	TEST__ASSERT_EQ(str__len("abc"), 3);
	TEST__ASSERT_EQ(str__len(""), 0);
	TEST__ASSERT_EQ(str__len(NULL), -1);
}

void	test__string__is_equal(void)
{
	test__header("str::is_equal");
	TEST__ASSERT_EXPR(str__is_equal("hello world", "hello world"));
	TEST__ASSERT_EXPR(not str__is_equal("hello world", "hello world!"));
	TEST__ASSERT_EXPR(not str__is_equal("hello world", "bye world"));
	TEST__ASSERT_EXPR(not str__is_equal("hello world", NULL));
}

int	main(void)
{
	test__string__cmp();
	test__string__len();
	test__string__is_equal();
	return (0);
}
