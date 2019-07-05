/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:04:58 by bscussel          #+#    #+#             */
/*   Updated: 2019/05/02 18:02:56 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memalloc(size_t size)
{
	void			*vptr;
	unsigned char	*chptr;

	if (!(vptr = (void *)malloc(sizeof(*vptr) * size)))
		return (NULL);
	chptr = (unsigned char *)vptr;
	while (size--)
		*chptr++ = (unsigned char)0;
	return (vptr);
}
