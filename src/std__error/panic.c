#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "std__system.h"
#include "std__color.h"

void	std__panic__syscall(t_string_ref category)
{
	std__writes(STDERR_FILENO, (t_string_ref[]){
		BHRED, category, ": ", strerror(errno), END "\n", NULL});
	exit(EXIT_FAILURE);
}

// prints error and exits program
void	std__panic(t_string_ref what)
{
	std__writes(STDERR_FILENO, (t_string_ref[]){
		BHRED, "panic: ", what, END "\n", NULL});
	exit(EXIT_FAILURE);
}

//TODO: atoi
void	std__panic__index(t_string what, int index)
{
	(void)index;
	std__writes(STDERR_FILENO, (t_string_ref[]){
		BHRED, "panic: ", what, ": index out of range: ", NULL});
	exit(EXIT_FAILURE);
}
