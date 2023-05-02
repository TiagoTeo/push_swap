/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:56:14 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 16:46:30 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!av || !av[0])
		exit(1);
	ft_check_cha(ac, av);
	ft_check_dups(ac, av, i, j);
}

void	ft_check_cha(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	while (j < ac)
	{
		i = 0;
		while (av[j][i] != '\0')
		{
			if (i == 0)
			{
				if ((av[j][i] == '\0') || (av[j][i] != '+' && av[j][i] != '-' \
				&& (av[j][i] < 48 || av[j][i] > 57)))
					ft_print_error();
				else if ((av[j][i] == '+' || av[j][i] == '-') && \
				(av[j][i + 1] < 48 || av[j][i + 1] > 57))
					ft_print_error();
			}
			else if ((av[j][i] > 57 || av[j][i] < 48) && av[j][i] != '\0')
				ft_print_error();
			i++;
		}
		ft_check_limits(av[j]);
		j++;
	}
}

void	ft_check_dups(int ac, char **av, int i, int j)
{
	int	*temp;
	int	t;

	temp = (int *)malloc(sizeof(int) * ac - 1);
	if (!temp)
		return ;
	while (i < ac)
	{
		temp[j] = ft_atoi(av[i]);
		if (j > 1)
		{
			t = 1;
			while (j - t >= 0)
			{
				if (temp[j] == temp[j - t])
					ft_print_error();
				t++;
			}
		}
		i++;
		j++;
	}
	free(temp);
}

void	ft_check_limits(char *str)
{
	int	i;

	i = 0;
	if ((str[i] >= 48 && str[i] <= 57) || str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' && strlen(str) < 11)
			return ;
		else if (str[i] == '-' && strlen(str) == 11 && \
		strncmp(str, STR_INT_MIN, 11) <= 0)
			return ;
		else if (str[i] == '+' && strlen(str) < 10)
			return ;
		else if (str[i] == '+' && strlen(str) == 10 && \
		strncmp(str, STR_INT_MAX, 10) <= 0)
			return ;
		else if (str[i] != '-' && strlen(str) < 10)
			return ;
		else if (str[i] != '-' && strlen(str) == 10 && \
		strncmp(str, STR_INT_MAX, 10) <= 0)
			return ;
	}
	ft_print_error();
}

t_minmax	*ft_check_mm(t_ps_list *stack_a)
{
	static t_minmax	*minmax;
	static int		flag;

	if (!flag)
	{
		minmax = NULL;
		flag = 1;
	}
	if (!minmax)
	{
		minmax = malloc(sizeof(t_minmax));
		minmax->min = stack_a->content;
		minmax->max = stack_a->content;
		minmax->size = ft_lstsize_ps(stack_a);
		minmax->med = find_med(stack_a, minmax->size);
		while (stack_a)
		{
			if (minmax->min > stack_a->content)
				minmax->min = stack_a->content;
			if (minmax->max < stack_a->content)
				minmax->max = stack_a->content;
			stack_a = stack_a->next;
		}
	}
	return (minmax);
}
