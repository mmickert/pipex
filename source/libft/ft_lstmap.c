/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:38:40 by mickert           #+#    #+#             */
/*   Updated: 2023/12/02 14:45:31 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*free_function(t_list *transformed_lst,
void *transformed_content, void (*del)(void *))
{
	if (del)
		del(transformed_content);
	ft_lstclear(&transformed_lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*transformed_lst;
	t_list	*transformed_nod;
	void	*transformed_content;

	while (lst)
	{
		transformed_content = f(lst->content);
		if (transformed_content == NULL)
		{
			free_function(transformed_lst, transformed_content, del);
			return (NULL);
		}
		transformed_nod = ft_lstnew(transformed_content);
		if (transformed_nod == NULL)
		{
			free_function(transformed_lst, transformed_content, del);
			return (NULL);
		}
		ft_lstadd_back(&transformed_lst, transformed_nod);
		lst = lst->next;
	}
	return (transformed_lst);
}

// #include <stdio.h>
// #include <stdlib.h>

// void *duplicate_content(void *content)
// {
//     char *original = (char *)content;
//     char *duplicate = ft_strdup(original);
//     return duplicate;
// }

// // Deletion function for testing (frees a string)
// void custom_del(void *content)
// {
//     free(content);
// }

// int main(void)
// {
//     // Create an original list
//     t_list *original_list = ft_lstnew("Hello");
//     ft_lstadd_back(&original_list, ft_lstnew("World"));

//     // Create a new list by duplicating content
//     t_list *new_list = ft_lstmap
//(original_list, duplicate_content, custom_del);

//     if (new_list)
//     {
//         // Print the content of the new list
//         t_list *current = new_list;
//         while (current)
//         {
//             printf("%s\n", (char *)current->content);
//             current = current->next;
//         }

//         // Clear the new list
//         ft_lstclear(&new_list, custom_del);
//     }

//     // Clear the original list
//     ft_lstclear(&original_list, custom_del);

//     return 0;
// }