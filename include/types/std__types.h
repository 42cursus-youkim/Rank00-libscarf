#ifndef STD__TYPES_H
# define STD__TYPES_H

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include <iso646.h>

typedef int8_t		t_i8;
typedef int16_t		t_i16;
typedef int32_t		t_i32;
typedef int64_t		t_i64;

typedef uint32_t	t_uint;
typedef uint8_t		t_u8;
typedef uint16_t	t_u16;
typedef uint32_t	t_u32;
typedef uint64_t	t_u64;

/** a string is defined as a pointer to a unsigned char array
 *  string's max length could be INT_MAX - 1 (1 for NULL) */
typedef char*		t_string;
typedef const char*	t_string_ref;

typedef enum e_res
{
	OK,
	ERR = -1,
	UNSET = -2,
}	t_res;

typedef int			t_non_neg_int_or_err;

typedef struct s_int_res
{
	t_res		err;
	int			result;
}	t_int_res;

#endif
