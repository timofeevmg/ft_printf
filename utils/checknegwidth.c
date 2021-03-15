/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknegwidth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 15:57:08 by epilar            #+#    #+#             */
/*   Updated: 2020/12/12 17:07:01 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	checknegwidth(t_struct *list)
{
	if (list->width < 0)
	{
		list->width = -list->width;
		list->minus = 1;
		list->zero = 0;
	}
}
