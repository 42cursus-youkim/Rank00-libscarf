#include <unistd.h>
#include "lib_error.h"
#include "lib_system.h"

t_res	error_syscall(char *category)
{
	lib_writes(STDERR_FILENO, (char *[]){
		BHRED, category, ": ", strerror(errno), END "\n", NULL});
	return (ERR);
}
