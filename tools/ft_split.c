/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:03:38 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 09:04:02 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

size_t	ft_strlen(const char *string)
{
	size_t	output;

	output = 0;
	while (string[output])
		output++;
	return (output);
}

static size_t	find_len(char const *s, char c)
{
	size_t	index;
	size_t	innr_index;
	size_t	len;

	index = 0;
	len = 0;
	while (s[index])
	{
		if (s[index] == c)
			index++;
		else
		{
			innr_index = 0;
			while (s[innr_index + index] != c && s[innr_index + index])
				innr_index++;
			if (innr_index)
				len++;
			index += innr_index;
		}
	}
	return (len);
}

static void	free_all(char **str, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ((void)0);
}

static void	fill_up(char **return_val, char const *s, char c)
{
	size_t	innr_index;
	size_t	str_i;

	str_i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			innr_index = 0;
			while (s[innr_index] != c && s[innr_index])
				innr_index++;
			return_val[str_i] = (char *)malloc(sizeof(char) * (innr_index + 1));
			if (!return_val[str_i])
				return (free_all(return_val, str_i));
			ft_strlcpy(return_val[str_i], s, innr_index + 1);
			s += innr_index;
			str_i++;
		}
	}
	return_val[str_i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**return_val;

	if (!*s)
	{
		return_val = (char **)malloc(sizeof(char *) * 1);
		if (!return_val)
			return (0);
		return_val[0] = 0;
		return (return_val);
	}
	return_val = (char **)malloc(sizeof(char *) * (find_len(s, c) + 1));
	if (!return_val)
		return (0);
	fill_up(return_val, s, c);
	return (return_val);
}
