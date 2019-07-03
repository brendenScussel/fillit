/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:15:33 by bscussel          #+#    #+#             */
/*   Updated: 2019/05/02 18:18:39 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dptr;
	unsigned char *sptr;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	if (dptr < sptr)
		while (len--)
			*(dptr++) = *(sptr++);
	else
		while (len--)
			*(dptr + len) = *(sptr + len);
	return (dst);
}
