/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ybinary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:27:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 16:32:46 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	returns length of digits needed to represent bit
int	ybitlen(unsigned int bit)
{
	int	i;

	i = 0;
	while (bit > 0)
	{
		bit >>= 1;
		i++;
	}
	return (i);
}

void	ywriteitob(unsigned int bit)
{
	int	i;

	i = ybitlen(bit);
	ywrite(1, UMAG);
	while (--i >= 0)
	{
		ywrite(1, (char [2][2]){"0", "1"}[(bit & 1 << i) != 0]);
	}
	ywrite(1, "\n" END);
}
