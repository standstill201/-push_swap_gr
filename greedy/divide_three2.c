/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_three2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:16:49 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 10:21:08 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	dv_three(t_list **a, t_list **b)
{
	int	size;
	int	bg_pv;
	int	sm_pv;
	int	index;

	index = 0;
	bg_pv = set_bg_pv(*a) + 1;
	sm_pv = set_sm_pv(*a);
	size = ft_lstsize(*a);
	while (ft_lstsize(*a) > size / 3 + 1 || index < size)
	{
		if ((*a)->content <= bg_pv && (*a)->content >= sm_pv)
			push_b(a, b);
		else if ((*a)->content < sm_pv)
		{
			push_b(a, b);
			rotate(b, 'b');
		}
		else if ((*a)->content > bg_pv)
			rotate(a, 'a');
		index++;
	}
	if (ft_lstsize(*a) > 5)
		sort_last(a, b);
	case_small(a, b);
}
