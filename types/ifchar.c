/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifchar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:35:04 by epilar            #+#    #+#             */
/*   Updated: 2020/12/08 17:17:07 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ifchar(t_struct *list, va_list *ap)
{
	int		count;
	char	c;

	count = 1;
	if (list->minus == 0)
	{
		while (--list->width >= 1)
			count += write(1, " ", 1);
		c = va_arg(*ap, int);
		write(1, &c, 1);
	}
	else
	{
		c = va_arg(*ap, int);
		write(1, &c, 1);
		while (--list->width >= 1)
			count += write(1, " ", 1);
	}
	list->printed += count;
}
