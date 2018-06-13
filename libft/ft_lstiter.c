#include <libft.h>

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst)
		return ;
	while (lst->next != NULL)
	{
		f(lst);
		lst = lst->next;
	}
	f(lst);
}
