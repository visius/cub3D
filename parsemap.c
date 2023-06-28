#include"cub3d.h"

void	getmap(char *str, t_all *s)
{
	char	**tmp;
	char	*map;
	int		i;
	int		j;

	i = ((s->map.x + 1) * s->map.y);
	map = (char *)malloc(i + 1);
	tmp = (char **)malloc(s->map.y * sizeof(char *));
	j = -1;
	while (++j < i)
		map[j] = '0';
	j = -1;
	while (str[++j] == '\n' || str[j] == '\r');
	str = &str[j];
	j = -1;
	while (++j < s->map.y)
	{
		i = (j * s->map.x + j);
		tmp[j] = &map[i];
		map[i + s->map.x] = '\0';
		str = writeline(str, &tmp[j][0], s, j);
	}
	s->map.map = tmp;
	s->err.err_line = 1;
	map_check(s);
	s->err.err_map = ft_mapcheck1(s);
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
	while (str[++i] == '\n' || str[i] == '\r');
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

void	set_rotation(char c, t_all *s)
{
	if (c == 'E')
		s->pos.rot = 0;
	if (c == 'W')
		s->pos.rot = 90;
	if (c == 'S')
		s->pos.rot = 180;
	if (c == 'N')
		s->pos.rot = 270;
}

void	set_transform(char c, t_all *s, int x, int y)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
	{	
		if (s->err.err_plr == 1)
		{
			printf("Error\nError zamk_mapPPP\n");
			exit(0);
		}
		s->pos.y = y + 0.5;
		s->pos.x = x + 0.5;
		if (s->pos.rot != -1)
			s->err.err_pos = -90;
		set_rotation(c, s);
		s->err.err_plr = 1;
		spawn_dir(s);
	}
}

void	spawn_dir(t_all *s)
{
	if (s->pos.rot == 0)
		s->dir.y = 0;
	if (s->pos.rot == 0)
		s->dir.x = 1;
	if (s->pos.rot == 90)
		s->dir.y = 0;
	if (s->pos.rot == 90)
		s->dir.x = -1;
	if (s->pos.rot == 180)
		s->dir.y = 1;
	if (s->pos.rot == 180)
		s->dir.x = 0;
	if (s->pos.rot == 270)
		s->dir.y = -1;
	if (s->pos.rot == 270)
		s->dir.x = 0;
}

void	map_aproov(t_all *s)
{
	int	y;

	y = -1;
	while (++y < s->map.y)
	{
		if (s->map.map[y][0] != ' ' && s->map.map[y][0] != '1')
		{
			printf("Error\nError zamk_map666\n");
			exit(0);
		}
		if (s->err.err_plr == -1)
		{
			printf("Error\nError zamk_map555\n");
			exit(0);
		}
	}
}
