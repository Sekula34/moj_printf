/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:41:05 by fseles            #+#    #+#             */
/*   Updated: 2023/09/27 12:41:10 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	is_valid(char conversion_specifier)
{
	char	valid_set[10];
	int		i;

	i = 0;
	ft_strlcpy(valid_set, "cspdiuxX%", ft_strlen("cspdiuxX%") + 1);
	while (valid_set[i] != '\0')
	{
		if (conversion_specifier == valid_set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	main_menu(char conversion_specifier, va_list a)
{
	if (conversion_specifier == 'c')
		printc(a);
	else if (conversion_specifier == 's')
		prints(a);
	// else if (conversion_specifier == 'p')
	// 	printp(a);
	else if (conversion_specifier == 'd' || conversion_specifier == 'i')
		printdi(a);
	else if (conversion_specifier == 'u')
		printu(a);
	// else if (conversion_specifier == 'x')
	// 	//x function
	// else if (conversion_specifier == 'X')
	// 	//X function
	else if (conversion_specifier == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	lista;

	va_start(lista, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		else
		{
			i++;
			if (!is_valid(format[i]))
				return (-1);
			//dohvati sljedeci argument i pozovi funkciju
			main_menu(format[i], lista);
		}
		i++;
	}
	va_end(lista);
	return (1);
}
