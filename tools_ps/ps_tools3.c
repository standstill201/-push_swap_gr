/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:11:05 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 09:12:15 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_or_b(t_list **a, t_list **b, char c)
{
	t_list	*temp;

	temp = *a;
	if (!temp)
		return ;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
