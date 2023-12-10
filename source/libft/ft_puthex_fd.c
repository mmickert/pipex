/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:07:49 by mickert           #+#    #+#             */
/*   Updated: 2023/10/24 17:25:14 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexlow_fd(unsigned long long n, int fd, size_t count)
{
	unsigned long	hex_n;
	char			buffer[16];
	char			c;
	int				index;

	index = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		count++;
	}
	while (n > 0)
	{
		hex_n = n % 16;
		if (hex_n < 10)
			c = hex_n + '0';
		else
			c = hex_n - 10 + 'a';
		buffer[index++] = c;
		n /= 16;
	}
	count = ft_puthex_fd(fd, count, index, buffer);
	return (count);
}

int	ft_puthex_fd(int fd, size_t count, int index, char *buffer)
{
	while (index > 0)
	{
		write(fd, &buffer[--index], 1);
		count++;
	}
	return (count);
}

int	ft_puthexup_fd(unsigned long long n, int fd, size_t count)
{
	unsigned long	hex_n;
	char			buffer[16];
	char			c;
	int				index;

	index = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		count++;
	}
	while (n > 0)
	{
		hex_n = n % 16;
		if (hex_n < 10)
			c = hex_n + '0';
		else
			c = hex_n - 10 + 'A';
		buffer[index++] = c;
		n /= 16;
	}
	count = ft_puthex_fd(fd, count, index, buffer);
	return (count);
}

// int	ft_puthexlow_fd(unsigned long long n, int fd, size_t count)
// {
// 	char	c;

// 	if (n == 0)
// 	{
// 		write(fd, "0", 1);
// 		count++;
// 	}
// 	if (n >= 16)
// 	{
// 		count = ft_puthexlow_fd((n / 16), fd, count);
// 		count = ft_puthexlow_fd((n % 16), fd, count);
// 	}
// 	else
// 	{
// 		if (n <= 9)
// 		{
// 			write(fd, (n + '0'), 1);
// 		}
// 		else
// 		{
// 			write(fd, (n + '0' + 32), 1);
// 			count++;
// 		}
// 	}
// 	return (count);
// }

// int	ft_strcmp(const char *s1, const char *s2)
// {
// 	unsigned char	*st1;
// 	unsigned char	*st2;

// 	st1 = (unsigned char *) s1;
// 	st2 = (unsigned char *) s2;
// 	while (*st1 && *st2)
// 	{
// 		st1++;
// 		st2++;
// 	}
// 	return (*(unsigned char *)s1 - *(unsigned char *)s2);
// }

// int	ft_puthexptr_fd(unsigned long long n, int fd, size_t count)
// {
// 	char	*hex_digits;
// 	char	c;
// 	int		digits[16];
// 	int		i;
// 	int		j;

// 	i = 0;
// 	hex_digits = "0123456789abcdef";
// 	if (n == 0)
// 	{
// 		write(fd, "0", 1);
// 		count++;
// 	}
// 	else
// 	{
// 		while (n > 0)
// 		{
// 			digits[i] = n % 16;
// 			n /= 16;
// 			i++;
// 		}
// 		j = i - 1;
// 		while (j >= 0)
// 		{
// 			c = hex_digits[digits[j]];
// 			write(fd, &c, 1);
// 			count++;
// 			j--;
// 		}
// 	}
// 	return (count);
// }