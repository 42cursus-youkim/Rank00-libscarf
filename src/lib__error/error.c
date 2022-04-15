#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "lib__system.h"
#include "lib__color.h"

void	lib__oppanic__syscall(t_string category)
{
	lib__writes(STDERR_FILENO, (t_string[]){
		BHRED, category, ": ", strerror(errno), END "\n", NULL});
	exit(EXIT_FAILURE);
}

// prints error and exits program
void	lib__panic(t_string what)
{
	lib__writes(STDERR_FILENO, (t_string[]){
		BHRED, "panic: ", what, END "\n", NULL});
	exit(EXIT_FAILURE);
}
