#include <libft.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;
	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = malloc(content_size + 1);
	if (content == 0)
	{
		new->content = 0;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	else
		ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
