/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:57:39 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 17:55:44 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_ps_list	*create_stack_a(char **av)
{
	int			temp;
	int			i;
	t_ps_list	*stack_a;

	i = 0;
	stack_a = NULL;
	while (av[i])
	{
		temp = ft_atoi(av[i]);
		ft_lstadd_back_ps(&stack_a, ft_lstnew_ps(temp));
		i++;
	}
	return (stack_a);
}

void	free_the_fuck_up(t_ps_list *stack_a, char **strs, int flag)
{
	t_ps_list	*temp;
	int			i;

	i = 0;
	while (stack_a)
	{
		temp = (stack_a)->next;
		free (stack_a);
		stack_a = temp;
	}
	if (flag)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

int	main(int ac, char **av)
{
	t_ps_list	*stack_a;
	int			flag;

	flag = 0;
	if (ac == 1 || !av[1][0])
		return (0);
	else if (ac == 2)
	{
		ac = ft_wordcount(av[1], ' ');
		av = ft_split(av[1], ' ');
		ft_check_arg(ac, av);
		flag = 1;
		stack_a = create_stack_a(av);
	}
	else
	{
		ft_check_arg(--ac, ++av);
		stack_a = create_stack_a(av);
	}
	stack_a = ft_choose_solve(stack_a);
	free_the_fuck_up(stack_a, av, flag);
}
