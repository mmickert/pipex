/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:07:03 by mickert           #+#    #+#             */
/*   Updated: 2023/11/13 13:05:44 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define TRUE 1
# define FALSE 0

int	ft_printf(const char *format, ...);
int	ft_putunsignednbr_fd(unsigned int n, int fd, size_t count);
int	ft_puthexlow_fd(unsigned long long n, int fd, size_t count);
int	ft_puthexup_fd(unsigned long long n, int fd, size_t count);
int	ft_putcharprintf_fd(char c, int fd, size_t count);
int	ft_putnbrprintf_fd(int n, int fd, size_t count);
int	ft_putstrprintf_fd(char *s, int fd, size_t count);
int	ft_putpointer_fd(size_t ptr, int fd, size_t count);
int	ft_puthexptr_fd(unsigned long long n, int fd, size_t count);
int	ft_puthex_fd(int fd, size_t count, int index, char *buffer);

#endif