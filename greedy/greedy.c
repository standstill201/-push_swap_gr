/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:49:17 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 10:33:02 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*find_nom_b(t_list *b)
{
	t_list	*curr;
	int		index;
	int		size;
	int		*return_arr;

	size = ft_lstsize(b);
	return_arr = (int *)malloc(sizeof(int) * size);
	curr = b;
	index = 0;
	while (curr)
	{
		if (index <= size / 2)
			return_arr[index] = index + 1;
		else
			return_arr[index] = size - index + 1;
		index++;
		curr = curr->next;
	}
	return (return_arr);
}

void	case_max(t_list *a, int *lst, int index)
{
	t_list	*curr;
	int		index_a;

	curr = a;
	index_a = 0;
	if (sort_checker(a))
		return ;
	else
	{
		while (curr)
		{
			if (curr->content == ft_lstmax(a))
				break ;
			curr = curr->next;
			index_a++;
		}
		if (index_a > ft_lstsize(a) / 2)
			lst[index] = lst[index] + ft_lstsize(a) - index_a + 1;
		else
			lst[index] = lst[index] + index_a + 1;
	}
}

void	case_min(t_list *a, int *lst, int index)
{
	t_list	*curr;
	int		index_a;

	curr = a;
	index_a = 0;
	if (sort_checker(a))
		return ;
	else
	{
		while (curr)
		{
			if (curr->content == ft_lstmin(a))
				break ;
			curr = curr->next;
			index_a++;
		}
		if (index_a > ft_lstsize(a) / 2)
			lst[index] = lst[index] + ft_lstsize(a) - index_a + 1;
		else
			lst[index] = lst[index] + index_a + 1;
	}
}

void	case_max_min(t_list *a, int b_content, int *lst, int index)
{
	if (b_content > ft_lstmax(a))
		case_max(a, lst, index);
	else
		case_min(a, lst, index);
}

void	case_middle(t_list *a, int b_content, int *lst, int index)
{
	t_list	*curr;
	int		index_a;

	index_a = 0;
	curr = a;
	while (curr)
	{
		if (curr->content < b_content && b_content < curr->next->content
			&& sort_checker_range(a, index_a, index_a + 1))
		{
			if (index_a > ft_lstsize(a) / 2)
				lst[index] = lst[index] + ft_lstsize(a) - index_a + 1;
			else
				lst[index] = lst[index] + index_a + 1;
			break ;
		}
		curr = curr->next;
		index_a++;
	}
}
