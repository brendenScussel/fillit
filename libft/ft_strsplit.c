/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:01:23 by bscussel          #+#    #+#             */
/*   Updated: 2019/05/02 19:08:44 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char		*ft_substrdup(const char *s1, char c)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	j = 0;
	while (s1[j] && s1[j] != c)
		j++;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (j + 1))))
		return (NULL);
	i = 0;
	while (j--)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int		ft_substrcount(char const *s, char c)
{
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	if (!s)
		return (0);
	while (*s)
	{
		if (flag && *s != c)
		{
			flag = 0;
			i += 1;
		}
		else if (!flag && *s == c)
			flag = 1;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		substr;
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	substr = ft_substrcount(s, c);
	if (!(result = (char **)malloc(sizeof(*result) * (substr + 1))))
		return (NULL);
	while (i < substr)
	{
		while (s[j] == c && s[j])
			j++;
		result[i] = ft_substrdup((s + j), c);
		i++;
		while (s[j] != c && s[j])
			j++;
	}
	result[i] = NULL;
	return (result);
}
