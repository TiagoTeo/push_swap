/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_push_a_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:34:42 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:50:45 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sim_ult_pa_2_aux(int *res, int *rot_a, int *rot_b)
{
	if (*rot_a > 0 && *rot_b > 0)
	{
		*res = *res + 2;
		*rot_a = *rot_a - 1;
		*rot_b = *rot_b - 1;
	}
	else if (*rot_a < 0 && *rot_b < 0)
	{
		*res = *res + 2;
		*rot_a = *rot_a + 1;
		*rot_b = *rot_b + 1;
	}
	else if (*rot_a > 0)
	{
		*res = *res + 1;
		*rot_a = *rot_a - 1;
	}
	else if (*rot_a < 0)
	{
		*res = *res + 1;
		*rot_a = *rot_a + 1;
	}
}

void	sim_ult_pa_2_aux_2(int *res, int *rot_b)
{
	if (*rot_b > 0)
	{
		*res = *res + 1;
		*rot_b = *rot_b - 1;
	}
	else if (*rot_b < 0)
	{
		*res = *res + 1;
		*rot_b = *rot_b + 1;
	}
}

int	sim_ult_pa_2(t_ps_list *stack_a, t_ps_list *stack_b)
{
	int	res;
	int	rot_a;
	int	rot_b;
	int	current_b;

	res = 0;
	current_b = 0;
	rot_a = wich_rotate_ult_a(stack_a, stack_b, &current_b);
	if (rot_a == ft_lstsize_ps(stack_a))
		return (rot_a);
	rot_b = wich_rotate_ult_a_b(stack_b, &current_b);
	while (rot_a != 0 || rot_b != 0)
	{
		if ((rot_a > 0 && rot_b > 0) || (rot_a < 0 && rot_b < 0) || \
		(rot_a > 0) || (rot_a < 0))
			sim_ult_pa_2_aux(&res, &rot_a, &rot_b);
		else if ((rot_b > 0) || (rot_b < 0))
			sim_ult_pa_2_aux_2(&res, &rot_b);
		else
			break ;
	}
	return (res);
}

int	sim_ult_pa_1(t_ps_list *stack_a, t_ps_list *stack_b)
{
	int			res;
	t_ps_list	*temp_a;

	res = 1;
	temp_a = ft_lst_dup(stack_a);
	while (!(is_next(temp_a, stack_b->content, temp_a->content)))
	{
		if (f_ult_a_next(stack_b->content, temp_a) <= \
		(ft_lstsize_ps(temp_a) / 2))
		{
			temp_a = rotate_a(temp_a, 1);
			res++;
		}
		else
		{
			temp_a = rrotate_a(temp_a, 1);
			res++;
		}
	}
	ft_lstclear_ps(&temp_a);
	return (res);
}

int	f_ult_a_next(int current, t_ps_list *stack_a)
{
	int	res;

	res = 0;
	while (!(is_next(stack_a, current, stack_a->content)))
	{
		res++;
		stack_a = stack_a->next;
	}
	return (res);
}
