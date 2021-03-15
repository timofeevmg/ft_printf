/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpercent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:58:16 by epilar            #+#    #+#             */
/*   Updated: 2020/12/14 17:26:16 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		printzerospace(t_struct *list)
{
	while (list->width > 0)
	{
		if (list->zero)
			list->printed += write(1, "0", 1);
		else
			list->printed += write(1, " ", 1);
		list->width--;
	}
}

void			ifpercent(t_struct *list)
{
	list->width--;
	if (list->minus == 0)
	{
		printzerospace(list);
		list->printed += write(1, "%", 1);
	}
	else
	{
		list->printed += write(1, "%", 1);
		printzerospace(list);
	}
}
