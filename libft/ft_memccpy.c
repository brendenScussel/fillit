/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:58:30 by bscussel          #+#    #+#             */
/*   Updated: 2019/05/02 18:13:37 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;
	int				i;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		*(dptr + i) = *(sptr + i);
		if (*(dptr + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
