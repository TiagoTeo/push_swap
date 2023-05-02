/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:58:47 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/20 19:17:43 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sim_rotate_min(t_ps_list *stack)
{
	int			res;
	int			min;
	t_ps_list	*temp;

	res = 0;
	min = stack->content;
	temp = stack;
	while (temp)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	while (stack)
	{
		res++;
		if (stack->content == min)
			break ;
		stack = stack->next;
	}
	return (res);
}

int	sim_rrotate_min(t_ps_list *stack)
{
	int			min;
	t_ps_list	*temp;

	min = stack->content;
	temp = stack;
	while (temp)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	while (stack)
	{
		if (stack->content == min)
			break ;
		stack = stack->next;
	}
	return (ft_lstsize_ps(stack));
}

int	find_med(t_ps_list *stack_a, int size)
{
	int			menos;
	int			mais;
	t_ps_list	*index;
	t_ps_list	*start;

	index = stack_a;
	start = stack_a;
	while (index)
	{
		stack_a = start;
		menos = 0;
		mais = 0;
		while (stack_a)
		{
			if (index->content > stack_a->content)
				menos++;
			else if (index->content < stack_a->content)
				mais++;
			stack_a = stack_a->next;
		}
		if (menos == size / 2 || mais == size / 2)
			return (index->content);
		index = index->next;
	}
	return (0);
}
