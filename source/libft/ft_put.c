/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:49:31 by mickert           #+#    #+#             */
/*   Updated: 2023/11/12 12:19:51 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharprintf_fd(char c, int fd, size_t count)
{
	if (write(fd, &c, 1) == -1)
	{
		count = -1;
		return (count);
	}
	count++;
	return (count);
}

int	ft_putnbrprintf_fd(int n, int fd, size_t count)
{
	char	c;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11), count + 11);
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
	{
		count = ft_putnbrprintf_fd(n / 10, fd, count);
		c = n % 10 + '0';
		write(fd, &c, 1);
		count++;
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
		count++;
	}
	return (count);
}

int	ft_putstrprintf_fd(char *s, int fd, size_t count)
{
	int		i;

	i = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		count += 6;
		return (count);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_putunsignednbr_fd(unsigned int n, int fd, size_t count)
{
	char	c;

	if (n >= 10)
		count = ft_putunsignednbr_fd(n / 10, fd, count);
	c = n % 10 + '0';
	write(fd, &c, 1);
	count++;
	return (count);
}

int	ft_putpointer_fd(size_t ptr, int fd, size_t count)
{
	char	p_str[17];
	int		i;
	char	*hx;

	write(1, "0x", 2);
	hx = "0123456789abcdef";
	count += 2;
	i = 0;
	if (ptr == 0)
	{
		count = ft_putcharprintf_fd('0', fd, count);
	}
	while (ptr)
	{
		p_str[i] = hx[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		count = ft_putcharprintf_fd(p_str[i], fd, count);
	return (count);
}
