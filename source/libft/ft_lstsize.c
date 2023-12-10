/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:41:59 by mickert           #+#    #+#             */
/*   Updated: 2023/10/20 15:35:15 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// #include <stdio.h>

// int	main()
// {
// 	char	*content;
// 	char	*n_content;
// 	t_list	*list;
// 	t_list	*n_list;
// 	int		len;

// 	content = "Hello, World!";
// 	n_content = "I'm Mona";
// 	list = ft_lstnew(content);
// 	n_list = ft_lstnew(n_content);
// 	ft_lstadd_front(&list, n_list);
// 	len = ft_lstsize(list);
// 	printf("%d", len);
// 	free(list);
// 	return (0);
// }