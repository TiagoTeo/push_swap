/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_push_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:59:19 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 17:58:46 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	lst_last(t_ps_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst->content);
}

int	get_value_ultpb(t_ps_list *stack, int nbr)
{
	int	res;

	res = 0;
	while (stack)
	{
		if (nbr < stack->content)
			res++;
		else
			res--;
		stack = stack->next;
	}
	return (res);
}

void	get_sequence_ultpb(t_ps_list *stack, t_ps_list **sequence)
{
	t_ultpb		*temp;
	int			dist;

	while (stack && stack->content != lst_last(*sequence))
		stack = stack->next;
	temp = malloc(sizeof(t_ultpb));
	temp->nbr = 0;
	dist = 0;
	while (stack)
	{
		if (lst_last(*sequence) < stack->content)
		{
			if (!temp->nbr || (temp->size < \
			(get_value_ultpb(stack, stack->content) - dist)))
			{
				temp->nbr = stack->content;
				temp->size = get_value_ultpb(stack, stack->content) - dist;
			}
		}
		dist++;
		stack = stack->next;
	}
	if (temp->nbr && temp->nbr != lst_last(*sequence))
		ft_lstadd_back_ps(sequence, ft_lstnew_ps(temp->nbr));
	free(temp);
}

t_ps_list	*find_ultpb(t_ps_list *stack_a)
{
	t_ps_list	*res;
	t_ps_list	*temp;
	int			pos;

	temp = ft_lst_dup(stack_a);
	temp = puton_min(temp);
	res = ft_lstnew_ps(temp->content);
	pos = 1;
	while (pos == ft_lstsize_ps(res))
	{
		get_sequence_ultpb(temp, &res);
		pos++;
	}
	ft_lstclear_ps(&temp);
	return (res);
}

void	ultimate_push_b(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*sequence;
	t_ps_list	*temp;
	int			rot_a;
	int			nbr;

	sequence = find_ultpb(*stack_a);
	while (ft_lstsize_ps(*stack_a) != ft_lstsize_ps(sequence))
	{
		temp = find_group(*stack_a, sequence);
		while (check_group(*stack_a, temp))
		{
			rot_a = rot_a_ultpb(*stack_a, temp, &nbr);
			one_push_b(stack_a, stack_b, rot_a, nbr);
		}
		ft_lstclear_ps(&temp);
	}
	ft_lstclear_ps(&sequence);
}
