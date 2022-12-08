/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumpedfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:54:26 by dminerva          #+#    #+#             */
/*   Updated: 2021/05/18 00:54:26 by dminerva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	dumpedfile(t_all *s, char *fname, char	**dumpf)
{
	int		i;
	int		cnt;
	int		fd;
	char	tmp[BUFERSIZE + 1];

	cnt = 0;
	fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error : Couldn't open file (FD)\n", 32);
		exit(0);
	}
	i = 1;
	while (i != 0)
	{
		i = read(fd, tmp, BUFERSIZE);
		cnt += i;
	}
	*dumpf = malloc(sizeof(char) * cnt + 1);
	fd = open(fname, O_RDONLY);
	read(fd, *dumpf, cnt);
	close(fd);
	dumpf[0][cnt] = '\0';
	return (cnt);
}

void	map_map(char *str, t_all *s, int *i)
{
	if (str[*i] == ' ' || str[*i] == '1' || str[*i] == '0')
	{
		*i = mapcnt(s, str, 0);
		getmap(str, s);
	}
	if (str[*i] == 'R' && str[*i + 1] == ' ')
		*i += get_res(&str[*i + 2], s, 0);
	else if (str[*i] == 'N' && str[*i + 1] == 'O' && str[*i + 2] == ' ')
		*i += gettexture(s, &s->tex.no, &s->tex.noptr, &str[*i + 3]) + 3;
	else if (str[*i] == 'S' && str[*i + 1] == 'O' && str[*i + 2] == ' ')
		*i += gettexture(s, &s->tex.so, &s->tex.soptr, &str[*i + 3]) + 3;
	else if (str[*i] == 'W' && str[*i + 1] == 'E' && str[*i + 2] == ' ')
		*i += gettexture(s, &s->tex.we, &s->tex.weptr, &str[*i + 3]) + 3;
	else if (str[*i] == 'E' && str[*i + 1] == 'A' && str[*i + 2] == ' ')
		*i += gettexture(s, &s->tex.ea, &s->tex.eaptr, &str[*i + 3]) + 3;
	else if (str[*i] == 'S' && str[*i + 1] == ' ')
		*i += gettexture(s, &s->tex.s, &s->tex.sptr, &str[*i + 2]) + 2;
	else if (str[*i] == 'F' && str[*i + 1] == ' ')
		*i += getcolor(s, &str[*i + 1], &s->tex.c) + 1;
	else if (str[*i] == 'C' && str[*i + 1] == ' ')
		*i += getcolor(s, &str[*i + 1], &s->tex.f) + 1;
}

int	parse(char *str, t_all *s)
{
	int	i;

	i = 0;
	s->err.err_line = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r')
		i++;
	map_map(str, s, &i);
	if (s->err.err_line == 0)
		print_error(s);
	return (i);
}

void	parsestart(t_all *s, char *av)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	dumpedfile(s, av, &str);
	tmp = &str[i];
	i += parse(tmp, s);
	while (str[i] != '\0')
	{
		tmp = &str[i];
		i += parse(tmp, s);
	}
	map_aproov(s);
	fil_one(s);
	cub_slist(s);
	free(str);
}

void	fil_one(t_all *s)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < s->map.y)
	{
		while (s->map.map[y][++x] != '\0')
		{
			if (s->map.map[y][x] == ' ')
				s->map.map[y][x] = '1';
			if (s->map.map[y][x] == 'N' || s->map.map[y][x] == 'W' \
				|| s->map.map[y][x] == 'S' || s->map.map[y][x] == 'E')
				s->map.map[y][x] = '0';
		}
		x = -1;
	}
}
