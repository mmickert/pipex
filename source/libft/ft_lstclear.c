/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:02:28 by mickert           #+#    #+#             */
/*   Updated: 2023/10/21 17:24:20 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	if (lst != NULL && del != NULL)
	{
		while (current)
		{
			next = current->next;
			del(current->content);
			free(current);
			current = next;
		}
	}
	*lst = NULL;
}

// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// void custom_del(void *content)
// {
//     if (content != NULL)
//         free(content);
// }

// int main(void)
// {
//     char *content1 = ft_strdup("Hello");
//     char *content2 = ft_strdup("World");
//     t_list *list = ft_lstnew(content1);
//     ft_lstadd_back(&list, ft_lstnew(content2));
//     t_list *current = list;
//     while (current)
//     {
//         printf("%s\n", (char *)current->content);
//         current = current->next;
//     }
//     ft_lstclear(&list, custom_del);
//     return (0);
// }
