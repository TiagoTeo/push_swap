/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:09:57 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:48:49 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_ps_list	*ft_solve_3(t_ps_list *stack_a, t_minmax *minmax)
{
	if (is_org(stack_a))
		return (stack_a);
	else if (is_prev(stack_a, stack_a->content, stack_a->next->content))
	{
		swap_a(stack_a);
		stack_a = ft_solve_3(stack_a, minmax);
	}
	else if (stack_a->content == minmax->max)
		stack_a = ft_solve_3(rotate_a(stack_a, 0), minmax);
	else
		stack_a = ft_solve_3(rrotate_a(stack_a, 0), minmax);
	return (stack_a);
}

t_ps_list	*ft_5(t_ps_list *stack_a, t_minmax *minmax, t_ps_list *stack_b)
{
	if (is_org(stack_a) && ft_lstsize_ps(stack_a) == minmax->size)
		return (stack_a);
	else if (is_prev(stack_a, stack_a->content, stack_a->next->content) \
	&& stack_a->content != minmax->min)
		swap_a(stack_a);
	else if ((stack_a->content == minmax->min && !stack_b) || \
	(stack_b && is_next(stack_a, stack_b->content, stack_a->content) \
	&& !is_org(stack_a)))
		push_b(&stack_b, &stack_a);
	else if (is_org(stack_a) && is_desorg(stack_b))
		push_a(&stack_a, &stack_b);
	else if (wich_rotate(stack_a))
		stack_a = rotate_a(stack_a, 0);
	else if (!wich_rotate(stack_a))
		stack_a = rrotate_a(stack_a, 0);
	return (ft_5(stack_a, minmax, stack_b));
}

t_ps_list	*ft_big(t_ps_list *stack_a, t_minmax *minmax, t_ps_list *stack_b)
{
	static int	flag;

	while (!(is_org(stack_a) && ft_lstsize_ps(stack_a) == minmax->size))
	{
		if (!flag)
		{
			ultimate_push_b(&stack_a, &stack_b);
			flag = 1;
		}
		else if ((ft_lstsize_ps(stack_b) / 2) == (ft_lstsize_ps(stack_a) / 2) \
		|| flag)
		{
			if ((is_org(stack_a) || is_almost_org(stack_a)) && \
			ft_lstsize_ps(stack_b))
				ultimate_push_a(&stack_b, &stack_a);
			else if (is_almost_org(stack_a) && !is_org(stack_a))
			{
				if (wich_rotate(stack_a))
					stack_a = rotate_a(stack_a, 0);
				else
					stack_a = rrotate_a(stack_a, 0);
			}
		}
	}
	return (stack_a);
}

t_ps_list	*ft_choose_solve(t_ps_list *stack_a)
{
	t_minmax	*minmax;

	minmax = ft_check_mm(stack_a);
	if (minmax->size == 2 && stack_a->content > stack_a->next->content)
		swap_a(stack_a);
	else if (minmax->size == 3)
		stack_a = ft_solve_3(stack_a, minmax);
	else if (minmax->size == 5 || minmax->size == 4)
		stack_a = ft_5(stack_a, minmax, NULL);
	else if (minmax->size > 5)
		stack_a = ft_big(stack_a, minmax, NULL);
	free(minmax);
	return (stack_a);
}
