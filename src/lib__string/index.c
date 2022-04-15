#include <stdio.h>
#include "lib__types.h"
#include "lib__error.h"

//	same as indexing but will crash if the index is out of bounds.
char	str__at(const t_string this, const t_uint index)
{
	if (index >= str__len(this))
	{
		printf("tried to access index %d of string %s"
			" but it only has %d characters.\n", index, this, str__len(this));
		lib__panic("str__at: index out of bounds");
	}
	return (this[index]);
}
