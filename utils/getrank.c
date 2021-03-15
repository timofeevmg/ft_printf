/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getrank.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:58:59 by epilar            #+#    #+#             */
/*   Updated: 2020/12/08 17:16:30 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		getrank(unsigned long int nl, int base)
{
	int		rank;

	rank = 0;
	while (nl > 0)
	{
		nl /= base;
		rank++;
	}
	return (rank);
}
