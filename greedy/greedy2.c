/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:31:40 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 10:32:47 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_nom_a(t_list *a, t_list *b, int *lst)
{
	t_list	*curr_b;
	int		index;

	index = 0;
	curr_b = b;
	while (curr_b)
	{
		if (curr_b->content > ft_lstmax(a) || curr_b->content < ft_lstmin(a))
			case_max_min(a, curr_b->content, lst, index);
		else if (ft_lstlast(a)->content < curr_b->content
			&& curr_b->content < a->content)
			lst[index] = lst[index] + 0;
		else
			case_middle(a, curr_b->content, lst, index);
		curr_b = curr_b->next;
		index++;
	}
}

int	*find_nom_n(t_list **a, t_list **b)
{
	int		*return_val;

	return_val = find_nom_b(*b);
	find_nom_a(*a, *b, return_val);
	return (return_val);
}

int	move_b(t_list **b, int index)
{
	int	size;

	size = ft_lstsize(*b);
	if (index <= size / 2)
	{
		while (index)
		{
			rotate(b, 'b');
			index--;
		}
	}
	else
	{
		index = size - index;
		while (index)
		{
			reverse_rotate(b, 'b');
			index--;
		}
	}
	return ((*b)->content);
}

void	move_a(t_list **a, int index_a)
{
	if (index_a < 0)
	{
		index_a = index_a * -1;
		while (index_a)
		{
			rotate(a, 'a');
			index_a--;
		}
	}
	else
	{
		while (index_a)
		{
			reverse_rotate(a, 'a');
			index_a--;
		}
	}
}

void	case_max_move(t_list **a)
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
			if (curr->content == ft_lstmax(*a))
				break ;
			curr = curr->next;
			index_a++;
		}
		if (index_a > ft_lstsize(*a) / 2)
			index_a = ft_lstsize(*a) - index_a - 1;
		else
			index_a = (index_a + 1) * -1;
	}
	move_a(a, index_a);
}
