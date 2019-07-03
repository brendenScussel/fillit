/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:19:40 by bscussel          #+#    #+#             */
/*   Updated: 2019/05/02 19:06:49 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char		*ft_strldup(const char *s1, int i)
{
	int		j;
	char	*ptr;

	j = 0;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		ptr[j] = s1[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char			*ft_strtrim(char const *s)
{
	int		bgn;
	int		i;
	int		end;

	if (!s)
		return (NULL);
	bgn = -1;
	i = 0;
	end = -2;
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
		if (s[i])
			bgn = i;
		while (s[i])
		{
			if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
				end = i;
			i++;
		}
	}
	return (ft_strldup(s + bgn, end - bgn + 1));
}
