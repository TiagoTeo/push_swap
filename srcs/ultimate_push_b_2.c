/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_push_b_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:53:13 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:30:55 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sequence(t_ps_list *seq, int nbr)
{
	while (seq)
	{
		if (nbr == seq->content)
			return (1);
		seq = seq->next;
	}
	return (0);
}

int	get_min_ultpb_aux(t_ps_list **stack, t_ps_list *sequence, t_ps_list *group)
{
	int	hold;

	hold = (*stack)->content;
	while (*stack)
	{
		if (!check_sequence(sequence, (*stack)->content) && \
		!check_sequence(group, (*stack)->content))
		{
			hold = (*stack)->content;
			break ;
		}
		*stack = (*stack)->next;
	}
	return (hold);
}

int	get_min_ultpb(t_ps_list *stack, t_ps_list *sequence, t_ps_list *group, \
int *flag)
{
	int			hold;
	t_ps_list	*start;

	hold = get_min_ultpb_aux(&stack, sequence, group);
	if (!stack)
		*flag = 1;
	start = stack;
	while (stack)
	{
		if (hold > stack->content && !check_sequence(sequence, stack->content) \
		&& !check_sequence(group, stack->content))
		{
			hold = stack->content;
			stack = start;
		}
		stack = stack->next;
	}
	return (hold);
}

t_ps_list	*find_group(t_ps_list *stack, t_ps_list *sequence)
{
	t_ps_list	*res;
	int			hold;
	int			i;
	int			flag;
	int			chunks;

	chunks = descobrir_chunks(ft_check_mm(NULL)->size);
	i = 0;
	flag = 0;
	res = NULL;
	while (i < ft_check_mm(NULL)->size / chunks \
	&& ft_lstsize_ps(stack) - ft_lstsize_ps(sequence) != ft_lstsize_ps(res))
	{
		hold = get_min_ultpb(stack, sequence, res, &flag);
		if (flag)
			return (res);
		if (!res)
			res = ft_lstnew_ps(hold);
		else
			ft_lstadd_back_ps(&res, ft_lstnew_ps(hold));
		i++;
	}
	return (res);
}

int	check_group(t_ps_list *stack, t_ps_list *group)
{
	while (stack)
	{
		if (check_sequence(group, stack->content))
			return (1);
		stack = stack->next;
	}
	return (0);
}
