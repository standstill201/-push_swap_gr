/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:12:27 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 09:12:55 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list **a)
{
	int	a_f;
	int	a_s;
	int	a_t;

	a_f = (*a)->content;
	a_s = (*a)->next->content;
	a_t = (*a)->next->next->content;
	if (a_f < a_t && a_f < a_s && a_s > a_t)
	{
		reverse_rotate(a, 'a');
		swap_a(*a);
	}
	else if (a_f < a_t && a_f > a_s && a_s < a_t)
		swap_a(*a);
	else if (a_f > a_t && a_f < a_s && a_s > a_t)
		reverse_rotate(a, 'a');
	else if (a_f > a_t && a_f > a_s && a_s < a_t)
		rotate(a, 'a');
	else if (a_f > a_s && a_f > a_s && a_s > a_t)
	{
		swap_a(*a);
		reverse_rotate(a, 'a');
	}
}

void	sort_four_2(t_list **a, t_list **b, int index)
{
	if (index == 0)
		push_b(a, b);
	else if (index == 3)
	{
		reverse_rotate(a, 'a');
		push_b(a, b);
	}
	else if (index == 1)
	{
		rotate(a, 'a');
		push_b(a, b);
	}
	else if (index == 2)
	{
		reverse_rotate(a, 'a');
		reverse_rotate(a, 'a');
		push_b(a, b);
	}
}

void	sort_four(t_list **a, t_list **b)
{
	int		min;
	int		index;
	t_list	*curr;

	curr = *a;
	index = 0;
	min = (*a)->content;
	while (curr)
	{
		if (curr->content < min)
			min = curr->content;
		curr = curr->next;
	}
	curr = *a;
	while (curr)
	{
		if (curr->content == min)
			break ;
		curr = curr->next;
		index++;
	}
	sort_four_2(a, b, index);
	sort_three(a);
	push_a(a, b);
}

void	sort_five_2(t_list **a, t_list **b, int index)
{
	if (index == 0)
		push_b(a, b);
	else if (index == 4)
	{
		reverse_rotate(a, 'a');
		push_b(a, b);
	}
	else if (index == 1)
	{
		rotate(a, 'a');
		push_b(a, b);
	}
	else if (index == 2)
	{
		rotate(a, 'a');
		rotate(a, 'a');
		push_b(a, b);
	}
	else if (index == 3)
	{
		reverse_rotate(a, 'a');
		reverse_rotate(a, 'a');
		push_b(a, b);
	}
}

void	sort_five(t_list **a, t_list **b)
{
	int		min;
	int		index;
	t_list	*curr;

	curr = *a;
	index = 0;
	min = (*a)->content;
	while (curr)
	{
		if (curr->content < min)
			min = curr->content;
		curr = curr->next;
	}
	curr = *a;
	while (curr)
	{
		if (curr->content == min)
			break ;
		curr = curr->next;
		index++;
	}
	sort_five_2(a, b, index);
	sort_four(a, b);
	push_a(a, b);
}
