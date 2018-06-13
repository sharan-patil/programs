#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new, *temp;
	if (!lst)
		return (NULL);
	new = (t_list*)malloc(sizeof(lst));
	if (!new)
		return (NULL);
	temp = f(lst);
	new = temp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp->next = f(lst);
		temp = temp->next;
	}
	return (new);
}
