#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new, *temp;
	new = *alst;
	while (new->next != NULL)
	{
		temp = new->next;
		ft_lstdelone(&new, del);
		new = temp;
	}
	ft_lstdelone(&new, del);
	*alst = NULL;
}
