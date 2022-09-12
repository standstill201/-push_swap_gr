/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:07:23 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 10:17:21 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	set_pv1(t_list *a)
{
	t_list	*curr;
	int		min;
	int		max;

	curr = a;
	min = a->content;
	max = a->content;
	while (curr)
	{
		if (min > curr->content)
			min = curr->content;
		else if (max < curr->content)
			max = curr->content;
		curr = curr->next;
	}
	return (min + ((max - min) / 3));
}

int	set_pv2(t_list *a)
{
	t_list	*curr;
	int		min;
	int		max;

	curr = a;
	min = a->content;
	max = a->content;
	while (curr)
	{
		if (min > curr->content)
			min = curr->content;
		else if (max < curr->content)
			max = curr->content;
		curr = curr->next;
	}
	return (min + ((max - min) / 3 * 2));
}

int	set_bg_pv(t_list *a)
{
	int		pv1;
	int		count;
	t_list	*curr;

	count = 0;
	curr = a;
	pv1 = set_pv2(a);
	while (1)
	{
		while (curr)
		{
			if (pv1 >= curr->content)
				count++;
			curr = curr->next;
		}
		if (count == ft_lstsize(a) / 3 * 2)
			return (pv1);
		else if (count < ft_lstsize(a) / 3 * 2)
			pv1++;
		else if (count > ft_lstsize(a) / 3 * 2)
			pv1--;
		count = 0;
		curr = a;
	}
	return (pv1);
}

int	set_sm_pv(t_list *a)
{
	int		pv1;
	int		count;
	t_list	*curr;

	count = 0;
	curr = a;
	pv1 = set_pv1(a);
	while (1)
	{
		while (curr)
		{
			if (pv1 >= curr->content)
				count++;
			curr = curr->next;
		}
		if (count == ft_lstsize(a) / 3)
			return (pv1);
		else if (count < ft_lstsize(a) / 3)
			pv1++;
		else if (count > ft_lstsize(a) / 3)
			pv1--;
		count = 0;
		curr = a;
	}
	return (pv1);
}

void	sort_last(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 5)
		push_b(a, b);
	sort_five(a, b);
}
