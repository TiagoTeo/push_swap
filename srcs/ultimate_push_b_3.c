/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_push_b_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:53:15 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 17:55:25 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rot_a_ultpb_aux(t_ps_list *temp, t_ps_list *group, int *i)
{
	int	nbr;

	nbr = temp->content;
	while (temp)
	{
		if (check_sequence(group, temp->content))
		{
			nbr = temp->content;
			break ;
		}
		*i = *i + 1;
		temp = temp->next;
	}
	return (nbr);
}

int	rot_a_ultpb(t_ps_list *stack_a, t_ps_list *group, int *nbr)
{
	t_ps_list	*temp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	temp = ft_lst_dup(stack_a);
	*nbr = rot_a_ultpb_aux(temp, group, &i);
	while (temp)
	{
		if (check_sequence(group, temp->content))
			break ;
		j--;
		temp = rrotate_a(temp, 1);
	}
	if (j * -1 < i)
	{
		*nbr = temp->content;
		i = j;
	}
	ft_lstclear_ps(&temp);
	return (i);
}

int	rot_b_ultpb(t_ps_list *stack_b, int nbr)
{
	int	i;
	int	size;

	i = 0;
	if (!stack_b)
		return (i);
	size = ft_lstsize_ps(stack_b);
	while (stack_b)
	{
		if (is_prev(stack_b, nbr, stack_b->content))
			break ;
		i++;
		stack_b = stack_b->next;
	}
	if (i > size / 2)
		i = (size - i) * -1;
	return (i);
}

void	one_push_b_aux(t_ps_list **stack_a, t_ps_list **stack_b, int *rot_a, \
int *rot_b)
{
	if (*rot_a > 0 && *rot_b > 0)
	{
		rr(stack_a, stack_b);
		*rot_a = *rot_a - 1;
		*rot_b = *rot_b - 1;
	}
	else if (*rot_a < 0 && *rot_b < 0)
	{
		rrr(stack_a, stack_b);
		*rot_a = *rot_a + 1;
		*rot_b = *rot_b + 1;
	}
	else if (*rot_a > 0)
	{
		*stack_a = rotate_a(*stack_a, 0);
		*rot_a = *rot_a - 1;
	}
}

void	one_push_b(t_ps_list **stack_a, t_ps_list **stack_b, int rot_a, int nbr)
{
	int	rot_b;

	rot_b = rot_b_ultpb(*stack_b, nbr);
	while (rot_a || rot_b)
	{
		if ((rot_a > 0 && rot_b > 0) || (rot_a < 0 && rot_b < 0) || (rot_a > 0))
			one_push_b_aux(stack_a, stack_b, &rot_a, &rot_b);
		else if (rot_b > 0)
		{
			*stack_b = rotate_b(*stack_b, 0);
			rot_b--;
		}
		else if (rot_a < 0)
		{
			*stack_a = rrotate_a(*stack_a, 0);
			rot_a++;
		}
		else if (rot_b < 0)
		{
			*stack_b = rrotate_b(*stack_b, 0);
			rot_b++;
		}
	}
	push_b(stack_b, stack_a);
}
