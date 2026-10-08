/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:11:50 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/04 21:41:39 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_add_count(int *count, int ret)
{
	if (ret < 0)
		return (-1);
	else
		*count += ret;
	return (1);
}

int	ft_putnbr(int nb)
{
	int		count;
	int		ret;
	long	n;

	n = nb;
	count = 0;
	if (n < 0)
	{
		ret = ft_putchar('-');
		if (int_add_count(&count, ret) < 0)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		ret = ft_putnbr(n / 10);
		if (int_add_count(&count, ret) < 0)
			return (-1);
	}
	ret = ft_putchar(n % 10 + '0');
	if (int_add_count(&count, ret) < 0)
		return (-1);
	return (count);
}

int	ft_putnbr_unsi(unsigned int nb)
{
	int	count;
	int	ret;

	count = 0;
	if (nb >= 10)
	{
		ret = ft_putnbr_unsi(nb / 10);
		if (int_add_count(&count, ret) < 0)
			return (-1);
	}
	ret = ft_putchar(nb % 10 + '0');
	if (int_add_count(&count, ret) < 0)
		return (-1);
	return (count);
}

int	ft_puthex(unsigned int nb, char *base)
{
	int	count;
	int	ret;

	count = 0;
	if (nb >= 16)
	{
		ret = ft_puthex(nb / 16, base);
		if (int_add_count(&count, ret) < 0)
			return (-1);
	}
	ret = ft_putchar(base[nb % 16]);
	if (int_add_count(&count, ret) < 0)
		return (-1);
	return (count);
}

// #include <stdio.h>
// int main(void)
// {
// 	int n = ft_putnbr(255);
// 	write(1, "\n", 1);
// 	ft_putnbr(n);
// }

// int main(void)
// {
// 	unsigned int n = ft_putnbr_unsi(-1);

// 	printf("\n%d\n", n);
// 	printf("%u\n", -1);
// }

// int main(void)
// {
// 	unsigned int n = 255;

// 	int s = ft_puthex(n, "0123456789abcdef");
// 	printf("\n%d\n", s);
// }