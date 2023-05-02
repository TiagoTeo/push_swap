/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:24:40 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/20 19:10:30 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_min(t_ps_list *stack, int min)
{
	while (stack)
	{
		if (min > stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_max(t_ps_list *stack, int max)
{
	while (stack)
	{
		if (max < stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* int	is_almost_org(t_ps_list *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->next)
		{
			if (stack->content > stack->next->content && \
			!(is_max(stack, stack->content) && \
			is_min(stack, stack->next->content)))
				return (0);
		}
		stack = stack->next;
	}
	return (1);
} 

int	is_almost_desorg(t_ps_list *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->next)
		{
			if (stack->content < stack->next->content && \
			!(is_min(stack, stack->content) && \
			is_max(stack, stack->next->content)))
				return (0);
		}
		stack = stack->next;
	}
	return (1);
}*/

int	is_almost_org(t_ps_list *stack)
{
	t_ps_list	*temp;

	temp = ft_lst_dup(stack);
	if (!stack || !temp)
		return (0);
	while (!is_min(temp, temp->content))
	{
		if (wich_rotate(temp))
			temp = rotate_a(temp, 1);
		else
			temp = rrotate_a(temp, 1);
	}
	if (is_org(temp))
	{
		ft_lstclear_ps(&temp);
		return (1);
	}
	else
	{
		ft_lstclear_ps(&temp);
		return (0);
	}
}

/*int	is_almost_desorg(t_ps_list *stack)
{
	t_ps_list	*temp;

	temp = ft_lst_dup(stack);
	if (!stack || !temp)
		return (0);
	while (!is_min(temp, temp->content))
	{
		if (wich_rotate_b(temp))
			temp = rotate_b(temp, 1);
		else
			temp = rrotate_b(temp, 1);
	}
	if (is_desorg(temp))
	{
		ft_lstclear_ps(&temp);
		return (1);
	}
	else
	{
		ft_lstclear_ps(&temp);
		return (0);
	}
}

int	wich_rotate_b(t_ps_list *stack)
{
	int	r;
	int	rr;

	r = sim_rotate_max(stack);
	rr = sim_rrotate_max(stack);
	if (r <= rr)
		return (1);
	else
		return (0);
} */
