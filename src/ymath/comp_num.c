/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:56:56 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 17:48:34 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ymax(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ymin(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

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

/*	returns true if value matches any of the values in the list
	usage: yany(value, 4, (int []){1, 2, 3, 4})
*/
bool	yanyi(int value, int size, const int arr[])
{
	if (size <= 0)
		yerror("yany", "i must be greater than 0");
	while (arr[--size])
		if (value == arr[size])
			return (true);
	return (false);
}
