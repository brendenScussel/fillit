/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:40:20 by bscussel          #+#    #+#             */
/*   Updated: 2019/05/02 18:42:53 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dptr;
	const char	*sptr;
	size_t		dlen;

	dptr = dst;
	sptr = src;
	while (*dptr && dstsize)
	{
		dptr++;
		dstsize--;
	}
	dlen = dptr - dst;
	if (!dstsize)
		return (ft_strlen(src) + dlen);
	while (*sptr && dstsize-- > 1)
		*dptr++ = *sptr++;
	while (*sptr)
		sptr++;
	*dptr = '\0';
	return (dlen + (sptr - src));
}
