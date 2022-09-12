/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:51:51 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 09:07:59 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_overlap(t_list **a, int val)
{
	t_list	*curr;

	curr = *a;
	while (curr)
	{
		if (curr->content == val)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	index_plus(int val)
{
	int	return_val;

	return_val = 0;
	if (val == 0)
		return (1);
	if (val < 0)
		return_val++;
	while (val)
	{
		val = val / 10;
		return_val++;
	}
	return (return_val);
}

long	parsing2(t_list **a, char *av)
{
	int		index;
	long	val;

	index = 0;
	while (av[index])
	{
		val = ft_atoi(av + index);
		if (is_overlap(a, val) || val == NAI)
			return (ERR);
		index += index_plus(val);
		while (av[index] == '\n' || av[index] == '\t'
			|| av[index] == '\f' || av[index] == '\r'
			|| av[index] == '\v' || av[index] == ' ')
			index++;
		ft_lstadd_back(a, ft_lstnew(val));
		if (!av[index])
			return (0);
		else if (!(av[index] > '0' && av[index] <= '9'))
			return (ERR);
		index++;
	}
	return (0);
}

void	free_nodes(t_list **a)
{
	t_list	*temp;

	while (*a)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
}

void	parsing(t_list **a, char **av)
{
	int		index;
	long	trigger_err;

	index = 1;
	while (av[index])
	{
		trigger_err = parsing2(a, av[index]);
		if (trigger_err == ERR)
		{
			write(1, "Error\n", 6);
			free_nodes(a);
			return ;
		}
		index++;
	}
}
