/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:34 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 10:19:38 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_small(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 5)
		sort_five(a, b);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 3)
		sort_three(a);
	else if (size < 3)
	{
		if (size == 2)
		{
			if ((*a)->content > (*a)->next->content)
				swap_a(*a);
			else
				return ;
		}
		else if (size < 1)
			return ;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	parsing(&a, av);
	if (ft_lstsize(a) < 6)
	{
		case_small(&a, &b);
		return (0);
	}
	dv_three(&a, &b);
	greedy(&a, &b);
	return (0);
}
