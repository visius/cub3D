/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:53:58 by dminerva          #+#    #+#             */
/*   Updated: 2021/05/18 02:49:05 by dminerva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	getmap(char *str, t_all *s)
{
	char		**tmp;
	char		*map;
	t_counters	c;

	c.i = ((s->map.x + 1) * s->map.y);
	map = (char *)malloc(c.i + 1);
	tmp = (char **)malloc(s->map.y * sizeof(char *));
	c.j = -1;
	while (++c.j < c.i)
		map[c.j] = '0';
	c.j = 0;
	while (str[c.j] == '\n' || str[c.j] == '\r')
		c.j++;
	str = &str[c.j];
	c.j = -1;
	while (++c.j < s->map.y)
	{
		c.i = (c.j * s->map.x + c.j);
		tmp[c.j] = &map[c.i];
		map[c.i + s->map.x] = '\0';
		str = writeline(str, &tmp[c.j][0], s, c.j);
	}
	s->map.map = tmp;
	s->err.err_line = 1;
	map_check(s);
}

char	*writeline(char *str, char *map, t_all *s, int y)
{
	int	i;
	int	len;

	i = 0;
	if (str[i] == '\n' || str[i] == '\r')
		i++;
	str = &str[i];
	len = ft_linelen(str, 0);
	i = -1;
	while (++i < len)
	{
		set_transform(str[i], s, i, y);
		if (str[i] != '\n' || str[i] != '\0')
			map[i] = str[i];
		if (str[i] == ' ')
			map[i] = ' ';
	}
	while (i < s->map.x)
		map[i++] = ' ';
	return (&str[len]);
}

int	mapcnt(t_all *s, char *str, int i)
{
	int	tmp;

	s->map.x = 0;
	s->map.y = 0;
	while (str[i] == '\n' || str[i] == '\r')
		i++;
	while (str[i] != '\0')
	{
		tmp = ft_linelen(&str[i], 0);
		i += tmp;
		if (str[i] != '\0')
			i++;
		if (s->map.x < tmp)
			s->map.x = tmp;
		s->map.y++;
	}
	return (i);
}

void	map_aproov(t_all *s)
{
	int	y;

	y = -1;
	while (++y < s->map.y)
	{
		if (s->map.map[y][0] != ' ' && s->map.map[y][0] != '1')
		{
			printf("Error\nError map\n");
			exit(0);
		}
		if (s->err.err_plr == -1)
		{
			printf("Error\nError not player\n");
			exit(0);
		}
	}
}
