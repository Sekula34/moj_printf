/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:07:26 by fseles            #+#    #+#             */
/*   Updated: 2023/09/29 10:07:27 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*hexa_string(unsigned long number, int option)
{
	char		*string;
	const char	*digits = "0123456789abcdef";
	long long	i;

	i = 0;
	string = ft_calloc(21, sizeof(char));
	if (string == NULL)
		return (NULL);
	if (number == 0)
	{
		string[0] = '0';
		return (string);
	}
	while (number > 0)
	{
		string[i] = digits[number % 16];
		if (option == 1)
			string[i] = ft_toupper(string[i]);
		i++;
		number = number / 16;
	}
	return (string);
}

void	printx(va_list lista, int option)
{
	unsigned int	number;
	char			*to_print;
	int				i;

	number = va_arg(lista, unsigned int);
	to_print = hexa_string(number, option);
	if (to_print == NULL)
		return ;
	i = ft_strlen(to_print);
	ft_putstr_fd("0x", 1);
	while (i >= 0)
	{
		ft_putchar_fd(to_print[i], 1);
		i--;
	}
	free(to_print);
}
