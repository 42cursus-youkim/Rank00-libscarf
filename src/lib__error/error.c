#include <unistd.h>
#include <string.h>
#include "lib__error.h"
#include "lib__system.h"

t_res	error__syscall(char *category)
{
	lib_writes(STDERR_FILENO, (char *[]){
		BHRED, category, ": ", strerror(errno), END "\n", NULL});
	return (ERR);
}
