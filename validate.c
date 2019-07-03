#include "fillit.h"

/*
** check if the tetriminos are valid
*/

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
		end_prg("ERROR");
}

/*
** check for false characters.
*/

void		valid1(char *p, int rd, int *np)
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
			end_prg("ERROR");
		(p[c.i] == '.') ? c.d++ : 0;
		c.i++;
		if (c.i == c.j)
		{
			valid2(p, c.h, c.j);
			c.h = c.h + 21;
			c.j = c.j + 21;
			np[0]++;
		}
	}
	(c.d != 12 * np[0]) ? end_prg("ERROR") : 0;
}