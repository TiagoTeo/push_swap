/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_push_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:17 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:49:59 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fun_do_it_aux(t_ps_list **stack_a, t_ps_list **stack_b, int	*rot_a, \
int *rot_b)
{
	if (*rot_a > 0 && *rot_b > 0)
	{
		*stack_a = rotate_a(*stack_a, 0);
		*stack_b = rotate_b(*stack_b, 0);
		*rot_a = *rot_a - 1;
		*rot_b = *rot_b - 1;
	}
	else if (*rot_a < 0 && *rot_b < 0)
	{
		*stack_a = rrotate_a(*stack_a, 0);
		*stack_b = rrotate_b(*stack_b, 0);
		*rot_a = *rot_a + 1;
		*rot_b = *rot_b + 1;
	}
	else if (*rot_a > 0)
	{
		*stack_a = rotate_a(*stack_a, 0);
		*rot_a = *rot_a - 1;
	}
	else if (*rot_a < 0)
	{
		*stack_a = rrotate_a(*stack_a, 0);
		*rot_a = *rot_a + 1;
	}
}

void	fun_do_it(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int			rot_a;
	int			rot_b;
	static int	current_b;

	rot_a = wich_rotate_ult_a(*stack_a, *stack_b, &current_b);
	rot_b = wich_rotate_ult_a_b(*stack_b, &current_b);
	while (rot_a != 0 || rot_b != 0)
	{
		if ((rot_a > 0 && rot_b > 0) || (rot_a < 0 && rot_b < 0) || (rot_a > 0) \
		|| (rot_a < 0))
			fun_do_it_aux(stack_a, stack_b, &rot_a, &rot_b);
		else if (rot_b > 0)
		{
			*stack_b = rotate_b(*stack_b, 0);
			rot_b--;
		}
		else if (rot_b < 0)
		{
			*stack_b = rrotate_b(*stack_b, 0);
			rot_b++;
		}
		else
			break ;
	}
	push_a(stack_a, stack_b);
}

void	ultimate_push_a(t_ps_list **stack_b, t_ps_list **stack_a)
{
	t_ps_list	*temp_a;
	t_ps_list	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	if (sim_ult_pa_1(temp_a, temp_b) <= sim_ult_pa_2(temp_a, temp_b))
	{
		while (!(is_next(temp_a, temp_b->content, temp_a->content)))
		{
			if (f_ult_a_next(temp_b->content, *stack_a) <= \
			(ft_lstsize_ps(*stack_a) / 2))
				temp_a = rotate_a(temp_a, 0);
			else
				temp_a = rrotate_a(temp_a, 0);
		}
		push_a(&temp_a, &temp_b);
	}
	else
		fun_do_it(&temp_a, &temp_b);
	*stack_a = temp_a;
	*stack_b = temp_b;
}
