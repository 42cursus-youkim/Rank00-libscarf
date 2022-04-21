//a

#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "std__string.h"
#include "std__system.h"
#include "std__test.h"
#include "std__string.h"
// #include "theft.h"

int main() {
	t_string_arr arr = str__new__arr(3, (t_string[]){"a", "b", "c"});
	str__delete__arr(&arr);
	std__panic__value__char("!!!", 'a');
	printf("DONE.\n");
}
