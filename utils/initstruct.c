/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:30:48 by epilar            #+#    #+#             */
/*   Updated: 2020/12/14 17:04:53 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	initstruct(const char *format, t_struct *list)
{
	list->format = (char *)format;
	list->printed = 0;
	list->i = 0;
	list->minus = 0;
	list->zero = 0;
	list->dot = 0;
	list->width = 0;
	list->prec = 0;
	list->error = 0;
}
