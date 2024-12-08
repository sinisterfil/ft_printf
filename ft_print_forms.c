/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_forms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbayram <hbayram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:22:36 by hbayram           #+#    #+#             */
/*   Updated: 2024/11/08 10:55:20 by hbayram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_string(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		count = count + print_char((int)*str);
		str++;
	}
	return (count);
}

int	print_digit(long n, int base, char current)
{
	int		count;
	char	*symbol;

	count = 0;
	if (current == 'X')
		symbol = "0123456789ABCDEF";
	else
		symbol = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		count = count + print_digit(-n, base, current) + 1;
	}
	else if (n < base)
	{
		count = count + print_char(symbol[n]);
	}
	else
	{
		count = count + print_digit(n / base, base, current);
		count = count + print_digit(n % base, base, current);
	}
	return (count);
}

int	print_void(unsigned long n, unsigned long base)
{
	int		count;
	char	*symbol;

	count = 0;
	symbol = "0123456789abcdef";
	if (n < base)
	{
		count = count + print_char(symbol[n]);
	}
	else
	{
		count = count + print_void(n / base, base);
		count = count + print_void(n % base, base);
	}
	return (count);
}
