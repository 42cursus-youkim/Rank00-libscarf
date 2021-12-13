/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yatoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:54:50 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 15:42:57 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
