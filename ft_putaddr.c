/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:33:52 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/06 13:05:35 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlhex(unsigned long nb, char *base)
{
	int	count;
	int	ret;

	count = 0;
	if (nb >= 16)
	{
		ret = ft_putlhex(nb / 16, base);
		if (int_add_count(&count, ret) < 0)
			return (-1);
	}
	ret = ft_putchar(base[nb % 16]);
	if (int_add_count(&count, ret) < 0)
		return (-1);
	return (count);
}

int	ft_putaddr(void	*p)
{
	unsigned long	addr;
	size_t			len;
	int				ret;

	len = 0;
	if (p == NULL)
	{
		ret = ft_putstr("(nil)");
		if (ret < 0)
			return (-1);
		return (ret);
	}
	addr = (unsigned long)p;
	ret = ft_putstr("0x");
	if (ret < 0)
		return (-1);
	len += ret;
	ret = ft_putlhex(addr, "0123456789abcdef");
	if (ret < 0)
		return (-1);
	len += ret;
	return (len);
}

// #include <stdio.h>

// int main(void)
// {
// 	int n = 0;
// 	ft_putaddr(&n);
// 	write(1, "\n", 1);
// 	printf("%p\n", &n);
// }