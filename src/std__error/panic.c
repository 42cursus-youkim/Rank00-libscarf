#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "std__system.h"
#include "std__color.h"
#include "std__string.h"


void	std__panic_write_internal(
	t_string_ref arr[])
{
	int		i;

	if (arr)
		std__writes(STDERR_FILENO, (t_string_ref[]){
			BHRED "panic " BMAG "@", arr[0], HRED, NULL});
	else
	{
		std__write(STDERR_FILENO,
			BHRED "panic " BMAG
			"@std__panic_write_internal : arr is NULL\n" END);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (arr[++i])
		std__writes(STDERR_FILENO, (t_string_ref[]){
			": ", arr[i], NULL});
	std__write(STDERR_FILENO, END "\n");
}

void	std__panic__syscall(t_string_ref category)
{
	std__panic_write_internal((t_string_ref[]){
		category, strerror(errno), NULL});
	exit(EXIT_FAILURE);
}

// prints error and exits program
void	std__panic(t_string_ref what)
{
	std__panic_write_internal((t_string_ref[]){
		what, NULL});
	exit(EXIT_FAILURE);
}

//TODO: atoi
void	std__panic__index(t_string_ref where, t_string_ref what, int index)
{
	t_string	index_str;

	index_str = str__new_from_int(index);
	std__panic_write_internal((t_string_ref[]){
		where, "while indexing", what, "index out of range", index_str, NULL});
	str__delete(&index_str);
	exit(EXIT_FAILURE);
}
