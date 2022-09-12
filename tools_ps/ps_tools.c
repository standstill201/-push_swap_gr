/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:08:43 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 09:08:44 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstlast_before(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next -> next)
		lst = lst -> next;
	return (lst);
}

void	reverse_rotate(t_list **or, char c)
{
	t_list	*temp;

	temp = ft_lstlast((*or));
	if (temp == *or)
		return ;
	ft_lstlast_before((*or))->next = NULL;
	temp->next = (*or);
	(*or) = temp;
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rotate(t_list **or, char c)
{
	t_list	*temp;

	if (!(*or)->next)
		return ;
	temp = (*or)->next;
	ft_lstlast((*or))->next = *or;
	(*or)->next = NULL;
	(*or) = temp;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	swap_a(t_list *a)
{
	int	temp;

	temp = a->content;
	a->content = a->next->content;
	a->next->content = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_list *a)
{
	int	temp;

	temp = a->content;
	a->content = a->next->content;
	a->next->content = temp;
	write(1, "sb\n", 3);
}
