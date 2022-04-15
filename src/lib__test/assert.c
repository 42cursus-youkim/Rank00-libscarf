#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib__string.h"
#include "lib__color.h"

void	test__header(const t_string text)
{
	printf(BHYEL "\n----------------------------------------\n");
	printf("[[[ Testing " BBLU "%s" BHYEL " ]]]\n", text);
}

void	test__subject(const t_string text)
{
	printf(MAG "  [ case " BCYN "%s" MAG " ]\n" END, text);
}

/** @brief assert expression is true. exit(1) if false.
 *  @param expr expression to evaluate
 *  @param name name of the assertion test.
 */
void	test__assert(bool expr)
{
	if (expr)
		printf(BGRN "OK! " END);
	else
	{
		printf(BHRED "KO!\n" END);
		exit(1);
	}
}
