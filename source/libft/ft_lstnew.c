/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:05:00 by mickert           #+#    #+#             */
/*   Updated: 2023/10/20 13:08:48 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *c)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->content = c;
	lst->next = NULL;
	return (lst);
}

// #include <stdio.h>

// int main() {
//     // Create a new node with some content (e.g., a string)
//     char *content = "Hello, World!";
//     t_list *node = ft_lstnew(content);

//     if (node) {
//         // Print the content of the newly created node
//         printf("Node Content: %s\n", (char *)node->content);
//         // Check if the next pointer is NULL
//         if (node->next == NULL) {
//             printf("Next pointer is NULL\n");
//         } else {
//             printf("Next pointer is not NULL\n");
//         }

//         // Free the allocated memory for the node
//         free(node);
//     } else {
//         printf("Failed to create a new node.\n");
//     }

//     return 0;
// }