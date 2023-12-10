/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:15:14 by mickert           #+#    #+#             */
/*   Updated: 2023/11/12 12:19:19 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char *format, va_list args, size_t i, size_t count);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count = ft_format((char *)format, args, i, count);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	ft_format(char *format, va_list args, size_t i, size_t count)
{
	if (format[i] == 'c')
		return (ft_putcharprintf_fd((char)va_arg(args, int), 1, count));
	else if (format[i] == 's')
		count = ft_putstrprintf_fd(va_arg(args, char *), 1, count);
	else if (format[i] == 'p')
		count = ft_putpointer_fd(va_arg(args, size_t), 1, count);
	else if (format[i] == 'i' || format[i] == 'd')
		count = ft_putnbrprintf_fd(va_arg(args, int), 1, count);
	else if (format[i] == 'u')
		count = ft_putunsignednbr_fd(va_arg(args, unsigned int), 1, count);
	else if (format[i] == 'x')
		count = ft_puthexlow_fd(va_arg(args, unsigned int), 1, count);
	else if (format[i] == 'X')
		count = ft_puthexup_fd(va_arg(args, unsigned int), 1, count);
	else if (format[i] == '%' && format[i++] == '%')
	{
		write(1, "%", 1);
		i--;
		count++;
	}
	return (count);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	int	i;
// 	int richtig;

// 	i = ft_printf("mein output:%%);
// 	richtig = printf("richtig ist:%%);
// 	printf("mein return: %d\n", i);
// 	printf("richtig ist: %d\n", richtig);
// 	return (0);
// }

//add retunr -1 if write == -1 to everywhere.
