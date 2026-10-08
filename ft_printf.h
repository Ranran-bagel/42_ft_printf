/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wezhou <wezhou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:29:55 by wezhou            #+#    #+#             */
/*   Updated: 2026/05/06 13:07:48 by wezhou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf_ar(char c, va_list args);
int	ft_printf_ar_back(char c, va_list args);
int	ret_error(int *len, int ret, va_list args);
int	int_add_count(int *count, int ret);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putnbr_unsi(unsigned int nb);
int	ft_puthex(unsigned int nb, char *base);
int	ft_putlhex(unsigned long nb, char *base);
int	ft_putaddr(void	*p);
int	ft_printf(const char *str, ...);

#endif
