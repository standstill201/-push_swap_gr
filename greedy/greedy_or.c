/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:33:12 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 10:33:25 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	greedy(t_list **a, t_list **b)
{
	int		min_index;
	t_list	*curr;
	int		index;

	index = 0;
	while (*b)
	{
		min_index = min_finder(a, b);
		now_move(a, b, min_index);
	}
	curr = *a;
	if (sort_checker(*a))
		return ;
	while (curr)
	{
		if (curr->content > curr->next->content)
			break ;
		index++;
		curr = curr->next;
	}
	if (index > ft_lstsize(*a) / 2)
		index = ft_lstsize(*a) - index - 1;
	else
		index = (index + 1) * -1;
	move_a(a, index);
}
