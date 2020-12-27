/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 06:56:02 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/27 19:43:28 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_hexlen(unsigned long long n)
{
	int l;

	l = 1;
	while (n /= 16)
		l++;
	return (l);
}

void	ft_puthex(unsigned long long n, char h)
{
	if (h == 'p')
		h = 'x';
	n / 16 ? ft_puthex(n / 16, h) : 0;
	ft_putchar(n % 16 + (n % 16 < 10 ? 48 : h - 33));
}

int		ft_printf_hex(t_frmt *s, unsigned long n, char h)
{
	if ((s->l = ft_hexlen(n)) && s->m != MIN)
	{
		s->p += ft_pz((long)s->d - s->l);
		n == 0 && s->d == 0 && s->m != 0 && s->m != 0 ? s->p += ft_ps(1) : 0;
		n != 0 || s->d != 0 ? ft_puthex(n, h) : 0;
		s->p += ft_ps((long)s->m - s->l - (s->d >= s->l ? s->d - s->l : 0));
	}
	else if (s->z != MIN)
	{
		if (s->d != MIN)
			s->p += ft_ps((long)s->z - s->l - (s->d >= s->l ? s->d - s->l : 0));
		s->p += ft_pz((long)s->d != MIN ? s->d - s->l : s->z - s->l);
		n == 0 && s->d == 0 && s->z != 0 ? s->p += ft_ps(1) : 0;
		n != 0 || s->d != 0 ? ft_puthex(n, h) : 0;
	}
	else
	{
		s->p += ft_ps((long)s->n - s->l - (s->d >= s->l ? s->d - s->l : 0));
		s->p += ft_pz((long)s->d - s->l);
		n == 0 && s->d == 0 && s->n != 0 && s->n != MIN ? s->p += ft_ps(1) : 0;
		n != 0 || s->d != 0 ? ft_puthex(n, h) : 0;
	}
	return (s->p += s->d != 0 || n != 0 ? s->l : 0);
}
