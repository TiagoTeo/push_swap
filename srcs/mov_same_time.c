/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_same_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:29:53 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/20 19:08:53 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_ps_list *stack_a, t_ps_list *stack_b)
{
	int	temp;

	temp = stack_a->content;
	if ((ft_lstsize_ps(stack_a) <= 1) || (ft_lstsize_ps(stack_b) <= 1))
		return ;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = temp;
	temp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = temp;
	write(1, "ss\n", 3);
}

void	rr(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*temp_a;
	t_ps_list	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	*stack_a = rotate_a(temp_a, 1);
	*stack_b = rotate_b(temp_b, 1);
	write(1, "rr\n", 3);
}

void	rrr(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*temp_a;
	t_ps_list	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	*stack_a = rrotate_a(temp_a, 1);
	*stack_b = rrotate_b(temp_b, 1);
	write(1, "rrr\n", 4);
}
