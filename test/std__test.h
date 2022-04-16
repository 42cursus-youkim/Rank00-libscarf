#ifndef STD__TEST_H
#define STD__TEST_H

#include <stdio.h>
#include "std__color.h"
#include "std__types.h"

void test__header(const t_string text)
{
	printf(BHYEL "\n----------------------------------------\n");
	printf("[[[ Testing " BBLU "%s" BHYEL " ]]]\n", text);
}

void test__subject(const t_string text)
{
	printf(MAG "  [ case " BCYN "%s" MAG " ]\n" END, text);
}

#define TEST__ASSERT_EQ(left, right)                                         \
  do {                                                                       \
    assert(left == right);                                                   \
    printf(HWHT "{ " BBLU #left " == " #right HWHT " } " BGRN " OK!\n" END); \
  } while (0);

#define TEST__ASSERT_EXPR(expr)                                \
  do {                                                         \
    assert(expr);                                              \
    printf(HWHT "{ " BBLU #expr HWHT " } " BGRN " OK!\n" END); \
  } while (0);

#endif
