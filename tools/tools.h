/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:01:45 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/09/12 09:14:24 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdlib.h>
# include "../push_swap_struct.h"
# include "../define_macro.h"

char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *string);
long	ft_atoi(const char *str);
t_list	*ft_lstnew(int val);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
int		ft_lstmax(t_list *lst);
int		ft_lstmin(t_list *lst);
int		sort_checker(t_list *a);
int		sort_checker_range(t_list *a, int start, int end);
size_t	ft_strlcpy(char *dst, const char *src, size_t maxsize);

#endif