/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_push_a_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:34:50 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 20:10:26 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	wich_rotate_ult_a_aux_aux(t_ps_list *temp_a, t_ps_list **temp_b, t_ps_list \
*stack_b)
{
	int	res;

	res = 1;
	while (temp_a && temp_a->next)
	{
		temp_b = &stack_b;
		while (*temp_b)
		{
			if (temp_a->content < (*temp_b)->content && \
			temp_a->next->content > (*temp_b)->content)
				break ;
			(*temp_b) = (*temp_b)->next;
		}
		if (*temp_b)
			break ;
		res++;
		temp_a = temp_a->next;
	}
	return (res);
}

int	wich_rotate_ult_a_aux(t_ps_list *stack_a, t_ps_list *stack_b, int *cur_b)
{
	t_ps_list	*temp_a;
	t_ps_list	**temp_b;
	t_ps_list	**head;
	int			res;

	temp_a = ft_lst_dup(stack_a);
	head = malloc(sizeof(t_ps_list *));
	*head = temp_a;
	temp_b = &stack_b;
	res = wich_rotate_ult_a_aux_aux(temp_a, temp_b, stack_b);
	if (res != ft_lstsize_ps(stack_a) && *temp_b)
		*cur_b = (*temp_b)->content;
	ft_lstclear_ps(head);
	free(head);
	return (res);
}

int	wich_rotate_ult_a_aux_2(t_ps_list *stack_a, t_ps_list *stack_b, \
int *cur_b, int res)
{
	t_ps_list	*temp_a;
	t_ps_list	*temp_b;
	int			temp;

	temp = 1;
	temp_a = ft_lst_dup(stack_a);
	while (temp_a && temp_a->next)
	{
		temp_b = stack_b;
		while (temp_b)
		{
			if (temp_a->content < temp_b->content && temp_a->next->content > \
			temp_b->content)
				break ;
			temp_b = temp_b->next;
		}
		if (temp_b)
			break ;
		temp--;
		temp_a = rrotate_a(temp_a, 1);
	}
	ft_lstclear_ps(&temp_a);
	if (temp_b && (temp * -1) < res)
		*cur_b = temp_b->content;
	return (temp);
}

int	wich_rotate_ult_a(t_ps_list *stack_a, t_ps_list *stack_b, int *cur_b)
{
	int			res;
	int			temp;

	res = wich_rotate_ult_a_aux(stack_a, stack_b, cur_b);
	if (res == ft_lstsize_ps(stack_a))
		return (res);
	temp = wich_rotate_ult_a_aux_2(stack_a, stack_b, cur_b, res);
	if ((temp * -1) < res)
		return (temp);
	return (res);
}

int	wich_rotate_ult_a_b(t_ps_list *original_b, int *cur_b)
{
	int			res;
	int			temp;
	t_ps_list	*stack_b;
	t_ps_list	*start;

	res = 0;
	temp = 0;
	stack_b = ft_lst_dup(original_b);
	start = stack_b;
	while (stack_b && *cur_b != stack_b->content)
	{
		stack_b = stack_b->next;
		res++;
	}
	stack_b = start;
	while (stack_b && *cur_b != stack_b->content)
	{
		stack_b = rrotate_b(stack_b, 1);
		temp--;
	}
	ft_lstclear_ps(&stack_b);
	if ((temp * -1) < res)
		return (temp);
	return (res);
}
