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
	t_string str = str__new("     abc de	   ");
	str__strip__spaces(&str);
	assert(str__is_equal(str, "abc de"));
	// t_string a = str__new_substr(str, 0, 3);
	// t_string b = str__new_substr(str, 3, -1);
	// printf("a: %s\n", a);
	// assert(str__is_equal(a, "abc"));
	// assert(str__is_equal(b, "de"));
	// t_string names[] = {
	// 	"test/gnlTester/files/empty",
	// 	"test/gnlTester/files/41_no_nl",
	// 	"test_no_nl.txt",
	// 	"test_empty_file.txt",
	// 	"test.txt",
	// };
	// for (int i = 0; i < 4; i++) {
	// 	t_fd fd = open(names[i], O_RDONLY);
	// 	printf("fd: %d\n", fd);
	// 	t_string str;
	// 	while (true) {
	// 		str = std__new_readfile__line(fd);
	// 		printf(CYN "[" END "%s" CYN "]\n" END, str);
	// 		if (!str)
	// 			break;
	// 		else
	// 			free(str);
	// 		for (int j = 0; j < 10; j++) std__new_readfile__line(fd);
	// 		printf("opening again\n");
	// 	}
	// }
	printf("DONE.\n");
}
