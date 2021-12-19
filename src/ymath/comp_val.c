/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:04:11 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 10:19:17 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
