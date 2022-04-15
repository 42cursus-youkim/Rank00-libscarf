#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "lib__system.h"
#include "lib__color.h"

t_res	lib__error__syscall(char *category)
{
	lib__writes(STDERR_FILENO, (char *[]){
		BHRED, category, ": ", strerror(errno), END "\n", NULL});
	return (ERR);
}
