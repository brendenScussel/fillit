/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:30:46 by bscussel          #+#    #+#             */
/*   Updated: 2019/07/20 21:06:17 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	valid3(const char *p)
{
	t_var	c;

	c.i = 0;
	while (p != '\0')
	{
		c.d = 0;
		c.nl = 0;
		while (c.nl != 4)
		{
			(p[c.i] == '.') ? c.d++ : 0;
			(p[c.i] == '\n' || p[c.i] == '\0') ? c.nl++ : 0;
			if ((c.nl == 4) && (c.d != 12))
				err_prog("", 1, "error");
			c.i++;
		}
		if (p[c.i] == '\0')
			break ;
		c.i++;
	}
	return ;
}

void	valid2(const char *p, int start, int end)
{
	t_var	t;

	t.i = start;
	t.j = 0;
	while (t.i < end)
	{
		if (p[t.i] == '#')
		{
			if (t.i + 1 <= end && p[t.i + 1] == '#')
				t.j++;
			if (t.i - 1 >= start && p[t.i - 1] == '#')
				t.j++;
			if (t.i + 5 <= end && p[t.i + 5] == '#')
				t.j++;
			if (t.i - 5 >= start && p[t.i - 5] == '#')
				t.j++;
		}
		t.i++;
	}
	if (t.j == 6 || t.j == 8)
		return ;
	else
		err_prog("", 1, "error");
}

void	valid1(char *p, int rd, int *np)
{
	t_var	c;

	c.d = 0;
	c.h = 0;
	c.i = 0;
	c.j = 19;
	while (c.i < rd)
	{
		if (p[c.i] != '.' && p[c.i] != '#' && \
		p[c.i] != '\n' && p[c.i] != '\0')
			err_prog("", 1, "error");
		c.i++;
		if (c.i == c.j)
		{
			valid2(p, c.h, c.j);
			c.h = c.h + 21;
			c.j = c.j + 21;
			np[0]++;
		}
	}
	valid3(p);
}
