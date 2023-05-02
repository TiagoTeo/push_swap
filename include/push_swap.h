/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:04:29 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:45:45 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

# ifndef STR_INT_MAX
#  define STR_INT_MAX "2147483647"
# endif

# ifndef STR_INT_MIN
#  define STR_INT_MIN "-2147483648"
# endif

typedef struct ps_list
{
	int				content;
	struct ps_list	*next;
}					t_ps_list;

typedef struct s_minmax
{
	int				max;
	int				min;
	int				size;
	int				med;
}					t_minmax;

typedef struct s_ultpb
{
	int				nbr;
	int				size;
}					t_ultpb;

void		ft_print_lst(t_ps_list *stack);

// movement functions stack a
void		swap_a(t_ps_list *stack);
void		push_a(t_ps_list **stack_1, t_ps_list **stack_2);
t_ps_list	*rotate_a(t_ps_list *stack, int flag);
t_ps_list	*rrotate_a(t_ps_list *stack, int flag);

// movement functions stack b
void		swap_b(t_ps_list *stack);
void		push_b(t_ps_list **stack_1, t_ps_list **stack_2);
t_ps_list	*rotate_b(t_ps_list *stack, int flag);
t_ps_list	*rrotate_b(t_ps_list *stack, int flag);

// movement functions at the same time
void		ss(t_ps_list *stack_a, t_ps_list *stack_b);
void		rr(t_ps_list **stack_a, t_ps_list **stack_b);
void		rrr(t_ps_list **stack_a, t_ps_list **stack_b);

//checks
void		ft_check_arg(int ac, char **av);
void		ft_check_cha(int ac, char **av);
void		ft_check_limits(char *str);
void		ft_check_dups(int ac, char **av, int i, int j);
t_minmax	*ft_check_mm(t_ps_list *stack_a);

//utils
void		ft_print_error(void);
int			ft_atoi(const char *str);
char		**ft_split(char const *str, char c);
int			ft_wordcount(char *str, char c);

//choose_solve
t_ps_list	*ft_choose_solve(t_ps_list *stack_a);

//is functions
int			is_prev(t_ps_list *stack, int current, int prev);
int			is_next(t_ps_list *stack, int current, int next);
int			is_org(t_ps_list *stack);
int			is_desorg(t_ps_list *stack);
int			wich_rotate(t_ps_list *stack);

//is 2
int			is_min(t_ps_list *stack, int min);
int			is_max(t_ps_list *stack, int max);
int			is_almost_org(t_ps_list *stack);

//lst Functions
int			ft_lstsize_ps(t_ps_list *lst);
void		ft_lstadd_front_ps(t_ps_list **lst, t_ps_list *new);
t_ps_list	*ft_lstnew_ps(int content);
t_ps_list	*ft_lstlast_ps(t_ps_list *lst);
void		ft_lstadd_back_ps(t_ps_list **lst, t_ps_list *new);

//lst Functions 2
t_ps_list	*ft_lst_dup(t_ps_list *stack);
void		ft_lstclear_ps(t_ps_list **lst);
t_ps_list	*puton_min(t_ps_list *stack);

//simulate
int			sim_rotate_min(t_ps_list *stack);
int			sim_rrotate_min(t_ps_list *stack);
int			find_med(t_ps_list *stack_a, int size);

//ultimate push a
void		ultimate_push_a(t_ps_list **stack_a, t_ps_list **stack_b);

//ultimate push a 2
int			wich_rotate_ult_a(t_ps_list *stack_a, t_ps_list *stack_b, \
			int *cur_b);
int			wich_rotate_ult_a_b(t_ps_list *original_b, int *cur_b);

//ultimate push a 3
int			f_ult_a_next(int current, t_ps_list *stack_a);
int			sim_ult_pa_2(t_ps_list *stack_a, t_ps_list *stack_b);
int			sim_ult_pa_1(t_ps_list *stack_a, t_ps_list *stack_b);

//ultimate push b
void		ultimate_push_b(t_ps_list **stack_a, t_ps_list **stack_b);
int			lst_last(t_ps_list *lst);
int			get_value_ultpb(t_ps_list *stack, int nbr);
void		get_sequence_ultpb(t_ps_list *stack, t_ps_list **sequence);
t_ps_list	*find_ultpb(t_ps_list *stack_a);

//ultimate push b 2
int			check_sequence(t_ps_list *seq, int nbr);
int			get_min_ultpb(t_ps_list *stack, t_ps_list *sequence, \
			t_ps_list *group, int *flag);
t_ps_list	*find_group(t_ps_list *stack, t_ps_list *sequence);
int			check_group(t_ps_list *stack, t_ps_list *group);

//ultimate push b 3
int			rot_a_ultpb(t_ps_list *temp, t_ps_list *group, int *i);
int			rot_b_ultpb(t_ps_list *stack_b, int nbr);
void		one_push_b(t_ps_list **stack_a, t_ps_list **stack_b, \
			int rot_a, int nbr);

//ultimate push b 4
int			descobrir_chunks(int size);

#endif