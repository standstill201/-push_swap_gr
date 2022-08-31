#include "push_swap.h"

int	set_pv1(t_list *a)
{
	t_list	*curr;
	int		min;
	int		max;

	curr = a;
	min = ft_atoi(a->content);
	max = ft_atoi(a->content);
	while (curr)
	{
		if (min > ft_atoi(curr->content))
			min = ft_atoi(curr->content);
		else if (max < ft_atoi(curr->content))
			max = ft_atoi(curr->content);
		curr = curr->next;
	}
	return (min + ((max - min) / 3));
}

int	set_pv2(t_list *a)
{
	t_list	*curr;
	int		min;
	int		max;

	curr = a;
	min = ft_atoi(a->content);
	max = ft_atoi(a->content);
	while (curr)
	{
		if (min > ft_atoi(curr->content))
			min = ft_atoi(curr->content);
		else if (max < ft_atoi(curr->content))
			max = ft_atoi(curr->content);
		curr = curr->next;
	}
	return (min + ((max - min) / 3 * 2));
}

int	set_bg_pv(t_list *a)
{
	int		pv1;
	int		count;
	t_list	*curr;

	count = 0;
	curr = a;
	pv1 = set_pv2(a);
	while (1)
	{
		while (curr)
		{
			if (pv1 >= ft_atoi(curr->content))
				count++;
			curr = curr->next;
		}
		if (count == ft_lstsize(a) / 3 * 2)
			return (pv1);
		else if (count < ft_lstsize(a) / 3 * 2)
			pv1++;
		else if (count > ft_lstsize(a) / 3 * 2)
			pv1--;
		count = 0;
		curr = a;
	}
	return (pv1);
}

int	set_sm_pv(t_list *a)
{
	int		pv1;
	int		count;
	t_list	*curr;

	count = 0;
	curr = a;
	pv1 = set_pv1(a);
	while (1)
	{
		while (curr)
		{
			if (pv1 >= ft_atoi(curr->content))
				count++;
			curr = curr->next;
		}
		if (count == ft_lstsize(a) / 3)
			return (pv1);
		else if (count < ft_lstsize(a) / 3)
			pv1++;
		else if (count > ft_lstsize(a) / 3)
			pv1--;
		count = 0;
		curr = a;
	}
	return (pv1);
}

//int	set_max(t_list **a)
//{
//	t_list	*curr;
//	int		max;

//	curr = *a;
//	max = ft_atoi((*a)->content);
//	while (curr)
//	{
//		if (max < ft_atoi(curr->content))
//			max = ft_atoi((curr)->content);
//		curr = curr->next;
//	}
//	return (max);
//}
//int	set_min(t_list **a)
//{
//	t_list	*curr;
//	int		min;

//	curr = *a;
//	min = ft_atoi((*a)->content);
//	}
//	return (min);
//}

void	dv_three(t_list **a, t_list **b)
{
	int	size;
	int	bg_pv;
	int	sm_pv;

	bg_pv = set_bg_pv(*a);
	sm_pv = set_sm_pv(*a);
	size = ft_lstsize(*a);
	while (ft_lstsize(*a) > size / 3 + 1)
	{
		if (ft_atoi((*a)->content) <= bg_pv && ft_atoi((*a)->content) >= sm_pv)
			push_b(a, b);
		else if (ft_atoi((*a)->content) < sm_pv)
		{
			push_b(a, b);
			rotate(b, 'b');
		}
		else if (ft_atoi((*a)->content) > bg_pv)
			rotate(a, 'a');
	}
	while ((*a))
		push_b(a, b);
}
