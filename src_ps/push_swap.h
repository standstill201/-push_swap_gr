#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

#include <stdio.h>

t_list	*ft_lstlast_before(t_list *lst);
void	reverse_rotate(t_list **or, char c);
void	rotate(t_list **or, char c);
void	swap_a(t_list *a);
void	swap_b(t_list *a);
void	swap_a_or_b(t_list *a, char c);
void	push_b(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_a_or_b(t_list **a, t_list **b, char c);

void	dv_three(t_list **a, t_list **b);


void	print_node(t_list *a);


# endif