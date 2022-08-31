#include "push_swap.h"

int main(int argc, char **argv)
{
	int index;
	t_list *a;
	t_list *b;
	t_list *add_fr;
	
	b = NULL;
	if (ft_strchr(argv[1], ' '))
	{
		char **temp = ft_split(argv[1], ' ');
		index = 1;
		a = ft_lstnew((char *)temp[0]);
		while (temp[index])
		{
			add_fr = ft_lstnew(temp[index]);
			ft_lstadd_back(&a, add_fr);
			index++;
		}
	}
	else
	{
		a = ft_lstnew((char *)argv[1]);
		index = 2;
		while (index < argc)
		{
			add_fr = ft_lstnew(argv[index]);
			ft_lstadd_back(&a, add_fr);
			index++;
		}
	}
	//dv_three(&a, &b);
	//print_node(a);
	printf("%d\n",sort_checker(a));
}