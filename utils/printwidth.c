/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printwidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:49:02 by epilar            #+#    #+#             */
/*   Updated: 2020/12/14 11:16:39 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printwidth(t_struct *list)
{
	while (list->width > 0)
	{
		if (list->zero && (!list->dot || list->prec < 0))
			list->printed += write(1, "0", 1);
		else
			list->printed += write(1, " ", 1);
		list->width--;
	}
}
