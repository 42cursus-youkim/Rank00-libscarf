/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymath.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:58:39 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 12:13:22 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YMATH_H
# define YMATH_H

typedef enum e_chartype
{
	LOWER = 1 << 0,
	UPPER = 1 << 1,
	DIGIT = 1 << 2,
	ALPHA = 1 << 3,
	ALNUM = 1 << 4,
	ASCII = 1 << 5,
}	t_chartype;
//	@func
/*
** < func_bool.c > */

bool	is_char(char c, t_chartype type);
/*
** < func_ymath.c > */

int		ydigits(long long n);
int		normalized(int n);
int		yrand(void);
int		ymax(int a, int b);
/*
** < new_yitoa.c > */

char	*new_yitoa(int n);
/*
** < yatoi.c > */

int		yatoi(const char *str);
#endif