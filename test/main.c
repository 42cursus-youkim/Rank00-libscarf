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
	// t_string str = str__new("abcde");
	// t_string a = str__new_substr(str, 0, 3);
	// t_string b = str__new_substr(str, 3, -1);
	// printf("a: %s\n", a);
	// assert(str__is_equal(a, "abc"));
	// assert(str__is_equal(b, "de"));
	t_fd fd = open("test.txt", O_RDONLY);
	// t_fd fd = open("test/gnlTester/files/41_no_nl", O_RDONLY);
	printf("fd: %d\n", fd);
	t_string str;
	while ((str = std__new_readfile__line(fd))) {
		printf(CYN "[" END "%s" CYN "]\n" END, str);
		free(str);
	}
	printf("DONE.\n");
}
