/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:56:21 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/06 13:01:12 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	ret;

	ret = write(1, &c, 1);
	if (ret < 0)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	size_t	i;
	int		ret;

	i = 0;
	if (str == NULL)
	{
		ret = write(1, "(null)", 6);
		if (ret < 0)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		ret = write(1, &str[i], 1);
		if (ret < 0)
			return (-1);
		i++;
	}
	return (i);
}
