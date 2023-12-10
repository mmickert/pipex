/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:09:09 by mickert           #+#    #+#             */
/*   Updated: 2023/10/20 14:44:39 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	size_t	i;

	i = 0;
	if (lst != NULL && new != NULL)
	{
		new->next = lst[i];
		lst[i] = new;
	}
}

// #include <stdio.h>

// int main() {
// 	// Create a linked list with three nodes
// 	t_list *node1 = ft_lstnew("Node 1");
// 	t_list *node2 = ft_lstnew("Node 2");
// 	t_list *node3 = ft_lstnew("Node 3");

// 	// Initialize the list with the first node
// 	t_list *list = node1;
//     // Print the initial list
//     printf("Initial List:\n");
//     t_list *current = list;
//     while (current) {
//         printf("%s\n", (char *)current->content);
//         current = current->next;
//     }

//     // Add a new node to the front of the list
//     t_list *newNode = ft_lstnew("New Node");
//     ft_lstadd_front(&list, newNode);

//     // Print the updated list
//     printf("\nUpdated List:\n");
//     current = list;
//     while (current) {
//         printf("%s\n", (char *)current->content);
//         current = current->next;
//     }

//     // Free the memory for the list nodes
//     while (list) {
//         t_list *temp = list;
//         list = list->next;
//         free(temp);
//     }

//     return 0;
// }
