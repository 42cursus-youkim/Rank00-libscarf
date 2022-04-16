#include <stdio.h>
#include <assert.h>
#include "std__test.h"
#include "std__string.h"

void	test__string__cmp(void)
{
	test__header("string::cmp");
	TEST__ASSERT_EQ(str__ncmp("abc", "abc", 3), 0);
	TEST__ASSERT_EQ(str__ncmp("abc", "abcd", 3), 0);
	TEST__ASSERT_EQ(str__ncmp("abc", "abb", 3), 1);
	TEST__ASSERT_EQ(str__ncmp("abb", "abc", 3), -1);
	TEST__ASSERT_EQ(str__ncmp("abcd", "abc", 4), 'd');
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

void	test__string__find(void)
{
	test__header("str::find related");
	test__subject("str::find");
	TEST__ASSERT_EQ(str__find("hello world", "hello"), 0);
	TEST__ASSERT_EQ(str__find("hello world", "world"), 6);
	TEST__ASSERT_EQ(str__find("hello world", "bye"), ERR);
	TEST__ASSERT_EQ(str__find("hello world", ""), 0);
	TEST__ASSERT_EQ(str__find("hello world", NULL), ERR);
	test__subject("str::find_first_of");
	TEST__ASSERT_EQ(str__find_first_of("hello world", "abc"), ERR);
	TEST__ASSERT_EQ(str__find_first_of("hello world", "def"), 1);
	TEST__ASSERT_EQ(str__find_first_of("hello world", ""), ERR);
	TEST__ASSERT_EQ(str__find_first_of("hello world", NULL), ERR);
	test__subject("str::find_first_not_of");
	TEST__ASSERT_EQ(str__find_first_not_of("hello world", "abc"), 0);
	TEST__ASSERT_EQ(str__find_first_not_of("hello world", "helo"), 5);
	TEST__ASSERT_EQ(str__find_first_not_of("hello world", ""), 0);
	TEST__ASSERT_EQ(str__find_first_not_of("hello world", "hello world"), ERR);
	TEST__ASSERT_EQ(str__find_first_not_of("hello world", NULL), ERR);
}

void	test__string__conversion(void)
{
	test__header("str::conversion");
	test__subject("str__to_int");
	TEST__ASSERT_EQ(str__to_int("123").num, 123);
	TEST__ASSERT_EQ(str__to_int("-123").num, -123);
	TEST__ASSERT_EQ(str__to_int("123a").err, ERR);
	TEST__ASSERT_EQ(str__to_int("a123").err, ERR);
	test__subject("int min/max");
	TEST__ASSERT_EQ(str__to_int("2147483647").num, 2147483647);
	TEST__ASSERT_EQ(str__to_int("-2147483648").num, -2147483648);
	test__subject("integer overflow");
	TEST__ASSERT_EQ(str__to_int("2147483648").err, ERR);
	TEST__ASSERT_EQ(str__to_int("-2147483649").err, ERR);
}

int	main(void)
{
	test__string__cmp();
	test__string__len();
	test__string__is_equal();
	test__string__find();
	test__string__conversion();

	t_string str = str__new("hello world");
	str__delete(&str);
	TEST__ASSERT_EQ(str, NULL);
	str__at("hello", 20);
	std__panic("str__new");
	return (0);
}
