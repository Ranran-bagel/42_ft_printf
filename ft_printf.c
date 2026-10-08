/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:29:36 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/06 13:21:09 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ar(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (c == 'p')
		return (ft_putaddr((void *)va_arg(args, void *)));
	else if (c == 's')
		return (ft_putstr((char *)va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsi((unsigned int)va_arg(args, unsigned int)));
	else
		return (ft_printf_ar_back(c, args));
}

int	ft_printf_ar_back(char c, va_list args)
{
	if (c == 'x')
		return (ft_puthex((unsigned int)va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex((unsigned int)va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ret_error(int *len, int ret, va_list args)
{
	if (ret < 0)
	{
		va_end(args);
		return (-1);
	}
	*len += ret;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		ret;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			ret = ft_printf_ar(*(++str), args);
			if (!ret_error(&len, ret, args))
				return (-1);
		}
		else
		{
			ret = ft_putchar(*str);
			if (int_add_count(&len, ret) < 0)
				return (-1);
		}
		str++;
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_printf("%d\nhello\n%s%q %Xwoaini", 20, NULL, 255);
// 	ft_printf("%s", NULL);
// }