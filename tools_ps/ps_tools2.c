/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:08:56 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 09:12:00 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	how_much_sorted(t_list *or)
{
	int		return_val;
	t_list	*curr;

	curr = or;
	return_val = 1;
	if (curr->content < curr->next->content)
	{
		while (curr->next && curr->content < curr->next->content)
		{
			curr = curr->next;
			return_val++;
		}
	}
	return (return_val);
}

int	sort_checker_range2(t_list *a, t_list *curr, int end, int index)
{
	t_list	*temp;
	int		return_val;

	temp = 0;
	while (curr)
	{
		if (index == end)
		{
			temp = curr->next;
			curr->next = 0;
			break ;
		}
		curr = curr->next;
		index++;
	}
	return_val = sort_checker(a);
	curr->next = temp;
	return (return_val);
}

int	sort_checker_range(t_list *a, int start, int end)
{
	t_list	*curr;
	int		return_val;
	int		index;

	index = 0;
	curr = a;
	while (curr)
	{
		if (index == start)
			break ;
		curr = curr->next;
		index++;
	}
	a = curr;
	return_val = sort_checker_range2(a, curr, end, index);
	return (return_val);
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	if (!temp)
		return ;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	if (!temp)
		return ;
	*b = (*b)->next;
	temp -> next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}
