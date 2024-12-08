/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbayram <hbayram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:22:51 by hbayram           #+#    #+#             */
/*   Updated: 2024/11/08 11:04:30 by hbayram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_form(char current, va_list args);
int	print_form2(char current, va_list args);
int	ft_printf(const char *form, ...);
int	print_char(int c);
int	print_string(char *str);
int	print_digit(long n, int base, char current);
int	print_void(unsigned long n, unsigned long base);

#endif
