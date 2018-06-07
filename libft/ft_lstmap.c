#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	while (lst->next != NULL)
	{
		new = f(lst);
		lst = lst->next;
		new = new->next;
	}
}
