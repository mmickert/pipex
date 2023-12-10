/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:27:09 by mickert           #+#    #+#             */
/*   Updated: 2023/10/21 17:34:29 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include "libft.h"
// #include <stdio.h>

// // A custom function to print the content of a list node
// void print_content(void *content)
// {
//     printf("Content: %s\n", (char *)content);
// }

// int main(void)
// {
//     // Create a linked list with some content
//     t_list *list = ft_lstnew("First Node");
//     ft_lstadd_back(&list, ft_lstnew("Second Node"));
//     ft_lstadd_back(&list, ft_lstnew("Third Node"));

//     // Use ft_lstiter to print the content of each node
//     printf("Printing list contents:\n");
//     ft_lstiter(list, print_content);

//     // Clean up the memory by freeing the list nodes
//     while (list)
//     {
//         t_list *temp = list;
//         list = list->next;
//         free(temp);
//     }

//     return 0;
// }