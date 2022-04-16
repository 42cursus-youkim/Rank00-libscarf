#include <stdio.h>
#include "std__types.h"
#include "std__error.h"
#include "std__string.h"

//	same as indexing but will crash if the index is out of bounds.
char	str__at(const t_string this, const t_uint index)
{
	if (index >= (t_uint)str__len(this))
	{
		printf("tried to access index %d of string %s"
			" but it only has %d characters.\n", index, this, str__len(this));
		std__panic("str__at: index out of bounds");
	}
	return (this[index]);
}
