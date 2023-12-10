/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:37:25 by mickert           #+#    #+#             */
/*   Updated: 2023/10/20 15:52:03 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h>

// int	main()
// {
// 	char	*content;
// 	char	*n_content;
// 	t_list	*list;
// 	t_list	*n_list;
// 	t_list	*last;
// 	int		len;

// 	content = "Hello, World!";
// 	n_content = "I'm Mona";
// 	list = ft_lstnew(content);
// 	n_list = ft_lstnew(n_content);
// 	ft_lstadd_front(&n_list, list);
// 	len = ft_lstsize(list);
// 	printf("List size:%d\n", len);
// 	last = ft_lstlast(list);
// 	printf("%s", (char *)last->content);
// 	free(list);
// 	return (0);
// }