/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_bool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:20:00 by youkim            #+#    #+#             */
/*   Updated: 2021/12/11 17:26:20 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	returns true if value matches any of the values in the list
	usage: yany(value, 4, (int []){1, 2, 3, 4})
*/
bool	yanyi(int value, int i, const int arr[])
{
	if (i <= 0)
		yerror("yany", "i must be greater than 0");
	while (arr[--i])
		if (value == arr[i])
			return (true);
	return (false);
}
