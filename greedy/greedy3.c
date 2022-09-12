/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:32:25 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 10:32:37 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_min_move(t_list **a)
{
	t_list	*curr;
	int		index_a;

	index_a = 0;
	curr = *a;
	if (sort_checker(*a))
		return ;
	else
	{
		while (curr)
		{
			if (curr->content == ft_lstmin(*a))
				break ;
			curr = curr->next;
			index_a++;
		}
		if (index_a > ft_lstsize(*a) / 2)
			index_a = ft_lstsize(*a) - index_a;
		else
			index_a = (index_a) * -1;
	}
	move_a(a, index_a);
}

void	move_max_min(t_list **a, int b_val)
{
	if (b_val > ft_lstmax(*a))
		case_max_move(a);
	else
		case_min_move(a);
}

void	move_middle(t_list **a, int b_val)
{
	t_list	*curr;
	int		index_a;

	index_a = 0;
	curr = *a;
	while (curr)
	{
		if (curr->content < b_val && b_val < curr->next->content
			&& sort_checker_range(*a, index_a, index_a + 1))
		{
			if (index_a > ft_lstsize(*a) / 2)
				index_a = ft_lstsize(*a) - index_a - 1;
			else
				index_a = -1 * (index_a + 1);
			break ;
		}
		curr = curr->next;
		index_a++;
	}
	move_a(a, index_a);
}

void	now_move(t_list **a, t_list **b, int index)
{
	int	b_val;

	b_val = move_b(b, index);
	if (b_val > ft_lstmax(*a) || b_val < ft_lstmin(*a))
		move_max_min(a, b_val);
	else if (ft_lstlast(*a)->content < b_val && b_val < (*a)->content)
	{
		push_a(a, b);
		return ;
	}
	else
		move_middle(a, b_val);
	push_a(a, b);
}

int	min_finder(t_list **a, t_list **b)
{
	int	*min_nom_n;
	int	index;
	int	min;

	min_nom_n = find_nom_n(a, b);
	index = 1;
	min = min_nom_n[0];
	while (min_nom_n[index])
	{
		if (min > min_nom_n[index])
			min = min_nom_n[index];
		index++;
	}
	index = 0;
	while (min_nom_n[index])
	{
		if (min_nom_n[index] == min)
			break ;
		index++;
	}
	return (index);
}
