#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;
	new = *alst;
	while (new->next != NULL)
	{
		ft_lstdelone(&new, del);
		new = new->next;
	}
	*alst = NULL;
}
