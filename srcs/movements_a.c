/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:53:27 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 16:48:13 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_ps_list *stack)
{
	int	temp;

	temp = stack->content;
	if (ft_lstsize_ps(stack) <= 1)
		return ;
	stack->content = stack->next->content;
	stack->next->content = temp;
	write(1, "sa\n", 3);
}

void	push_a(t_ps_list **stack_1, t_ps_list **stack_2)
{
	t_ps_list	*temp;

	temp = *stack_2;
	if (ft_lstsize_ps(*stack_2) < 1)
		return ;
	*stack_2 = temp->next;
	ft_lstadd_front_ps(stack_1, temp);
	write(1, "pa\n", 3);
}

t_ps_list	*rotate_a(t_ps_list *stack, int flag)
{
	t_ps_list	*temp;

	temp = stack;
	while (temp->next)
		temp = temp->next;
	temp->next = stack;
	stack = stack->next;
	temp->next->next = NULL;
	if (!flag)
		write(1, "ra\n", 3);
	return (stack);
}

t_ps_list	*rrotate_a(t_ps_list *stack, int flag)
{
	t_ps_list	*temp;

	temp = stack;
	while (temp->next->next)
		temp = temp->next;
	temp->next->next = stack;
	stack = temp->next;
	temp->next = NULL;
	if (!flag)
		write(1, "rra\n", 4);
	return (stack);
}
