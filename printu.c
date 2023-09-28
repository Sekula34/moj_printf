/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:55:33 by fseles            #+#    #+#             */
/*   Updated: 2023/09/28 16:55:34 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printu(va_list lista)
{
	unsigned int number; 

	number = va_arg(lista, unsigned int);
	putunbr_fd(number, 1);
}

