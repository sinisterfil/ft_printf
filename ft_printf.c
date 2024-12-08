/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbayram <hbayram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:23:00 by hbayram           #+#    #+#             */
/*   Updated: 2024/11/08 10:55:39 by hbayram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_form(char current, va_list args)
{
	int		count;
	void	*ptr;

	count = 0;
	if (current == 'c')
		count = count + print_char(va_arg(args, int));
	else if (current == 's')
		count = count + print_string(va_arg(args, char *));
	else if (current == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			return (write(1, "(nil)", 5));
		count = count + print_string("0x");
		count = count + print_void((unsigned long)ptr, 16);
	}
	else
		count += print_form2(current, args);
	return (count);
}

int	print_form2(char current, va_list args)
{
	int	count;

	count = 0;
	if (current == 'd')
		count = count + print_digit(va_arg(args, int), 10, current);
	else if (current == 'i')
		count = count + print_digit(va_arg(args, int), 10, current);
	else if (current == 'u')
		count = count + print_digit(va_arg(args, unsigned int), 10, current);
	else if (current == 'x')
		count = count + print_digit(va_arg(args, unsigned int), 16, current);
	else if (current == 'X')
		count = count + print_digit(va_arg(args, unsigned int), 16, current);
	else
	{
		count++;
		write(1, &current, 1);
	}
	return (count);
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, form);
	while (*form != '\0')
	{
		if (*form == '%')
			count = count + print_form(*(++form), args);
		else
			count = count + write(1, form, 1);
		form++;
	}
	va_end(args);
	return (count);
}
