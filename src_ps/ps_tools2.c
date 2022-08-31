#include "push_swap.h"

int	how_much_sorted(t_list *or)
{
	int		return_val;
	t_list	*curr;

	curr = or;
	return_val = 1;
	if (ft_atoi(curr->content) < ft_atoi(curr->next->content))
	{
		while (curr->next && ft_atoi(curr->content) < ft_atoi(curr->next->content))
		{
			curr = curr->next;
			return_val++;
		}
	}
	return (return_val);
}

int	sort_checker(t_list *a)
{
	t_list	*curr;

	if (!a)
		return (0);
	curr = a;
	if (ft_atoi(curr->content) < ft_atoi(curr->next->content))
	{
		while (curr->next)
		{
			if (ft_atoi(curr->content) > ft_atoi(curr->next->content))
				return (0);
			curr = curr->next;
		}
	}
	else
		return (0);
	return (1);
}