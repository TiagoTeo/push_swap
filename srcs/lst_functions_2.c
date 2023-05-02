/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:56:55 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 17:56:46 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_ps_list	*ft_lst_dup(t_ps_list *stack)
{
	t_ps_list	*res;

	res = NULL;
	while (stack)
	{
		ft_lstadd_back_ps(&res, ft_lstnew_ps(stack->content));
		stack = stack->next;
	}
	return (res);
}

void	ft_lstclear_ps(t_ps_list **lst)
{
	t_ps_list	*temp;
	t_ps_list	*stack;

	stack = *lst;
	if (lst)
	{
		while (stack)
		{
			temp = (stack)->next;
			free (stack);
			stack = temp;
		}
		*lst = NULL;
	}
}

t_ps_list	*puton_min(t_ps_list *stack)
{
	while (!is_min(stack, stack->content))
	{
		if (wich_rotate(stack))
			stack = rotate_a(stack, 1);
		else
			stack = rrotate_a(stack, 1);
	}
	return (stack);
}
