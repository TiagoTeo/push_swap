/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_push_b_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:29:50 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:36:00 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	descobrir_chunks(int size)
{
	int	res;

	res = size / 5;
	if (res > 50)
		res = 50;
	return (size / res);
}
