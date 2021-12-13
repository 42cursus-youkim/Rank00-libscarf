/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymath.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:58:39 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 18:18:43 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YMATH_H
# define YMATH_H

typedef enum e_ctype_b
{
	LOWER = 0b0001,
	UPPER = 0b0010,
	ALPHA = 0b0011,
	DIGIT = 0b0100,
	ALNUM = 0b0111,
	ASCII = 0b1000,
}	t_ctype_b;
//	@func
/*
** < comp_char.c > */

bool	is_char(char c, t_ctype_b type);
/*
** < comp_num.c > */

int		ymax(int a, int b);
int		ymin(int a, int b);
int		ydigitlen(long long n);
bool	yanyi(int value, int size, const int arr[]);
/*
** < conv.c > */

int		normalized(int n);
int		yrand(void);
char	*new_yitoa(int n);
int		yatoi(const char *str);
/*
** < ybinary.c > */

int		ybitlen(unsigned int bit);
void	ywriteitob(unsigned int bit);
char	*new_yitob(unsigned int bit);
#endif