#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "std__system.h"
#include "std__color.h"

void	std__panic__syscall(t_string category)
{
	std__writes(STDERR_FILENO, (t_string[]){
		BHRED, category, ": ", strerror(errno), END "\n", NULL});
	exit(EXIT_FAILURE);
}

// prints error and exits program
void	std__panic(t_string what)
{
	std__writes(STDERR_FILENO, (t_string[]){
		BHRED, "panic: ", what, END "\n", NULL});
	exit(EXIT_FAILURE);
}
