/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 09:53:11 by bscussel          #+#    #+#             */
/*   Updated: 2019/05/05 13:11:50 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;
	int		j;

	ch = (char)c;
	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == ch)
			j = i;
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	if (j == -1)
		return (NULL);
	return ((char *)(s + j));
}
