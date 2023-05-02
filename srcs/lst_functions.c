/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:04:31 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/01/20 18:22:00 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_lstsize_ps(t_ps_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_front_ps(t_ps_list **lst, t_ps_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_ps_list	*ft_lstnew_ps(int content)
{
	t_ps_list	*res;

	res = (t_ps_list *)malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

t_ps_list	*ft_lstlast_ps(t_ps_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ps(t_ps_list **lst, t_ps_list *new)
{
	t_ps_list	*last;

	if (!*lst)
	{
		ft_lstadd_front_ps(lst, new);
		return ;
	}
	last = ft_lstlast_ps(*lst);
	last->next = new;
}
