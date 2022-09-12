/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:21:23 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 09:14:04 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	return_val;

	return_val = 0;
	while (lst)
	{
		return_val++;
		lst = lst -> next;
	}
	return (return_val);
}

int	ft_lstmax(t_list *lst)
{
	int		max;
	t_list	*curr;

	curr = lst;
	max = lst->content;
	while (curr)
	{
		if (max < curr->content)
			max = curr->content;
		curr = curr->next;
	}
	return (max);
}

int	ft_lstmin(t_list *lst)
{
	int		min;
	t_list	*curr;

	curr = lst;
	min = lst->content;
	while (curr)
	{
		if (min > curr->content)
			min = curr->content;
		curr = curr->next;
	}
	return (min);
}

int	sort_checker(t_list *a)
{
	t_list	*curr;

	if (!a)
		return (0);
	if (ft_lstsize(a) == 1)
		return (1);
	curr = a;
	if (curr->content < curr->next->content)
	{
		while (curr->next)
		{
			if (curr->content > curr->next->content)
				return (0);
			curr = curr->next;
		}
	}
	else
		return (0);
	return (1);
}
