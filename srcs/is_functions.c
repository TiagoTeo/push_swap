/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:46:44 by mtiago-s          #+#    #+#             */
/*   Updated: 2022/12/27 17:22:34 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	wich_rotate(t_ps_list *stack)
{
	int	r;
	int	rr;

	r = sim_rotate_min(stack);
	rr = sim_rrotate_min(stack);
	if (r <= rr)
		return (1);
	else
		return (0);
}

int	is_desorg(t_ps_list *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->next)
		{
			if (stack->content < stack->next->content)
				return (0);
		}
		stack = stack->next;
	}
	return (1);
}

int	is_org(t_ps_list *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->next)
		{
			if (stack->content > stack->next->content)
				return (0);
		}
		stack = stack->next;
	}
	return (1);
}

int	is_next(t_ps_list *stack, int current, int next)
{
	t_minmax	*minmax;

	minmax = ft_check_mm(stack);
	if ((current == minmax->max && next == minmax->min) || \
	(is_min(stack, next) && is_max(stack, current)))
		return (1);
	else if (current + 1 == next)
		return (1);
	else if (next < current)
		return (0);
	else
	{
		while (stack)
		{
			if (stack->content != current && stack->content != next && \
			stack->content > current && stack->content < next)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
}

int	is_prev(t_ps_list *stack, int current, int prev)
{
	t_minmax	*minmax;

	minmax = ft_check_mm(stack);
	if ((current == minmax->min && prev == minmax->max) || \
	(is_min(stack, current) && is_max(stack, prev)))
		return (1);
	else if (current - 1 == prev)
		return (1);
	else if (prev > current)
		return (0);
	else
	{
		while (stack)
		{
			if (stack->content != current && stack->content != prev && \
			stack->content < current && stack->content > prev)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
}
