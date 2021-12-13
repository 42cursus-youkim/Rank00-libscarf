/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yaiconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:45:25 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 16:54:14 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*new_yitoa(int n)
{
	char	*str;
	int		digit;
	long	num;

	num = n;
	if (num == 0)
		return (new_ystr("0"));
	digit = ydigitlen(num);
	if (num < 0)
		digit++;
	str = new_ystrm(digit);
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[--digit] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}

int	yatoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	if (!str)
		return (0);
	while (ystrchri("\t\n\v\f\r ", str[i]) >= 0)
		i++;
	if (ystrchri("-+", str[i]) >= 0)
		if (str[i++] == '-')
			sign = -1;
	while ('0' <= str[i] && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (sign * num);
}
