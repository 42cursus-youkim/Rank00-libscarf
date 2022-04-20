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
	// t_string a = str__new_size(0);
	// str__append(&a, str);
	// printf("%s / %s \n", str, a);
	// assert(str__is_equal(str__new_substr("hello", 0, str__len("hello")), "hello"));
	t_fd fd = open("test/main.c", O_RDONLY);
	printf("fd: %d\n", fd);
	t_string str;
	while ((str = std__new_readfile__line(fd))) {
		printf(CYN "[" END "%s" CYN "]\n" END, str);
		free(str);
	}
	printf("DONE.\n");
}
