/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:32:37 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 10:41:52 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "push_swap_struct.h"
# include "define_macro.h"
# include "./tools/tools.h"

t_list	*ft_lstlast_before(t_list *lst);
void	reverse_rotate(t_list **or, char c);
void	rotate(t_list **or, char c);
void	swap_a(t_list *a);
void	swap_b(t_list *a);
void	swap_a_or_b(t_list *a, char c);
void	push_b(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_a_or_b(t_list **a, t_list **b, char c);
void	print_node(t_list *a);
// part_of_tools

void	sort_five(t_list **a, t_list **b);
void	sort_four(t_list **a, t_list **b);
void	sort_three(t_list **a);
void	case_small(t_list **a, t_list **b);
// part_of_small

void	parsing(t_list **a, char **av);
// parsing

int		set_bg_pv(t_list *a);
void	sort_last(t_list **a, t_list **b);
int		set_sm_pv(t_list *a);
void	dv_three(t_list **a, t_list **b);
// dividing

void	case_max_min(t_list *a, int b_content, int *lst, int index);
void	case_middle(t_list *a, int b_content, int *lst, int index);
int		*find_nom_b(t_list *b);
void	greedy(t_list **a, t_list **b);
void	move_a(t_list **a, int index_a);
int		move_b(t_list **b, int index);
int		*find_nom_n(t_list **a, t_list **b);
void	case_max_move(t_list **a);
int		min_finder(t_list **a, t_list **b);
void	now_move(t_list **a, t_list **b, int index);
// greedy

#endif
