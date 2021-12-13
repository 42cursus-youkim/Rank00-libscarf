/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymath.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:58:39 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 16:54:14 by youkim           ###   ########.fr       */
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
** < comp.c > */

int		ydigitlen(long long n);
/*
** < conv.c > */

int		normalized(int n);
int		yrand(void);
int		ymax(int a, int b);
int		ymin(int a, int b);
/*
** < yaiconv.c > */

char	*new_yitoa(int n);
int		yatoi(const char *str);
/*
** < ybinary.c > */

int		ybitlen(unsigned int bit);
void	ywriteitob(unsigned int bit);
char	*new_yitob(unsigned int bit);
#endif