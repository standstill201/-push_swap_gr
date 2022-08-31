#include "push_swap.h"

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
	char	*temp;

	temp = a -> content;
	a -> content = a -> next -> content;
	a -> next -> content = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_list *a)
{
	char	*temp;

	temp = a -> content;
	a -> content = a -> next -> content;
	a -> next -> content = temp;
	write(1, "sb\n", 3);
}

void	swap_a_or_b(t_list *a, char c)
{
	char	*temp;

	temp = a -> content;
	a -> content = a -> next -> content;
	a -> next -> content = temp;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}


void	push_b(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	if (!temp)
		return ;
	*a = (*a) -> next;
	temp -> next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	if (!temp)
		return ;
	*b = (*b) -> next;
	temp -> next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

void	push_a_or_b(t_list **a, t_list **b, char c)
{
	t_list	*temp;

	temp = *a;
	if (!temp)
		return ;
	*a = (*a) -> next;
	temp -> next = *b;
	*b = temp;
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

#include <stdio.h>
void	print_node(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp)
	{
		printf("node: %s\n", (char *)temp->content);
		temp = temp->next;
	}
}