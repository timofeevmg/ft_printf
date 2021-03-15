/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifunsign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:35:36 by epilar            #+#    #+#             */
/*   Updated: 2020/12/14 17:08:50 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		preparewidth(t_struct *list, int num, int rank)
{
	if (num == 0 && list->dot && !list->prec)
		list->width++;
	list->width = (list->width > rank) ? (list->width - rank) : 0;
}

static void		printdecimal(t_struct *list, unsigned long int nl, int rank)
{
	char	*s;
	int		i;

	if (nl == 0 && list->dot && !list->prec)
		return ;
	if (!(s = (char *)malloc(sizeof(char) * (rank))))
	{
		list->error = 1;
		return ;
	}
	i = 0;
	while (i <= (rank - 1))
	{
		s[i] = nl % 10 + 48;
		nl /= 10;
		i++;
	}
	while (--i >= 0)
		list->printed += write(1, &s[i], 1);
	free(s);
}

void			ifunsign(t_struct *list, unsigned int num)
{
	unsigned long int	nl;
	int					rank;
	int					base;

	base = 10;
	nl = (num < 0) ? (4294967296 + num) : num;
	rank = (num == 0) ? 1 : getrank(num, base);
	rank = (list->prec > rank) ? list->prec : rank;
	preparewidth(list, num, rank);
	if (list->minus == 0)
	{
		printwidth(list);
		printdecimal(list, num, rank);
	}
	else
	{
		printdecimal(list, num, rank);
		printwidth(list);
	}
}
