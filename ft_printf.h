/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:28:14 by epilar            #+#    #+#             */
/*   Updated: 2020/12/14 17:04:32 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

# define ALLSYMBOLS "cspdiuxX%-.*0123456789"

typedef struct		s_struct
{
	char			*format;
	unsigned int	printed;
	int				i;
	int				minus;
	int				zero;
	int				dot;
	int				width;
	int				prec;
	int				error;
}					t_struct;

int					ft_printf(const char *arg, ...);
int					parser(char *format, t_struct *list, va_list *ap, int pos);
void				printwidth(t_struct *list);
void				checknegwidth(t_struct *list);
int					getrank(unsigned long int nl, int base);
void				initstruct(const char *format, t_struct *list);
void				clearstruct(t_struct *list);
void				ifchar(t_struct *list, va_list *ap);
void				ifstring(t_struct *list, char *s);
void				ifpointer(t_struct *list, unsigned long long num);
void				ifdecint(t_struct *list, long num);
void				ifunsign(t_struct *list, unsigned int num);
void				ifhex(t_struct *list, unsigned int num, char c);
void				ifpercent(t_struct *list);

#endif
