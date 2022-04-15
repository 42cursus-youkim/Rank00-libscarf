#ifndef LIB__TYPES_H
# define LIB__TYPES_H

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include <iso646.h>

typedef int8_t		t_i8;
typedef int16_t		t_i16;
typedef int32_t		t_i32;
typedef int64_t		t_i64;

typedef uint8_t		t_u8;
typedef uint16_t	t_u16;
typedef uint32_t	t_u32;
typedef uint64_t	t_u64;

typedef char *		t_string;

typedef enum e_res
{
	OK,
	ERR = -1,
}	t_res;

#endif
