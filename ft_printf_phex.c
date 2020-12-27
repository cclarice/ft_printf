/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_phex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:39:05 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/27 19:56:30 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_putox(unsigned long n, unsigned long long d)
{
	ft_putchar('0');
	ft_putchar('x');
	if (n == 0 && d == 0)
		return (2);
	return (0);
}

int		ft_pre_phex(t_frmt *s)
{
	if (s->z >= 1 && s->d > s->z)
		s->z += 2;
	else if (s->z > s->l && s->d == MIN)
		s->z -= 2;
	if (s->d >= 1)
		s->d += 2;
	return (2);
}

int		ft_in_phex(void)
{
	ft_putchar('0');
	ft_putchar('x');
	return (0);
}

int		ft_printf_phex(t_frmt *s, unsigned long long n)
{
	if ((s->l = ft_hexlen(n) + ft_pre_phex(&(*s))) != MIN && s->m != MIN)
	{
		s->p += ft_in_phex() + ft_pz((long)s->d - s->l);
		n == 0 && s->d == 0 && s->m != 0 && s->m != 0 ? s->p += ft_ps(1) : 0;
		n != 0 || s->d != 0 ? ft_puthex(n, 'p') : 0;
		s->p += ft_ps((long)s->m - s->l - (s->d > s->l ? s->d - s->l : 0));
	}
	else if (s->z != MIN)
	{
		if (s->d != MIN)
			s->p += ft_ps((long)s->z - s->l - (s->d > s->l ? s->d - s->l : 0));
		n == 0 && s->d == 0 && s->z != 0 ? s->p += ft_ps(1) : 0;
		ft_in_phex();
		s->p += ft_pz((long)s->d != MIN ? s->d - s->l : s->z - (s->l - 2));
		n != 0 || s->d != 0 ? ft_puthex(n, 'p') : 0;
	}
	else
	{
		s->p += ft_ps((long)s->n - s->l - (s->d > s->l ? s->d - s->l : 0));
		ft_in_phex();
		s->p += ft_pz((long)s->d - s->l);
		n == 0 && s->d == 0 && s->n != 0 && s->n != MIN ? s->p += ft_ps(1) : 0;
		n != 0 || s->d != 0 ? ft_puthex(n, 'p') : 0;
	}
	return (s->p += s->d != 0 || n != 0 ? s->l : 2);
}
