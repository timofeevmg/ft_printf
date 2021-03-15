/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearstruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:19:36 by epilar            #+#    #+#             */
/*   Updated: 2020/12/08 17:20:16 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	clearstruct(t_struct *list)
{
	list->minus = 0;
	list->zero = 0;
	list->dot = 0;
	list->width = 0;
	list->prec = 0;
}
