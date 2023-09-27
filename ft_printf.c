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

int	ft_printf(const char *format, ...)
{
	int i;
	va_list lista;
	int broj;

	va_start(lista, format);
	broj = va_arg(lista, int);
	broj =va_arg(lista, int);
	i = 0;
	while(format[i] != '\0')
	{
		write(1, &format[i], sizeof(char));
		i++;
	}
	ft_putnbr_fd(broj, 1);
	return (i);
}