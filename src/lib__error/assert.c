#include <stdio.h>
#include <stdbool.h>
#include "lib__string.h"
#include "lib__color.h"

/** @brief assert expression is true. exit(1) if false.
 *  @param expr expression to evaluate
 *  @param name name of the assertion test.
 */
void	lib__assert(bool expr, const t_string name)
{
	printf(CYN "testing case " WHT "%s" MAG ":", name);
	if (expr)
		printf(BGRN "OK!\n" END);
	else
	{
		printf(BHRED "KO!\n" END);
		exit(1);
	}
}
