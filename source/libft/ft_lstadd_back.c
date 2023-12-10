/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:07:10 by mickert           #+#    #+#             */
/*   Updated: 2023/10/21 16:38:02 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastlst;

	if (lst != NULL && new != NULL)
	{
		lastlst = ft_lstlast(*lst);
		if (lastlst == NULL)
		{
			*lst = new;
		}
		else
		{
			lastlst->next = new;
		}
	}
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
// 	len = ft_lstsize(list);
// 	printf("List size:%d\n", len);
// 	ft_lstadd_back(&list, n_list);
// 	len = ft_lstsize(list);
// 	printf("List size:%d\n", len);
// 	t_list *current = list;
//     while (current)
//     {
//         printf("%s\n", (char *)current->content);
//         current = current->next;
//     }
//     // Free the allocated memory for the list
//     while (list)
//     {
//         t_list *temp = list;
//         list = list->next;
//         free(temp);
//     }
//     return 0;
// }
