/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:56:56 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 17:13:05 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// bool	is_char(char c, t_chartype type)
// {
// 	int	res;

// 	res = 0;
// 	return ((bool)res);
// }

//	returns how many digits the number has
int	ydigitlen(long long n)
{
	int	digit;

	digit = 0;
	if (n < 0)
	{
		n /= -10;
		digit++;
	}
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}