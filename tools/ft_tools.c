/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:55:10 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 09:13:38 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

long	ft_atoi(const char *str)
{
	int		sign;
	long	return_value;

	return_value = 0;
	sign = 1;
	while (*str == '\n' || *str == '\t' || *str == '\f' || *str == '\r'
		|| *str == '\v' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		return_value = return_value * 10 + *str - '0';
		str++;
	}
	if (return_value > 2147483647 || return_value < -2147483648)
		return (NAI);
	return (return_value * sign);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_addr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_addr = ft_lstlast(*lst);
	last_addr -> next = new;
}

t_list	*ft_lstnew(int val)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node -> content = val;
	new_node -> next = NULL;
	return (new_node);
}

char	*ft_strchr(const char *s, int c)
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
		index++;
	}
	if (c == '\0')
		return ((char *)s + index);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t maxsize)
{
	size_t	size;
	size_t	index;

	index = 0;
	size = ft_strlen(src);
	if (!maxsize)
		return (size);
	while (index < size && index + 1 < maxsize && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (size);
}
